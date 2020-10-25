print ""
print "**** Welcome to Rock Paper Scissors Spock Lizard ****"
print""

while 'Y':
        inputOK=0
        while (inputOK==0):
                stringPlayer1 = raw_input ("Player 1, choose: rock, paper, scissors, spock, or lizard: ")
                if (stringPlayer1== 'rock' or stringPlayer1== 'paper' or stringPlayer1 == 'scissors'
                        or stringPlayer1 == 'spock' or stringPlayer1 == 'lizard'):
                        inputOK=1
                else:
                        print "Error: You did not select rock, paper, or scissors."
        inputOK=0
        while (inputOK==0):
                stringPlayer2 = raw_input ("Player 2, choose: rock, paper, scissors, spock, or lizard: ")
                if (stringPlayer2== 'rock' or stringPlayer2== 'paper' or stringPlayer2 == 'scissors'
                        or stringPlayer2 == 'spock' or stringPlayer2 == 'lizard'):
                        inputOK=1
                else:
                        print "Error: You did not select rock, paper, or scissors."	
        if (stringPlayer1 == stringPlayer2 ):
                print "Tie: Both players chose:" + stringPlayer1

        elif (stringPlayer1 == 'rock' and stringPlayer2 == 'scissors'):
            print "Player 1 wins: rock smashes scissors."
                
        elif (stringPlayer1 == 'scissors' and stringPlayer2 == 'paper'):
            print "Player 1 wins: scissors cut paper."

        elif (stringPlayer1 == 'paper' and stringPlayer2 == 'rock'):
            print "Player 1 wins: paper covers rock."
                
        elif (stringPlayer1 == 'paper' and stringPlayer2 == 'scissors'):
            print "Player 2 wins: scissors cut paper."

        elif (stringPlayer1 == 'rock' and stringPlayer2 == 'paper'):
            print "Player 2 wins: paper covers rock."

        elif (stringPlayer1 == 'scissors' and stringPlayer2 == 'rock'):
            print "Player 2 wins: rock smashes scissors."

        elif (stringPlayer1 == 'spock' and stringPlayer2 == 'lizard'):
            print "Player 1 wins: spock vulcan nerve pinches lizard."
                
        elif (stringPlayer1 == 'spock' and stringPlayer2 == 'rock'):
            print "Player 2 wins: rock smashes spock."
                
        elif (stringPlayer1 == 'spock' and stringPlayer2 == 'scissors'):
            print "Player 2 wins: scissors cuts spock."
                
        elif (stringPlayer1 == 'spock' and stringPlayer2 == 'paper'):
            print "Player 1 wins: spock crumples paper."

        elif (stringPlayer1 == 'lizard' and stringPlayer2 == 'spock'):
            print "Player 2 wins: spock vulcan nerve pinches lizard."	

        elif (stringPlayer1 == 'lizard' and stringPlayer2 == 'rock'):
            print "Player 2 wins: rock smashes lizard."

        elif (stringPlayer1 == 'lizard' and stringPlayer2 == 'paper'):
            print "Player 1 wins: lizard eats paper."

        elif (stringPlayer1 == 'lizard' and stringPlayer2 == 'scissors'):
            print "Player 2 wins: lizard gets cut by scissors."	

        else:
            print "Error: Somebody did not select rock, paper, or scissors."

        print
        stringPlayer=raw_input("Play Again: 'Y' or 'N' :").lower
        if stringPlayer1 == 'Y' :
                'Y'
        if stringPlayer1 == 'N' :
                break
                stringWait = raw_input ("Press Enter to close Window ...")
        
