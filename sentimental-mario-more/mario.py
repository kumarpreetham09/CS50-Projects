# TODO
from cs50 import get_int

while True:
    n = get_int("Enter height: ")
    if n > 0:
        break


for i in range(n+1):
    print(" "*(n-i) + "#"*i + " " + "#"*i )