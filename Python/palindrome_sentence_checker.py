#palindrome_sentence_checker.py
#unique Palindrome checker that ignores spaces, punctuation, and case.

import re

def is_palindrome_sentence(s: str) -> bool:
    # Remove punctuation and spaces
    cleaned = re.sub(r'[^A-Za-z0-9]', '', s).lower()
    return cleaned == cleaned[::-1]

if __name__ == "__main__":
    sentence = input("Enter a sentence: ")
    if is_palindrome_sentence(sentence):
        print("✅ It's a palindrome sentence!")
    else:
        print("❌ Not a palindrome sentence.")
