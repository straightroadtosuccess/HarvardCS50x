from cs50 import get_string

# Prompt the user for some text
text = get_string("Text: ")

# Count the number of letters, words, and sentences in the text


def count_letters(text):
    return sum(1 for char in text if char.isalpha())


def count_words(text):
    return len(text.split())


def count_sentences(text):
    return sum(1 for char in text if char in ".!?")


# Calculate letter, word, and sentence counts
amountLetters = count_letters(text)
amountWords = count_words(text)
amountSentences = count_sentences(text)

# Initialize variables for the index and divide into letters and sentences
L = (amountLetters / amountWords) * 100
S = (amountSentences / amountWords) * 100

# Coleman-Liau index
index = round(0.0588 * L - 0.296 * S - 15.8)

# Print the result of the information gathered
print(f"\nLetters: {amountLetters}")
print(f"Words: {amountWords}")
print(f"Sentences: {amountSentences}\n")

# Print the grade level
if index < 1:
    print("Before Grade 1")
elif index >= 16:
    print("Grade 16+")
else:
    print(f"Grade {index}")
