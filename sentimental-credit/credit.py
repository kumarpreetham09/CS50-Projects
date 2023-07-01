# TODO
from cs50 import get_string, get_int



def main():
    is_valid = True
    while is_valid:
        input = get_string("Number: ")
        if len(str(input)) == 13 or len(str(input)) == 15 or len(str(input)) == 16:
            if algo(input) == True:
                is_valid = False
                print("AMEX")
            else:
                print("INVALID")


    if input[0] == 3 and len(input) == 15:
        if input[1] == 4 or input[1] == 7:
            print("AMEX")
    elif input[0] == 4 and len(input) == 13 or len(length) == 15:
        print("VISA")


def algo(i):
    input = i.split(", ")
    odd = 0
    even = 0
    length = len(input)
    for i in range(length):
        pos = (length - (i+1))
        if pos%2 == 0:
            input[pos] += odd
        else:
            buffer = input[pos] * 2
            print(buffer)
            # if int(buffer) > 10:
            #     buffer_sum = buffer[0] + buffer[1]

            #     buffer_sum += even

            # else:
            #     input[pos] += even
    sum = odd + even
    sum_length = len(sum)
    if sum[sum_length - 1] == 0:
        return True
    else:
        return False


main()