# TODO
import re


def main():
    text = input("Text: ")
    grade = formula(text)
    if grade < 1:
        print("Before Grade 1")
    elif grade >= 16:
        print("Grade 16+")
    else:
        print(f"Grade {grade}")


def formula(text):
    words = len(text.split(" "))
    sentences = len(re.split(r"[.!?]", text)) - 1
    letters = 0
    for i in text:
        if i.isalpha():
            letters += 1

    L = (letters / words) * 100
    S = (sentences / words) * 100
    index = round(0.0588 * L - 0.296 * S - 15.8)
    return index


main()
