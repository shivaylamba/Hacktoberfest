from tkinter import *
import mysql.connector as S
conn=S.connect(host="localhost",user="root",passwd="chikuSQL@123",database="chiku") #Information to be entered by user.
cursor=conn.cursor()
root=Tk()
root.geometry("500x300")
root.title("VVV Project")

#Storing Data from File onto Database
def storevals(a,b,c,d):
    sql1='''CREATE TABLE Std_Info(
          Name varchar(20),
          Class varchar(6),
          Section varchar(2),
          Roll_Number varchar(2) primary key,
          Gender varchar(6)
          )'''
    cursor.execute(sql1)
    sql="INSERT INTO Std_Info(Name,Class,Section,Roll_Number,Gender) VALUES(%s,%s,%s,%s,%s)"
    vals=(a,b,c,d,"U")
    cursor.execute(sql,vals)
    conn.commit()
    print("data saved")
    conn.close()
    
#Trigger Function Storing Values in a Binary File
def getvals():
    print("Accepted")
    d={}
    a=nameentry.get()
    b=stdentry.get()
    c=sectionentry.get()
    d=rollentry.get()
    storevals(a,b,c,d)
    print("Data Stored")
    print(a)
    
#Heading
Label(root, text="Sign Up Portal", font="calibri 20 bold").grid(row=0,column=3)

