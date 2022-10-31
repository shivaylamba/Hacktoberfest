import random

while True:
    user_action = input("Enter a choice (rock, paper, scissors: ")
    possible_actions = ["rock", "paper", "scissors"]
    computer_action = random.choice(possible_actions)
    print(f"\n You chose {user_action}, the computer chose {computer_action}.\n")

    if user_action == computer_action:
        print(f"Both payers selected {computer_action}. It's a tie!")
    elif user_action == "rock":
        if computer_action == "paper":
            print("Paper covers rock. You lose!")
        else:
            print("Rock smashes scissors. You win!")
    elif user_action == "paper":
        if computer_action == "rock":
            print("Paper covers rock. You win!")
        else:
            print("Scissors cuts paper. You lose!")
    elif user_action == "scissors":
        if computer_action == "rock":
            print("Rock smashes scissors. You lose!")
        else:
            print("Scissors cuts paper. You win!")
    
    play_again = input("Play again? (yes/no): ")
    if play_again.lower() != "y":
        break
