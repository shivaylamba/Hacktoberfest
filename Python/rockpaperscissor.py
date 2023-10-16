# -*- coding: utf-8 -*-
"""
Created on Mon Aug 17 14:24:23 2020

@author: Gulshan
"""
# Function rock_paper_scissor--->
def rock_paper_scissor(num1,num2,bit1,bit2):
    play_pos1=int(num1[bit1])%3  #Play Position For Player 1
    play_pos2=int(num2[bit2])%3  #Play Position For Player 2
    if(player_one[play_pos1]==player_two[play_pos2]):
        print("Draw")
    elif(player_one[play_pos1]=="Rock" and player_two[play_pos2]=="Scissor"):
        print("Player one wins!!")
    elif(player_one[play_pos1]=="Rock" and player_two[play_pos2]=="Paper"):
        print("Player two wins!!")
    elif(player_one[play_pos1]=="Paper" and player_two[play_pos2]=="Scissor"):
        print("Player two wins!!")
    elif(player_one[play_pos1]=="Paper" and player_two[play_pos2]=="Rock"):
        print("Player one wins!!")
    elif(player_one[play_pos1]=="Scissor" and player_two[play_pos2]=="Rock"):
        print("Player two wins!!")
    elif(player_one[play_pos1]=="Scissor" and player_two[play_pos2]=="Paper"):
        print("Player one wins!!")

# Main Function To Execute Rock Paper Scissor        
if __name__ == '__main__':        
    player_one={0:'Rock',1:'Paper',2:'Scissor'}
    player_two={0:'Paper',1:'Rock',2:'Scissor'}
    while(1):
        num1=input("Player one, Enter your choice ")
        num2=input("Player two, Enter your choice ")
        bit1=int(input("Player one, Enter the secret bit position "))
        bit2=int(input("Player two, Enter the secret bit position "))
        rock_paper_scissor(num1,num2,bit1,bit2)
        ch=input("Do you want to continue? y/n ")
        if(ch=='n'):
            break
            
            
'''
Output Implementation:

Player one, Enter your choice 123                                                                                               
Player two, Enter your choice 567                                                                                               
Player one, Enter the secret bit position 0                                                                                     
Player two, Enter the secret bit position 1                                                                                     
Draw

Do you want to continue? y/n y                                                                                                  
Player one, Enter your choice 012                                                                                               
Player two, Enter your choice 234                                                                                               
Player one, Enter the secret bit position 1                                                                                     
Player two, Enter the secret bit position 2                                                                                     
Player one wins!!

Do you want to continue? y/n y                                                                                                  
Player one, Enter your choice 345                                                                                               
Player two, Enter your choice 012                                                                                               
Player one, Enter the secret bit position 0                                                                                     
Player two, Enter the secret bit position 2                                                                                     
Player one wins!!  

'''
