from os import system
from random import randint

gametitle = "Castle Dungeons- An interactive story game"

system("mode 110,30")
system("Title"+gametitle)


def cls():
    system("cls")


character_name = None
character_class = None
character_race = None
character_strength = None
character_magic = None
character_dexterity = None
character_life = None

cls()
print("Castle Dungeons- An interactive story fiction game in python")


def intro():
    print("")
    print("In this story, you are the hero")
    print("")
    print("Your main goal is to protect and save your fellow friends from the evil socerer's prison")
    print("")
    print("Your princess is also held captive in his castle.")
    print("")
    print("Defeat the socerer and win your princess back to be the most powerful being in this mystic universe")
    print("")
    print("Your choices, skills and your luck will determine the outcome of the game")
    print("")
    print("So buckle up and get ready to fight for your life")
    print("")
    input("Press Enter to Start...")


intro()


def create_character():
    cls()
    global character_name
    character_name = input("""
                           Lets begin the game by making your character,
                           What's the name of your hero?
                           
                           >""")
    global character_race
    while character_race is None:
        race_choice = input("""
                           Choose a race for your character:
                           1. Human
                           2. Elf
                           >""")
        if race_choice == "1":
            character_race = "Human"
        elif race_choice == "2":
            character_race = "Elf"
        else:
            print("Not a valid choice, please try again.")

    cls()
    global character_class
    while character_class is None:
        class_choice = input("""
                            Excellent choice.
                            You are """+character_race + """
                            Now Time for you to choose your class:
                            1. Warrior
                            2. Magician
                            >""")
        if class_choice == "1":
            character_class = "Warrior"
        elif class_choice == "2":
            character_class = "Magician"
        else:
            print("Invalid Input, Please enter a Valid input")


create_character()


def create_character_skill_sheet():
    global character_name, character_race, character_class, character_dexterity, character_magic, character_life, character_strength
    print("""
          Now let's determine your chatacter's skills, which you will use throughout the game.
          In this game, your character has four skills:
          
          -Strength, which you will use in a combat
          -Magic, which will help you cast spells
          -Dexterity, which you will use in a ability test
          -Life, which determines your life energy, points will be lost when hurt
          and when the life becomes 0, the character dies.
          
          Depending upon your Race and Class,
          you will have a certain point base already calculated automically.
          
          You will shortly be able to increase your skill points by rolling a 6-faced Dice.
          
          Here is your base character skill sheet:""")
    character_strength = 5
    character_magic = 0
    character_dexterity = 3
    character_life = 10

    if character_race == "Human":
        character_strength = character_strength+3
        character_magic = character_magic+1
        character_dexterity = character_dexterity+5
        character_life = character_life+5
    elif character_race == "Dwarf":
        character_strength = character_strength+1
        character_magic = character_magic+5
        character_dexterity = character_dexterity+3
        character_life = character_life+7
    if character_class == "Warrior":
        character_strength = character_strength+10
        character_magic = character_magic+5
        character_life = character_life+10
        character_dexterity = character_dexterity+5
    elif character_class == "Magician":
        character_strength = character_strength+5
        character_magic = character_magic+10
        character_life = character_life+5
        character_dexterity = character_dexterity+10
    print("Name: "+character_name)
    print("Race: "+character_race)
    print("Class: "+character_class)
    print("Strength: "+str(character_strength))
    print("Magic: "+str(character_magic))
    print("Dexterity: "+str(character_dexterity))
    print("Life "+str(character_life))
    input("Press enter")


create_character_skill_sheet()


