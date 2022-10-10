from random import randint
num=randint(1,100)

print('\nI will think a number between 1 and 100 u need to guess that number.\n')
print('Rule:-\n\t1. When you are close to the number it gets warm otherwise cold.')
print('\t2. The closer u go it goes warmer otherwise it get colder.\n')

gusslist=[0]
flag= False

guess = int(input("\nI'm thinking of a number between 1 and 100.\nWhat is your guess??\n"))

while True:
    print('\n')
        
    if guess<1 or guess>100:
        print('OUT OF BOUNDS! Please try again: ')
        guess = int(input("What's your guess?? " ))
        continue
    
    if (len(gusslist)!=1):
        guess = int(input('Guess again!!\n'))
        
    if guess==num:
        print(f'CONGRATULATIONS, YOU GUESSED IT IN ONLY {len(gusslist)} GUESSES!!')
        break
        
    gusslist.append(guess)
        
    if flag:
        if abs(num-guess) < abs(num-gusslist[-2]):
            print('Warmer!!')
        else:
            print('Colder!!')     
    else:
        if abs(num-guess)>10:
            print('Cold!!')
        else:
            print('Warm!!')
            flag=True