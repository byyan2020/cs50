from cs50 import get_int

number = get_int("Number: ")

sum = 0
length = len(number)
for i in range(length-2, -1, -2):
    sum += i * 2
for j in range(length - 1, -1, -2):
    sum += i

if sum % 10 != 0:
    print("INVALID")
else:
    if length == 15:
        print("American Express")
    elif 
