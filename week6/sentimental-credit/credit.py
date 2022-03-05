from cs50 import get_int

number = get_int("Number: ")

sum = 0
length = len(number)
for i in range(length-2, -1, -2):
    sum += i * 2