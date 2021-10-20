p1_leftCnt=1; p1_rightCnt=1; p2_leftCnt=1; p2_rightCnt=1;
def error():
    print("\nWrong Input.Please enter accordingly.\n");
def dead():
    print("You cant attack a dead hand...\n")
def player_status():
    if p1_leftCnt==0 and p1_rightCnt==0:
        print("\nPlayer 2 won!!");
        return 0;
    if p2_leftCnt==0 and p2_rightCnt==0:
        print("\nPlayer 1 won!!");
        return 0;
def check1():
    global p1_leftCnt,p2_leftCnt,p1_rightCnt,p2_rightCnt;
    if p1_leftCnt>=5 or p1_leftCnt<=0:
        p1_leftCnt=0;
    if p1_rightCnt>=5 or p1_rightCnt<=0:
        p1_rightCnt=0;
def check2():
    global p1_leftCnt,p2_leftCnt,p1_rightCnt,p2_rightCnt;
    if p2_leftCnt>=5 or p2_leftCnt<=0:
        p2_leftCnt=0;
    if p2_rightCnt>=5 or p2_rightCnt<=0:
        p2_rightCnt=0;
def attack1():
    global p1_leftCnt,p2_leftCnt,p1_rightCnt,p2_rightCnt;
    try:
        atk_move0,atk_move1=input("Enter attack combination : ").split(); atk_move0=atk_move0.upper(); atk_move1=atk_move1.upper(); 

        if atk_move0=="L" and atk_move1=="L":
            if p2_leftCnt!=0:
                p2_leftCnt= p2_leftCnt + p1_leftCnt;
            else:
                dead(); attack1();
        elif atk_move0=='L' and atk_move1=='R':
            if p2_rightCnt!=0:
                p2_rightCnt=p2_rightCnt+ p1_leftCnt;
            else:
                dead(); attack1() 
        elif atk_move0=='R' and atk_move1=='R':
             if p2_rightCnt!=0:
                p2_rightCnt=p2_rightCnt+ p1_rightCnt;
             else:
                dead(); attack1() 
        elif atk_move0=='R' and atk_move1=='L':
            if p2_leftCnt!=0:
                p2_leftCnt=p2_leftCnt+ p1_rightCnt;
            else:
                dead(); attack1()  
        else:
            error(); attack1();
    except ValueError:
        print("Value Error detected.\n"); attack1();
def attack2():
    global p1_leftCnt,p2_leftCnt,p1_rightCnt,p2_rightCnt;
    try:
        atk_move0,atk_move1=input("Enter attack combination : ").split(); atk_move1=atk_move1.upper(); atk_move0=atk_move0.upper();
        if atk_move0=='L' and atk_move1=='L':
            if p1_leftCnt!=0:
                p1_leftCnt= p1_leftCnt + p2_leftCnt;
            else:
                dead(); attack2()
        elif atk_move0=='L' and atk_move1=='R':
            if p1_rightCnt!=0:
                p1_rightCnt=p1_rightCnt+ p2_leftCnt;
            else:
                dead(); attack2() 
        elif atk_move0=='R' and atk_move1=='R':
            if p1_rightCnt!=0:
                p1_rightCnt=p1_rightCnt+p2_rightCnt;
            else:
                dead(); attack2(); 
        elif atk_move0=='R' and atk_move1=='L':
            if p1_leftCnt!=0:
                p1_leftCnt=p1_leftCnt+p2_rightCnt;
            else:
                dead(); attack2(); 
        else:
            error(); attack2();
    except ValueError:
        print("Value Error detected.\n"); attack2();

def split1():
    global p1_leftCnt,p2_leftCnt,p1_rightCnt,p2_rightCnt;
    try:
        split_hand,split_left,split_right=input("Enter the move for split : ").split(); split_left=int(split_left); split_right=int(split_right);
        if (p1_rightCnt+p1_leftCnt)==(split_left+split_right) and (split_left+split_right)<=8:
            if split_right==5 or split_left==5 or split_left==0 or split_right==0:
                print("You,sir,have walked towards your own descent.\n");
            p1_leftCnt=split_left; p1_rightCnt=split_right;
        else:
            error(); split1();
    except ValueError:
        print("Value Error detected.\n"); split1();
def split2():
    global p1_leftCnt,p2_leftCnt,p1_rightCnt,p2_rightCnt;
    try:
        split_hand,split_left,split_right=input("Enter the move for split : ").split(); split_left=int(split_left); split_right=int(split_right);
        if (p2_leftCnt+p2_rightCnt)==(split_left+split_right) and (split_left+split_right)<=8:
            if split_right==5 or split_left==5 or split_left==0 or split_right==0:
                print("You,sir,have walked towards your own descent.\n");
            p2_leftCnt=split_left; p2_rightCnt=split_right; 
        else:
            error(); split2();
    except ValueError:
        print("Value Error detected.\n"); split2();
def display_status():
    print("\nCurrent status : \nPlayer 1 - ",p1_leftCnt,p1_rightCnt,"\nPlayer 2 - ",p2_leftCnt,p2_rightCnt,"\n");
def player1():
    p1=input("\nEnter move for player 1 : ");
    if p1=='A' or p1=='a':
        attack1();
    elif p1=='S' or p1=='s':
        split1();
    else:
        error(); player1();
def player2():
    p2=input("\nEnter move for player 2 : ");
    if p2=='A' or p2=='a':
        attack2();
    elif p2=='S' or p2=='s':
        split2();
    else:
        error(); player2(); 
print("\t\t\t\tWELCOME TO THE CHOPSTICKS GAME.\n")
print("MOVES ARE OF TWO TYPES: 'A' FOR ATTACK AND 'S' FOR SPLIT.\n")
print("IN ATTACK COMBINATION USER INPUTS HAND TO ATTACK FROM AND HAND TO ATTACK TO.")
print("IN SPLIT USER INPUTS HAND TO SPLIT(L/R) AND NUMBER OF FINGERS OF LEFT AND RIGHT HAND AFTER SPLIT")
print("ONCE A PLAYER REACHES 5 FINGERS OR 0 FINGERS ON BOTH HANDS,OTHER PLAYER WINS.")
print("IN PLAYER CURRENT STATUS,FIRST NUMBER INDICATES THE NUMBER OF FINGERS IN LEFT AND SECOND INDICATES NUMBER OF FINGERS IN RIGHT HAND\n")
display_status();
while(True): 
    player1();
    check1();check2();
    display_status();
    if player_status()==0:
        break;
    player2();
    check2();check1();
    display_status();
    if player_status()==0:
        break;
