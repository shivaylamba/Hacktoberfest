# LANGUAGE: Python
# AUTHOR: Ayushi
# GITHUB: https://github.com/Kshawayushi28

import random

print("Welcome to Number Guessing Game!")
number = random.randint(1, 20)
attempts = 0

while True:
    guess = int(input("Guess a number between 1 and 20: "))
    attempts += 1
    if guess < number:
        print("Too low!")
    elif guess > number:
        print("Too high!")
    else:
        print(f"Congratulations! You guessed the number {number} in {attempts} attempts.")
        break
