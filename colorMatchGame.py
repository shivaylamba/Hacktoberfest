#Importing libraries
import sqlite3
import tkinter 
import random
global score 
global time_remaining
global user_entry
#Creating color list
colours = ['Red','Blue','Green','Pink','Black', 
           'Yellow','Orange','White','Purple','Brown','Cyan','Grey','Brown']
score = 0
time_remaining = 45

#Creating database table
register=sqlite3.connect('color_game.db')
c=register.cursor()
create= "CREATE TABLE IF NOT EXISTS game (name TEXT, score INT);"
register.execute(create)


# game starts using this function
def startGame(event): 
      
    if time_remaining == 45: 
          
        CountDownTimer() 
          
    # run the function to 
    # choose the next colour. 
    RandomColour() 
  
# To Display the Next Random Color
def RandomColour(): 
  
    global score 
    global time_remaining
    global user_entry
  
    if time_remaining > 0: 
  
        # make the text entry box active. 
        InputBox.focus_set() 
  
        if InputBox.get().lower() == colours[1].lower(): 
              
            score += 1
  
        # clear the text entry box. 
        InputBox.delete(0, tkinter.END) 
          
        random.shuffle(colours) 
          
        # change the colour to type, by changing the 
        # text _and_ the colour to a prirandom colour value 
        label.config(fg = str(colours[1]), text = str(colours[0])) 
          
        # update the score. 
        ScoreBoard.config(text = "Score: " + str(score))

        #Calling to finalise the score 
        if time_remaining==0:
            # Assigning final value
            finalscore=score
    
            #Printing the final score
            print("Your final score is: ",score)

            # Adding it to database
            insert="INSERT INTO game (name,score) VALUES('{}',{})"
            c.execute(insert.format(user_entry, finalscore))
            register.commit()
          
# Countdown timer function  
def CountDownTimer(): 
  
    global time_remaining 
  
    # if a game is in play 
    if time_remaining > 0: 
  
        # decrement the timer. 
        time_remaining -= 1
          
        # update the time left label 
        TimeBoard.config(text = "Time left: "
                               + str(time_remaining)) 
                                 
        # run the function again after 1 second. 
        TimeBoard.after(1000, CountDownTimer) 
  
  
# Program
user_entry=input("Enter player name: ")

root = tkinter.Tk() 

root.title("Color Match!")

root.geometry("600x500")

rules = tkinter.Label(root, text = "Type in the colour"
                        " of the words, and not the word text!", 
                                      font = ('aria', 14,'bold')) 
rules.pack()  
  
ScoreBoard = tkinter.Label(root, text = "Press enter to start", 
                                      font = ('aria', 12,'bold')) 
ScoreBoard.pack() 
   
TimeBoard = tkinter.Label(root, text = "Time left: " +
              str(time_remaining), font = ('Courier', 17,'bold')) 
                
TimeBoard.pack()
 
label = tkinter.Label(root, font = ('Helvetica', 60))
label.pack() 
  
InputBox = tkinter.Entry(root, width=30)

  
# run the 'startGame' function  
# when the enter key is pressed 
root.bind('<Return>', startGame) 
InputBox.pack() 
  
InputBox.focus_set() 

# start the GUI 
root.mainloop()

