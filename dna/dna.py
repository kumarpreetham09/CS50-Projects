import csv
import sys
import numpy as np


def main():

    # TODO: Check for command-line usage
    n = len(sys.argv)
    if n != 3:
        print("Invalid number of arguments")
    else:
        database = sys.argv[1]
        text = sys.argv[2]

        # TODO: Read database file into a variable
        result = []
        with open(database, 'r') as data_file:
            reader = csv.DictReader(data_file)
            buffer = []
            keys = []
            i = 0
            for row in reader:
                for key in row:
                    if i == len(row) - 1:
                        buffer.append(row[f'{key}'])
                        keys.append(buffer)
                        i = 0
                        buffer = []

                    else:
                        buffer.append(row[f'{key}'])
                        i += 1
            print(keys)

        # TODO: Read DNA sequence file into a variable
        with open(text , 'r') as text_file:
            sequence = text_file.read()


        # TODO: Find longest match of each STR in DNA sequence
            for i in len(keys)

        for sub in keys:
            integer = longest_match(sequence, sub)
            result.append(integer)

        # TODO: Check database for matching profiles

            # if len(names) == 1:
            #     print(names)
            #     print(result)

            # elif len(names) == 0:
            #     print("No match")

            # else:
            #     print("error")
            #     print(names)
            #     print(result)


        return


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


main()
