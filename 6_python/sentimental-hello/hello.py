def main():
    print(hello())


def hello():
    name = input("What is your name?\n")
    return f"hello, {name}"


if __name__ == "__main__":
    main()
