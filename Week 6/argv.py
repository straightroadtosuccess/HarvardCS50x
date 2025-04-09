from sys import argv

# if len(argv) == 2:
#     print(f"hello, {argv[1]}")
# else:
#     print("hello, world")

# for arg in argv:
for arg in argv[1:]:
    # if arg != "argv.py":
    print(arg)
