import csv
import sys


def main():

    # Check for command-line usage
    check_command_line()

    # Read database file into a variable
    db = read_db()

    # Read DNA sequence file into a variable
    sequence = read_sequence()

    # Find longest match of each STR in DNA sequence
    result = length_longest_run(db, sequence)

    # Check database for matching profiles
    print(check_db(db, result))

    return


def check_command_line():
    while True:
        try:
            if len(sys.argv) < 3:
                sys.exit("Too few command-line arguments")
            elif len(sys.argv) > 3:
                sys.exit("Too many command-line arguments")
            elif not sys.argv[1].endswith(".csv"):
                sys.exit("Not a CSV file")
            elif not sys.argv[2].endswith(".txt"):
                sys.exit("Not a text file")
            else:
                break
        except FileNotFoundError:
            sys.exit("File does not exist")


def read_db():
    db = []
    with open(sys.argv[1], "r") as file:
        reader = csv.DictReader(file)
        for row in reader:
            db.append(row)
    return db


def read_sequence():
    with open(sys.argv[2], "r") as file:
        return file.read()


def length_longest_run(db, sequence):
    result = {}
    strs = list(db[0])
    strs.pop(0)
    for str in strs:
        longest_run = longest_match(sequence, str)
        result[str] = longest_run
    return result


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


def check_db(db, result):
    strs = list(result)
    for person in db:
        for str in strs:
            if int(person[str]) != result[str]:
                break
        else:
            return person["name"]
    return "No match"


main()
