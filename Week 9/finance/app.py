import os
from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request, session
from flask_session import Session
from werkzeug.security import check_password_hash, generate_password_hash
from helpers import apology, login_required, lookup, usd

# Configure application
app = Flask(__name__)

# Custom filter
app.jinja_env.filters["usd"] = usd

# Configure session to use filesystem (instead of signed cookies)
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///finance.db")


@app.after_request
def after_request(response):
    """Ensure responses aren't cached"""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


@app.route("/")
@login_required
def index():
    """Show portfolio of stocks"""
    user_id = session["user_id"]

    # Current cash
    cash = db.execute("SELECT cash FROM users WHERE id = ?", user_id)[0]["cash"]

    # Stocks owned
    rows = db.execute(
        "SELECT symbol, SUM(shares) AS total FROM transactions WHERE user_id = ? GROUP BY symbol HAVING total > 0",
        user_id
    )

    stocks = []
    total_value = 0
    for row in rows:
        stock = lookup(row["symbol"])
        value = stock["price"] * row["total"]
        total_value += value
        stocks.append({
            "symbol": stock["symbol"],
            "shares": row["total"],
            "price": stock["price"],
            "total": value
        })

    grand_total = cash + total_value
    return render_template("index.html", stocks=stocks, cash=cash, grand_total=grand_total)


@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    """Buy shares of stock"""
    if request.method == "POST":
        symbol = request.form.get("symbol")
        shares = request.form.get("shares")

        if not symbol:
            return apology("must provide symbol", 400)
        if not shares or not shares.isdigit() or int(shares) <= 0:
            return apology("must provide positive integer shares", 400)

        stock = lookup(symbol)
        if not stock:
            return apology("invalid symbol", 400)

        user_id = session["user_id"]
        shares = int(shares)
        price = stock["price"]
        total_cost = shares * price

        # Check user cash
        cash = db.execute("SELECT cash FROM users WHERE id = ?", user_id)[0]["cash"]
        if total_cost > cash:
            return apology("can't afford", 400)

        # Deduct cash and insert transaction
        db.execute("UPDATE users SET cash = cash - ? WHERE id = ?", total_cost, user_id)
        db.execute(
            "INSERT INTO transactions (user_id, symbol, shares, price) VALUES (?, ?, ?, ?)",
            user_id, stock["symbol"], shares, price
        )

        return redirect("/")

    else:
        return render_template("buy.html")


@app.route("/history")
@login_required
def history():
    """Show history of transactions"""
    user_id = session["user_id"]
    transactions = db.execute(
        "SELECT symbol, shares, price, transacted FROM transactions WHERE user_id = ? ORDER BY transacted DESC",
        user_id
    )
    return render_template("history.html", transactions=transactions)


@app.route("/login", methods=["GET", "POST"])
def login():
    """Log user in"""
    # Forget any user_id
    session.clear()

    if request.method == "POST":
        username = request.form.get("username")
        password = request.form.get("password")

        # Check if username/password provided
        if not username:
            return apology("must provide username", 403)
        if not password:
            return apology("must provide password", 403)

        # Query database for user
        rows = db.execute("SELECT * FROM users WHERE username = ?", username)

        # Check if user exists
        if len(rows) != 1:
            return apology("invalid username", 403)

        # Check password against hash
        if not check_password_hash(rows[0]["hash"], password):
            return apology("invalid password", 403)

        # Log user in
        session["user_id"] = rows[0]["id"]
        return redirect("/")

    # GET request
    return render_template("login.html")


@app.route("/logout")
def logout():
    """Log user out"""
    session.clear()
    return redirect("/")


@app.route("/quote", methods=["GET", "POST"])
@login_required
def quote():
    """Get stock quote."""
    if request.method == "POST":
        symbol = request.form.get("symbol")
        if not symbol:
            return apology("must provide symbol", 400)

        stock = lookup(symbol)
        if not stock:
            return apology("invalid symbol", 400)

        return render_template("quoted.html", stock=stock)

    else:
        return render_template("quote.html")


@app.route("/register", methods=["GET", "POST"])
def register():
    """Register user"""
    if request.method == "POST":
        username = request.form.get("username")
        password = request.form.get("password")
        confirmation = request.form.get("confirmation")

        # Validate submission
        if not username:
            return apology("must provide username", 400)
        if not password or not confirmation:
            return apology("must provide password", 400)
        if password != confirmation:
            return apology("passwords do not match", 400)

        # Hash password
        hash_pw = generate_password_hash(password)

        # Try to insert new user
        try:
            new_user = db.execute(
                "INSERT INTO users (username, hash) VALUES (?, ?)",
                username, hash_pw
            )
        except:
            return apology("username already exists", 400)

        # Log in new user
        session["user_id"] = new_user
        return redirect("/")

    else:
        return render_template("register.html")


@app.route("/add_cash", methods=["GET", "POST"])
@login_required
def add_cash():
    if request.method == "POST":
        amount = request.form.get("amount")
        if not amount or float(amount) <= 0:
            return apology("must provide positive amount")
        amount = float(amount)
        db.execute("UPDATE users SET cash = cash + ? WHERE id = ?", amount, session["user_id"])
        flash(f"Added ${amount:.2f} to your account!")
        return redirect("/")
    else:
        return render_template("add_cash.html")


@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    """Sell shares of stock"""
    user_id = session["user_id"]
    # Get current owned stocks
    stocks = db.execute(
        "SELECT symbol, SUM(shares) AS total FROM transactions WHERE user_id = ? GROUP BY symbol HAVING total > 0",
        user_id
    )

    if request.method == "POST":
        symbol = request.form.get("symbol")
        shares = request.form.get("shares")

        if not symbol:
            return apology("must select stock", 400)
        if not shares or not shares.isdigit() or int(shares) <= 0:
            return apology("must provide positive integer shares", 400)

        shares = int(shares)
        # Check owned shares
        owned = db.execute(
            "SELECT SUM(shares) AS total FROM transactions WHERE user_id = ? AND symbol = ? GROUP BY symbol",
            user_id, symbol
        )
        if not owned or shares > owned[0]["total"]:
            return apology("not enough shares", 400)

        stock = lookup(symbol)
        total_value = shares * stock["price"]

        # Add cash and insert negative transaction
        db.execute("UPDATE users SET cash = cash + ? WHERE id = ?", total_value, user_id)
        db.execute(
            "INSERT INTO transactions (user_id, symbol, shares, price) VALUES (?, ?, ?, ?)",
            user_id, stock["symbol"], -shares, stock["price"]
        )

        return redirect("/")

    else:
        return render_template("sell.html", stocks=stocks)

