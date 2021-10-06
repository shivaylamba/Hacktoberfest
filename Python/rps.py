#Rock, paper, scissors

from random import randint

#list of playing options
play_options = ['rock', 'paper', 'scissors']

#random play to computer
computer = play_options[randint(0,2)]

while True:
    player = input('Enter your move: rock, paper, or scissors: ')
    player = player.lower()

    if player not in play_options:
        while True:
            print('Please enter a valid move.')
            player = input('Enter your move: rock, paper, or scissors: ').lower()
            if player in play_options:
                break

    if player == computer:
        print('It\'s a tie!')

    elif player == 'rock':
        if computer == 'scissors':
            print('You win! Rock smashes Scissors!')
        else:
            print('You lose, Paper covers Rock.')
    elif player == 'paper':
        if computer == 'scissors':
            print('You lose. Scissors cut Paper.')
        else:
            print('You win! Rock smashes Scissors')
    elif player == 'scissors':
        if computer == 'rock':
            print('You lose. Rock smashes Scissors.')
        else:
            print('You win! Scissors cut Paper')

    next_round = input('Do you want to play another round? Y/N:').upper()
    if next_round == 'N':
        break