def modify_skills():
    cls()
    global character_dexterity, character_strength, character_life
    print("""To modify your skills, roll a 6-faced dice to determine the modified skill.
          This is purely based on your luck
          Let's see how lucky you are ;)""")
    input("Press enter to roll for strength")
    roll = randint(1, 6)
    print("you rolled: "+str(roll))
    character_strength = character_strength+roll
    input("Press enter to roll for dexterity")
    roll = randint(1, 6)
    print("you rolled: "+str(roll))
    character_dexterity = character_dexterity+roll
    input("Press enter to roll for Life")
    roll = randint(1, 6)
    print("you rolled: "+str(roll))
    character_life = character_life+roll
    input("Press enter to continue...")
    cls()
    print("Your updated skill sheet is:")
    print("Name: "+character_name)
    print("Race: "+character_race)
    print("Class: "+character_class)
    print("Strength: "+str(character_strength))
    print("Magic: "+str(character_magic))
    print("Dexterity: "+str(character_dexterity))
    print("Life "+str(character_life))
    print()
    input("Press Enter to enter your adventure...")


modify_skills()


def scene_1():
    cls()
    choice = None
    while choice is None:
        user_input = input("""
                    You have entered the castle.
                    It is dark but thankfully your torch is lit and you can see upto 20ft from you.
                    The stone walls are damp and the smell of rats and orc is strong.
                    you walk down a narrow corridor, untill you reach a thick stone wall.
                    
                    The corridor continues on the left and on right.
                    
                    Its your choice now:
                    1. Turn Left
                    2. Turn Right
                    """)
        if user_input == "1" or user_input == "turn left":
            choice = "1"
            scene_2()
        elif user_input == "2" or user_input == "turn right":
            choice = "2"
            scene_3()
        else:
            print("""
                  Not a valid choice, enter a number or enter
                   "turn left" or "turn right" to continue... """)


def scene_2():
    cls()
    choice = None
    while choice is None:
        user_input = input("""
                           From the darkness behind you, you hear a strange noise...
                           
                           What will you do?
                           1. Continue walking
                           2. Stop to listen
                           >""")
        if user_input == "1" or user_input == "continue":
            choice = "1"
            combat()
        elif user_input == "2" or user_input == "stop":
            choice = "2"
            skill_check()
        else:
            print("""Not a valid choice, please enter a number or enter
                  "continue" or "stop" """)


def scene_3():
    cls()
    choice = None
    while choice is None:
        user_input = input("""
                           From the darkness ahead of you, you hear a strange noise...
                           
                           What will you do?
                           1. Continue walking
                           2. Stop to listen
                           >""")
        if user_input == "1" or user_input == "continue":
            choice = "1"
            combat()
        elif user_input == "2" or user_input == "stop":
            choice = "2"
            skill_check()
        else:
            print("""
                  Not a valid choice, please enter a number or enter
                  "continue" or "stop""")


def skill_check():
    cls()
    print("""A giant rock falls from the ceiling. 
          Roll a die to see if You can dodge it... or you'll die from it
          
          The number you get from rolling the die added to your dexterity is greater than 15 than you'll survive.
          OR
          YOU WILL DIE!""")
    input("Click enter to roll a die...")
    roll = randint(1, 6)
    print("you rolled "+str(roll))
    if roll+character_dexterity >= 15:
        print("""You've survived the stone fall
              BUT
              the strange noise from the darkness is still here and danger is not over yet...
              Prepare for next survival task...""")
        print()
        input("Press Enter to continue...")
        combat()
    else:
        print(
            "Sorry but you've failed to survive the stone fall and you are buried under it.")
        print("GAME OVER!!")
        input("Press enter to exit the game")
        exit()


def combat():
    cls()
    global character_life
    print("A horrible orc attacks you out of no where...")
    input("Press Enter to combat...")
    orc = [15, 10]
    while orc[1] > 0 or character_life > 0:
        char_roll = randint(1, 6)
        print("You rolled: " + str(char_roll))
        orc_roll = randint(1, 6)
        print("The Orc rolled: " + str(orc_roll))
        if char_roll+character_strength >= orc_roll+orc[0]:
            print("You've hit the Orc!!")
            orc[1] = orc[1] - randint(1, 6)
        else:
            print("The Orc hits you!!")
            character_life = character_life - randint(1, 6)
    if character_life > 0:
        print("You've defeated the Orc and won the game!!")
        input("Press enter to exit the game")
    else:
        print("The Orc defeated you!!")
        input("Press Enter to exit")


scene_1()
