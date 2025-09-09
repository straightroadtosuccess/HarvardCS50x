from datetime import datetime
import json


# Goal class
class Goal:
    def __init__(self, name, current, target=100):
        # Store goal, name and current progress
        self.name = name
        self.current = current
        self.target = target
        # Intialize logs list, enter progress at today's date
        self.logs = [{"date": datetime.today().strftime("%Y-%m-%d"), "amount": current}]


    # Add new progress to existing goal
    def add_progress(self, amount, date_str):
        try:
            # Convert string date to datetime object
            date = datetime.strptime(date_str, "%Y-%m-%d")
        except ValueError:
            # If date format is wrong, show error and exit
            print("Invalid date format. Use YYYY-MM-DD. \n")
            return
        # Update current progress
        self.current = amount
        # Append new progress log to the logs list
        self.logs.append({"date": date_str, "amount": amount})
        # Print messages to user
        print(f"Progress added for {self.name}: {amount}")
        print(f"Progress added for {self.name}: {amount}/{self.target}")


    # Create ASCII progress bar
    def progress_bar(self, width=20):
        """Return a simple ASCII progress bar based on current progress"""
        # Calculate progress percentage
        percent = self.progress_percent()
        # Calculate number of filled segments
        filled = int(width * percent / 100)
        # Combine filled and empty segments
        bar = "█" * filled + "-" * (width - filled)
        return f"[{bar}] {percent:.1f}%"


    # Calculate progress as a percentage
    def progress_percent(self):
        # Return the current progress as % of target
        return min(100, (self.current / self.target) * 100)


    # Display all progress logs with ASCII bars
    def show_logs(self):
        print(f"\nProgress logs for {self.name}:")
        for log in self.logs:
            # Calculate % for each log entry
            percent = (log["amount"] / self.target) * 100
            filled = int(20 * percent / 100)
            bar = "█" * filled + "-" * (20 - filled)
            # Print date, amount, progress bar and percentage
            print(f"{log['date']}: {log['amount']} [{bar}] ({percent:.1f}%)")
        # Also show current progress with full bar
        print(f"Current progress: {self.current}/{self.target} {self.progress_bar()}")


    # Calculate momentum (average increase between logs)
    def show_momentum(self):
        """Simple momentum calculation: average % increase per log"""
        # Need at least to logs to calculate
        if len(self.logs) < 2:
            print("Not enough logs to calculate momentum")
            return
        total_increase = 0
        # Loop through logs starting from second entry
        for i in range(1, len(self.logs)):
            prev = self.logs[i-1]["amount"]
            curr = self.logs[i]["amount"]
            increase = curr - prev
            total_increase += increase
        # Average increase per log
        avg_increase = total_increase / (len(self.logs) - 1)
        # Print momentum message
        print(f"Average increase per entry: {avg_increase:.1f} units ({(avg_increase/self.target)*100:.1f}%)")


# Save goals to JSON file
def save_goals(goals, filename="goals.json"):
    data = []
    for g in goals:
        # Convert each goal object into dictionary for JSON
        data.append({
            "name": g.name,
            "current": g.current,
            "target": g.target,
            "logs": g.logs,
        })
    # Write JSON file
    with open(filename, "w") as f:
        json.dump(data, f, indent=4)


# Load goals from JSON
def load_goals(filename="goals.json"):
    goals = []
    try:
        with open(filename, "r") as f:
            data = json.load(f)
            for item in data:
                # Recreate Goal objects from loaded data
                g = Goal(item["name"], item["current"], item["target"])
                g.logs = item["logs"]
                goals.append(g)
    except FileNotFoundError:
        # If file doesn't exist, return empty list
        pass
    except json.JSONDecodeError:
        # If file is empty or corrupted
        print("\nWarning: goals file is empty or corrupted. Starting fresh.")
    return goals


# Main program
def main():
    # Load goals from file at start
    goals = load_goals()

    while True:
        # Show menu options
        print("\n---GOAL PROGRESS TRACKER---\n")
        print("1. Add new goal")
        print("2. Log progress")
        print("3. Show goal progress")
        print("4. Show momentum")
        print("5. Remove a goal")
        print("6. Save & Exit")
        choice = input("\nChoose an option: ")

        if choice == "1":
            # Input new goal name and current progress
            name = input("Goal name: ")
            current_input = input("Current amount percentage: ").strip()
            # Strip % if user included it
            if current_input.endswith('%'):
                current_input = current_input[:-1]
            current = float(current_input)

            # Check if goal exists
            existing_goal = None
            for g in goals:
                if g.name == name:
                    existing_goal =g
                    break

            if existing_goal:
                # If goal exists, add new progress
                existing_goal.add_progress(current, datetime.today().strftime("%Y-%m-%d"))
                print(f"Update existing goal '{name}' with new progress.")
                # Save immediately
                save_goals(goals)
            else:
                # If new goal, create and add to list
                goals.append(Goal(name, current, 100))
                print(f"\nGoal '{name}' added.")
                # Save immediately
                save_goals(goals)

        elif choice == "2":
            # Log progress for an existing goal
            if not goals:
                print("No goals yet. ")
                continue
            # Display numbered list of goals
            for i, g in enumerate(goals):
                print(f"{i+1}. {g.name}")
            idx = int(input("Select goal number: ")) - 1
            if 0 <= idx < len(goals):
                amount = float(input("New current amount: "))
                date_str = input("Date (YYYY-MM-DD): ")
                goals[idx].add_progress(amount, date_str)
            else:
                print("\nInvalid selection. ")

        elif choice == "3":
            # Show logs for all goals
            if not goals:
                print("\nNo goals yet. ")
                continue
            for g in goals:
                g.show_logs()

        elif choice == "4":
            # Show momentum for all goals
            if not goals:
                print("No goals yet. ")
                continue
            for g in goals:
                print(f"\nMomentum for {g.name}:")
                g.show_momentum()

        elif choice == "5":
            # Remove a goal
            if not goals:
                print("No goals to remove.")
                continue
            for i, g in enumerate(goals):
                print(f"{i+1}. {g.name}")
            try:
                idx = int(input("Select goal number to remove: ")) - 1
            except ValueError:
                print("Invalid input. Enter a number.")
                continue
            if 0 <= idx < len(goals):
                removed = goals.pop(idx)
                save_goals(goals)
                print(f"Goal '{removed.name}' has been removed.")
            else:
                print("Invalid selection.")


        elif choice == "6":
            # Save all goals and exit program
            save_goals(goals)
            print("\nBye, have a beautiful time!\n")
            break

        else:
            # Message for invalid input
            print("Invalid choice, try again. ")


if __name__ == "__main__":
    main()
