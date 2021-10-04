# rock, paper and scissors.
import random
computer_win = 0
your_win = 0
tie = 0
total_matches_played = 0
def game(comp, you):
    if comp==you:
        return("tie")
    elif comp == "r":
        if you == "p":
            return("you")
        elif you == "s":
            return("comp")
    elif comp == "p":
        if you == "r":
            return("comp")
        elif you == "s":
            return("you")
    elif comp == "s":
        if you == "r":
            return("you")
        elif you == "p":
            return("comp")
    
def turn():
    global total_matches_played
    global computer_win
    global your_win
    global tie
    total_matches_played += 1
    print("computer turn:-\n rock(r), paper(p) & scissors(s)")
    num = random.randint(1, 3)
    if num == 1:
        comp = 'r'
    elif num == 2:
        comp = 'p'
    elif num == 3:
        comp = 's'
    print("Your turn:-\n rock(r), paper(p) & scissors(s)")
    you = input()

    if you == "r" or you == "p" or you == "s":
        win = game(comp, you)

    else:
        print("Plaese make right choice")
        decsion()

    if win == "comp":
        computer_win += 1
        print(f"The computer won {computer_win} times")
    elif win == "you":
        your_win += 1
        print(f" you won {your_win} times")
    elif win == "tie":
        tie += 1
        print(f"The tie occurred {tie} times")
    decsion()

def decsion():
    k = input("Want to play another match press :- n or want to quit press :- q\n")
    if k == "n":
        turn()
    if k == "q":
        print(total_matches_played)
        exit()

turn()
# game code ends
