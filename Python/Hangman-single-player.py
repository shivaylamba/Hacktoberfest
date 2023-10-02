# Hangman Game - Explanation
# ========================
# Hangman is a word-guessing game where the player tries to guess a secret word one letter at a time.
# The player has a limited number of attempts to guess the word correctly.
# If the player guesses all the letters of the word before running out of attempts, they win.
# If they run out of attempts before guessing the word, they lose.

# How to Play:
# ------------
# 1. Choose a Theme:
#    - Start by choosing a theme for the secret word (e.g., Animals, Fruits, Countries).
# 2. Set the Number of Attempts:
#    - Specify the number of attempts you want (between 3 and 10).
# 3. Begin the Round:
#    - You'll see a word description related to the chosen theme.
#    - Blank spaces represent the letters of the word.
# 4. Make Guesses:
#    - Guess letters one at a time by typing them.
#    - For a hint, type 'hint', but use it wisely as it deducts from your score.
#    - Continue guessing until you guess the word or run out of attempts.
# 5. Win or Lose:
#    - If you guess all the letters correctly, you win.
#    - If you run out of attempts, you lose, and the secret word is revealed.
# 6. Keep Track of Your Score:
#    - Your score is based on the number of letters you correctly guess in each round.
# 7. Play Again:
#    - After each round, choose to play another round with the same theme or exit the game.
#    - You can also see the scorecard to track your overall progress.

import random

word_categories = {
    "Animals": [("cat", "a furry mammal with whiskers"), 
                ("dog", "a loyal companion with four legs"), 
                ("elephant", "a large, gray creature with a trunk"), 
                ("giraffe", "a tall animal with a long neck and spots"), 
                ("kangaroo", "a marsupial that hops on two legs"), 
                ("lion", "the king of the jungle"), 
                ("tiger", "a fierce big cat with stripes"),
                ("penguin", "a bird that cannot fly and lives in the Antarctic"),
                ("dolphin", "a highly intelligent marine mammal"),
                ("rhinoceros", "a large herbivorous mammal with a horn on its nose"),
                ("cheetah", "the fastest land animal on Earth"),
                ("koala", "a marsupial native to Australia with a diet of eucalyptus leaves"),
                ("gazelle", "a slender, graceful antelope known for its speed"),
                ("panda", "a bear native to China known for its black and white fur"),
                ("octopus", "a sea creature with eight arms and a soft body"),
                ("elephant", "a majestic creature often associated with wisdom")],

    "Fruits": [("apple", "a red or green fruit with a core"), 
               ("banana", "a yellow fruit with a curved shape"), 
               ("orange", "a citrus fruit with a bright color"), 
               ("grape", "a small, round fruit often in clusters"), 
               ("kiwi", "a small, brown fruit with green flesh"), 
               ("mango", "a sweet tropical fruit"), 
               ("pear", "a juicy fruit with a narrow top and wider bottom"),
               ("strawberry", "a small, red, and sweet fruit"),
               ("pineapple", "a tropical fruit with a spiky outer skin"),
               ("watermelon", "a large, juicy fruit with green skin and red flesh"),
               ("blueberry", "a small, round, and blue fruit"),
               ("cherry", "a small, red or black fruit often used in desserts"),
               ("avocado", "a creamy fruit used in salads and spreads"),
               ("peach", "a juicy, sweet fruit with a fuzzy skin"),
               ("grapefruit", "a citrus fruit known for its tangy flavor")],

    "Countries": [("france", "a European country known for its culture"), 
                  ("canada", "a North American country with maple leaves"), 
                  ("japan", "an Asian country with cherry blossoms"), 
                  ("brazil", "a South American country famous for Carnival"), 
                  ("egypt", "an African country with pyramids"), 
                  ("china", "an Asian country with the Great Wall"), 
                  ("india", "a South Asian country with diverse culture"),
                  ("australia", "a continent and country known for unique wildlife"),
                  ("germany", "a European country famous for its engineering and beer"),
                  ("southafrica", "a country with diverse landscapes and wildlife"),
                  ("russia", "the largest country in the world known for its vastness"),
                  ("italy", "a European country known for its cuisine and art"),
                  ("mexico", "a North American country famous for its cuisine and culture"),
                  ("argentina", "a South American country known for tango and beef"),
                  ("canada", "the second-largest country in the world by land area")]
}



# Function to choose a random word from a given category.
def choose_word(theme):
    return random.choice(word_categories.get(theme, []))

# Function to display the current state of the word with guessed letters.
def display_word(word, guessed_letters):
    display = ""
    for letter in word:
        if letter in guessed_letters:
            display += letter
        else:
            display += "_"
        display += " "
    return display

# Function to display the hangman based on the number of incorrect attempts.
def display_hangman(attempts):
    hangman_art = [
        "  _________",
        " |/      |",
        " |      (_)",
        " |      /|\\",
        " |      / \\",
        " |",
        "_|___"
    ]
    for line in hangman_art[:6-attempts]:
        print(line)

# Function to provide a hint for the word.
def hint(word, guessed_letters):
    not_guessed = [letter for letter in word if letter not in guessed_letters]
    return random.choice(not_guessed)

# Main game function.
def hangman():
    total_rounds = 0
    total_score = 0
    print("Welcome to Hangman!")

    while True:
        print("\n" + "=" * 40)
        theme = input("Choose a theme (Animals, Fruits, Countries): ").title()
        if theme not in word_categories:
            print("Invalid theme. Please choose from Animals, Fruits, or Countries.")
            continue
        
        word, word_description = choose_word(theme)
        attempts = int(input("Enter the number of attempts (3-10): "))
        guessed_letters = []
        score = len(word)
        round_num = total_rounds + 1

        print("\nNew round!")
        print(f"Word Description: {word_description}")
        print(display_word(word, guessed_letters))

        while attempts > 0:
            print("-" * 40)
            guess = input("Guess a letter or type 'hint' for a hint: ").lower()

            if guess == 'hint':
                if len(guessed_letters) == len(word) - 1:
                    print("Sorry, you've already guessed most of the word.")
                else:
                    hint_letter = hint(word, guessed_letters)
                    print(f"Hint: The word has the letter '{hint_letter}'.")
                    score = score-1
                continue

            if len(guess) != 1 or not guess.isalpha():
                print("Please enter a single letter.")
                continue

            if guess in guessed_letters:
                print("You already guessed that letter.")
                continue

            guessed_letters.append(guess)

            if guess in word:
                print("Correct guess!")
            else:
                attempts -= 1
                print(f"Wrong guess! You have {attempts} attempts left.")
                display_hangman(attempts)

            display = display_word(word, guessed_letters)
            print(display)

            if "_" not in display:
                print("Congratulations! You guessed the word.")
                total_score += score
                break

        if "_" in display:
            print(f"Sorry, you're out of attempts. The word was '{word}'.")
        
        print("-" * 40)
        print(f"Round: {round_num}")
        print(f"Your score for this round: {score}")
        print(f"Total score: {total_score}")
        
        total_rounds += 1
        play_again = input("Do you want to play another round with the same theme? (yes/no): ")
        if play_again.lower() != "yes":
            show_scorecard = input("Do you want to see the scorecard? (yes/no): ")
            if show_scorecard.lower() == "yes":
                print("\nScorecard:")
                print(f"Total rounds played: {total_rounds}")
                print(f"Total score: {total_score}")
            print("\nThank you for playing!")
            break

if __name__ == "__main__":
    hangman()