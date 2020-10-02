#A Basic ToDo CommandLine App 
'''
Documentation:
1) Functionality = adding of task, displaying task, deletion of task
2) Global variable = taskList (type: list)
3) Author = prathmesh-Chaudhari05 (gitHub A/C)
 
*******************My Small Contribution to Open Souce**************************
'''

import pyttsx3

taskList= []

def add():
    taskList.append(input(("Assign Task-->")))
    print("New Task Has been assign")

def display():
    print("Task To Be Done")
    x=0
    for i in taskList:
        x=x+1
        print(f'{x}.{i}')

def delete():
    indx = int(input('Input Index number to Delete-->'))
    indx = indx-1   #user will enter any number and I'll reduce it by one coz list index start from 0(zero)
    # taskList.pop(indx)
    speak = taskList.pop(indx)+' task has successfully deleted'
    print(speak)


print('Welcome to To Do List Command Line App')

while True:
    print('***************************')
    print("""    1. Add In List
    2. Display List
    3. Delete Task
    4. Exit""")


    chs = input("Enter the Choice-->")

    if chs == '1':
        add()
    if chs == '2':
        display()
    if chs == '3':
        delete()
    if chs == '4':
        print("Thanks For using command Line App")
        quit()

