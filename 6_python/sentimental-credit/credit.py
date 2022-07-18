# Determine whether a provided credit card number is valid according to Luhn’s algorithm
import re


def main():
    print(validation(get_number()))


def get_number():
    # prompt user for valid format of number
    while True:
        if matches := re.search(r"^\d+$", input("Number: ")):
            return matches.group(0)
        else:
            pass


def validation(num):
    if luhn_algo(num):
        return card_brand(num)
    else:
        return "INVALID"


def luhn_algo(num):
    # pass number into Luhn's algorithm
    total = 0
    for i in range(len(num)):
        digit = int(num[len(num) - (i + 1)])

        if (i % 2 != 0):
            digit *= 2

            if digit > 9:
                sum_of_digits = 0
                for j in str(digit):
                    sum_of_digits += int(j)
                digit = sum_of_digits

        total += digit

    return True if total % 10 == 0 else False


def card_brand(num):
    # determine brand of card
    if len(num) == 15 and re.match(r"3[47]", num):
        return "AMEX"
    elif len(num) == 16 and re.match(r"5[1-5]", num):
        return "MASTERCARD"
    elif (len(num) == 13 or len(num) == 16) and re.match(r"4", num):
        return "VISA"
    else:
        "INVALID"


if __name__ == "__main__":
    main()
