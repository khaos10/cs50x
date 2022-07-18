# Calculate the minimum number of coins required to give a user change
import math

# Declare coins: quarter, dime, nickel, penny
Q = 0.25
D = 0.10
N = 0.05
P = 0.01


def main():
    print(num_coins(get_amount()))


def get_amount():
    # Prompt user for amount of change
    while True:
        try:
            amount = float(input("Change owed: "))
            if 0 <= amount:
                return amount
        except ValueError:
            pass


def num_coins(amount):
    # Calculate total number of coins
    amount, num_q = count_coins(amount, Q)
    amount, num_d = count_coins(amount, D)
    amount, num_n = count_coins(amount, N)
    amount, num_p = count_coins(amount, P)

    return num_q + num_d + num_n + num_p


def count_coins(amount, coin):
    # Count number of given type of coins contained in given amount
    count = math.floor(amount / coin)
    amount -= (coin * count)
    return round(amount, 10), count


if __name__ == "__main__":
    main()
