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
    alpha = "abcdefghck
    for i in text:
        if i in

def count_words(text):
    return

def count_sentence(text):
    return

if __name__ == __main__:
    main()
