# from sys import argv, exit
import sys

# if len(argv) != 2:
if len(sys.argv) != 2:
    print("Missing command-line argument")
#     exit(1)
    sys.exit(1)

# print(f"hello, {argv[1]}")
print(f"hello, {sys.argv[1]}")
# exit(0)
sys.exit(0)
