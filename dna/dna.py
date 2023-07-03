import csv
import sys


def main():

    # TODO: Check for command-line usage
    n = len(sys.argv)
    if n != 3:
        print("Invalid number of arguments")
    else:
        database = sys.argv[1]
        text = sys.argv[2]

        # TODO: Read database file into a variable
        names = []
        result = []
        with open(database, 'r') as data_file:
            reader = csv.DictReader(data_file)
            aquired_keys = False
            keys = []
            for row in reader:
                names.append(row['name'])
                if not aquired_keys:
                    for key in row:
                        keys.append(key)
                        aquired_keys = True

            keys.remove(keys[0])

        # TODO: Read DNA sequence file into a variable
        with open(text , 'r') as text_file:
            sequence = text_file.read()


        # TODO: Find longest match of each STR in DNA sequence

        for sub in keys:
            integer = longest_match(sequence, sub)
            result.append(integer)

        # TODO: Check database for matching profiles
        with open(database, 'r') as data_file:

            reader = csv.DictReader(data_file)
            for i in range(len(result)):
                print(i)
                for row in reader:
                    if int(row[f"{keys[i]}"]) == int(result[i]):
                        print(f'{row[f"{keys[i]}"]} : {result[i]} : True')
                    else:
                        print(f'{row[f"{keys[i]}"]} : {result[i]} : False')
                        names.remove(row['name'])

            print(len(result))
            print(names)

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
