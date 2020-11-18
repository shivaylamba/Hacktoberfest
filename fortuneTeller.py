import random
import time

eight_ball = [ "It is certain", "It is decidedly so", "Without a doubt", "Yes, definitely",
               "You may rely on it", "As I see it, yes", "Most Likely", "Outlook Good",
               "Yes", "Signs point to yes", "Reply hazy, try again", "Ask again later",
               "Better not tell you now", "Cannot predict now", "Concentrate and ask again",
               "Don't count on it", "My reply is no", "My sources say no", "Outlook not so good", "Very Doubtful"]

def question():
    question = input("You may ask your yes or no question of the Magic 8 Ball!\n")
    print("Thinking...")
    time.sleep(random.randrange(0,5))
    print(random.choice(eight_ball))

while True:
    question()
    repeat = input("Would you like to ask another question? (Y or N)")
    if not (repeat == "y" or repeat == "Y"):
        print("Come back if you have more questions!")
        break
