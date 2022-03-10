import csv
import sys


def main():

    # TODO: Check for command-line usage
    if len(sys.argv) != 3:
        sys.exit("Usage: python dna.py data.csv sequence.txt")

    # TODO: Read database file into a variable
    database = []
    with open(sys.argv[1], "r") as file1:
        reader = csv.DictReader(file1)
        for data in reader:
            database.append(data)

    # TODO: Read DNA sequence file into a variable
    with open(sys.argv[2], "r") as file2:
        sequence = file2.read()

    # TODO: Find longest match of each STR in DNA sequence
    strs = [k for k in database[0].keys()]
    strs = strs[1:]
    match = {}
    for i in strs:
        match[i] = longest_match(sequence, i)
    # print(f"strs:{strs}" )
    # print(f"match: {match}" )

    # TODO: Check database for matching profiles
    for person in database:
        # print(f"person: {person}"  )
        find_person = False
        # check if every str is match
        flag = 0
        for j in strs:
            # print(j,person[j], match[j])
            if int(person[j]) != match[j]:
                flag = -1
        # print(f"flag: {flag}")
        # if match, print name
        if flag == 0:
            print(person["name"])
            find_person = True
            break
        # else, print no match
    if find_person == False:
        print("No match")

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
