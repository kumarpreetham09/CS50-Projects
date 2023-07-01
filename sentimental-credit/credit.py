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
    for i in input:
        i