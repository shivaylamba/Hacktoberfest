import random

# Generate a random number between 1 and 100
secret_number = random.randint(1, 100)

# Initialize the number of guesses
guesses = 0

print("Welcome to the Number Guessing Game!")
print("I'm thinking of a number between 1 and 100.")

while True:
    # Ask the player to guess the number
    try:
        guess = int(input("Enter your guess: "))
        guesses += 1

        # Check if the guess is correct
        if guess == secret_number:
            print(f"Congratulations! You guessed the number {secret_number} correctly in {guesses} attempts.")
            break
        elif guess < secret_number:
            print("Try a higher number.")
        else:
            print("Try a lower number.")
    except ValueError:
        print("Invalid input. Please enter a valid number between 1 and 100.")

# End of the game
print("Thank you for playing!")
