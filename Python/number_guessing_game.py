import random 
def number_guessing_game():
    print("Welcome to the number Guessing Game")
    number_to_guess = random.randint(1,100)
    attempts = 0
    while True:
        user_guess = int(input("Guess a number between 1 and 100: "))
        attempts+=1
        if user_guess<number_to_guess:
            print("Too low! Try again.")
        elif user_guess>number_to_guess:
            print("Too high! Try agian.")
        else:
            print(f"Congratulations! You've guessed the number in {attempts} attempts.")
            break

if __name__ == "__main__":
    number_guessing_game()
