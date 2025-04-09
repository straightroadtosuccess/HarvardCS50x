from cs50 import get_string

# s = get_string("Do you agree? ")
s = get_string("Do you agree? ").lower()

# if s == "Y" or s == "y":
# if s in ["y", "Y", "yes", "Yes", "YES", "YeS", "YEs"]:
# if s.lower() in ["y", "yes"]:
if s in ["y", "yes"]:
    print("Agreed. ")
# elif s == "N" or s == "n"
# elif s in ["n", "no", "No", "NO", "nO"]:
# elif s.lower() in ["n", "no"]:
elif s in ["n", "no"]:
    print("Not agreed. ")
