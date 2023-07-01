# TODO
from cs50 import get_string, get_int


is_valid = True

while not is_valid:
    input = get_int("Number: ")
    if len(input) == 13 or len(input) == 16 and algo(input):
        is_valid = True
    else:
        print("INVALID")


def algo(input):
    odd = 0
    even = 0
    length = len(input)
    for i in range(length):
        pos = (length - (i+1))
        if pos%2 == 0:
            input[pos] += odd
        else:
            buffer = input[pos] * 2
            if buffer >= 10:
                buffer[0] + buffer[1] + even = even
            else:
                input[pos] += even
    sum = odd + even
    sum_length = len(sum)

