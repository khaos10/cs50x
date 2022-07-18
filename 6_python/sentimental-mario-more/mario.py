# Print out a double half-pyramid of a specified height

def main():
    height = get_int()
    for i in range(height):
        block = i + 1
        space = height - block
        print(" " * space, "#" * block, " " * 2, "#" * block, sep="")


def get_int():
    while True:
        try:
            height = int(input("Height: "))
            if 0 < height <= 8:
                return height
        except ValueError:
            pass


if __name__ == "__main__":
    main()
