from cs50 import get_int
# import cs50

# x = get_int("x: ")
# y = get_int("y: ")
# x = cs50.get_int("x: ")
# y = cs50.get_int("y: ")
# x = int(input("x: "))
# y = int(input("y: "))
# try:
#     x = int(input("x: "))
# except:
#     print("That is not an int!")
#     exit()
# try:
#     y = int(input("y: "))
# except:
#     print("That is not an int!")
#     exit()
# print(x + y)

x = get_int("x: ")
y = get_int("y: ")

z = x / y
# print(z)
print(f"{z:.50f}")
