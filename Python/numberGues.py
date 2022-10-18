import random


def numberGuess():
    number=random.randrange(1,100)
    chances=0
    while chances<5:
        yourNum=int(input("ENTER ANY NUMBER B/W 1 AND 100:"))
        if yourNum==number:
            print("HURRAY!, YOU HAVE WON THE GAME")
            break
        elif yourNum<number:
            print("YOUR NUMBER IS LESSER THAN THE SELECTED NUMBER:")
        elif yourNum>number:
            print("YOUR NUMBER IS HIGHER THAN THE SELECTED NUMBER:")
           
        chances=chances+1
    if not chances<5:
         print("Your chances are over.NUMBER IS:",format(number))
    
numberGuess()
interest=input("do you want to play again:y/n:")
while interest=="y" or interest=="Y":
    numberGuess()
    interest=input("do you want to play again:y/n")


print("THANKS FOR PLAYING")

    

