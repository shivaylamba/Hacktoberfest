#A simple number-guessing game!!
magicNumber = 4
times = 3

print('Welcome to Magic Number Game, made by Daberechi!! :)')

while times != 0:
    print('guess a number between 1 and 5 to get the magic number')

    guess = int(input('Number: '))

    if guess== magicNumber:
        print('Hooooorayyy!! you got it')
        break
    else:
        times -= 1
        print('You missesd it. Try again')
        print('You have', times, 'more times')

