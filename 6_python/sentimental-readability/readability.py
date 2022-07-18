# Compute the approximate grade level needed to comprehend some text

def main():
    print(grade(get_text()))


def get_text():
    while True:
        txt = input("Text: ")
        if txt:
            return txt
        else:
            pass


def grade(txt):
    num_letters = count_letters(txt)
    num_words = count_words(txt)
    num_sentences = count_sentences(txt)

    l = avg_per_100_words(num_letters, num_words)
    s = avg_per_100_words(num_sentences, num_words)

    # compute Coleman-Liau index
    grade = 0.0588 * l - 0.296 * s - 15.8

    if grade >= 16:
        return "Grade 16+"
    elif grade < 1:
        return "Before Grade 1"
    else:
        return f"Grade {round(grade)}"


def count_letters(txt):
    count = 0
    for i in txt:
        if i.isalpha():
            count += 1
    return count


def count_words(txt):
    count = 0
    for i in txt:
        if i.isspace():
            count += 1
    return count + 1


def count_sentences(txt):
    count = 0
    for i in txt:
        if i == "." or i == "!" or i == "?":
            count += 1
    return count


def avg_per_100_words(elements, words):
    return elements / words * 100


if __name__ == "__main__":
    main()
