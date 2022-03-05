from cs50 import get_int

number = str(get_int("Number: "))

sum = 0
length = len(number)
for i in range(length-2, -1, -2):
    # print(i, int(number[i]))
    for n in str(int(number[i]) * 2):
        sum += int(n)
# print(sum)
for j in range(length-1, -1, -2):
    # print(j, int(number[j]))
    sum += int(number[j])
# print(sum)

print(sum)
if sum % 10 != 0:
    print("INVALID")
else:
    if length == 15:
        print("AMEX")
    elif number[0] == "4":
        print("VISA")
    else:
        print("MASTERCARD")
