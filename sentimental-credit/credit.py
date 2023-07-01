# TODO
from cs50 import get_string, get_int


def main():
    num = input("Type:")
    length = len(num)
    if length == 13 or length == 15 or length == 16:
        if algo(num) == 0:
            return num
        else:
            print("INVALID")

    else:
        print("INVALID")


def algo(num):
    def digits_of(n):
        return[int(d) for d in str(n)]
    digits = digits_of(num)
    odd = 0
    even = 0
    pos = 1
    for i in digits[-1::-1]:
        pos += 1
        if pos%2 == 0:
            even += i
        else:
            buffer = i * 2
            digits2 = digits_of(buffer)
            for j in digits2:
                odd += j
    sum = odd + even
    if sum%10 == 0:
        return 0
    else:
        return 1

def print_func(num):
    length = len(num)
    print(num[0])
    print(length)
    if (num[0] == 3) and (length == 15):
        print("hello")
        if (num[1] == 4) or (num[1] == 7):
            print("AMEX")
        else:
            print("INVALID")
    elif num[0] == 4 and (length == 13 or length == 16):
        print("VISA")
    else:
        print("MASTERCARD")

print_func(main())