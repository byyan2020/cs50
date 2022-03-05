from cs50 import get_string

def main():
    text = get_string("Text: ")
    letters = count_letters(text)
    words = count_words(text)
    sentence = count_sentences(text)
    L = letters / words * 100
    S = sentences / words * 100
    index = round(0.0588 * L - 0.296 * S - 15.8)

    if index > 16:
        print("Grade 16+")
    elif index < 1:
        print("Before Grade 1")
    else:
        print(f"Grade {index}")

def count_letters(text):
    alpha = "abcdefghijklmnopqrstuvwxyz"
    count = 0
    for i in text:
        if i in alpha or alpha.upper():
            count += 1
    return count

def count_words(text):
    count = 0
    for i in text:
        if i == " ":
            count += 1
    return count

def count_sentence(text):
    count = 0
    for i in text:
        if i == "." or "!" or "?":
            count += 1
    return count

if "__name__" == "__main__":
    main()
