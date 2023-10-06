
# Basic libraries to import for completing the whole work.
import sys
from PyQt5.uic import loadUi
from PyQt5.QtWidgets import *
from PyQt5 import QtCore, QtGui, QtWidgets
import csv
import pandas as pd

class Mainwindow(QMainWindow):
    def __init__(self):
        super(Mainwindow,self).__init__()
        loadUi("scrape.ui",self) # Here we imported the QT Designer file which we made as Python GUI FIle.
        
        # Command to remove the default Windows Frame Design.
        self.setWindowFlag(QtCore.Qt.FramelessWindowHint)
        # Command to make the backgroud of Window transparent.
        self.setAttribute(QtCore.Qt.WA_TranslucentBackground)
        
        #These 2 lines are used to put funnctions on close and minimize buttons.
        self.MinimizeButton.clicked.connect(lambda: self.showMinimized())
        self.CrossButton.clicked.connect(lambda: self.close())
        
        # Function to load the previous data of student at the start of program.
        self.load_table()
        
        #Button Functions
        self.AddButton.clicked.connect(self.Add_student)
        self.DeleteButton.clicked.connect(self.Delete_student)
        self.EditButton.clicked.connect(self.edit_student)
        self.StuInfoTable.clicked.connect(self.fill_values)
        
    
    # This functions allows the user to select the value from the table to edit or delete
    # the information of the students.
    def fill_values(self):
        row = self.StuInfoTable.currentRow()
        self.NameEdit.setText(self.StuInfoTable.item(row,0).text())
        self.RegEdit.setText(self.StuInfoTable.item(row,1).text())
        self.gpaEdit.setText(self.StuInfoTable.item(row,2).text())
        self.NumberEdit.setText(self.StuInfoTable.item(row,3).text())
        self.uniEdit.setText(self.StuInfoTable.item(row,4).text())
    
    
    # This is a helping function to put the text fields back after adding or editing a STudent.
    def resetValues(self):
        self.NameEdit.setText("Student Name")
        self.RegEdit.setText("Registration Number")
        self.gpaEdit.setText("GPA")
        self.NumberEdit.setText("Number")
        self.uniEdit.setText("University")
        
    #This is also a helping function to put a validation that student of same registration should not be added.
    def Check_regNo(self,reg): 
        print(reg)
        with open('student.csv', 'r',encoding="utf-8",newline="") as fileInput:
            data = list(csv.reader(fileInput))
            print(data)
            for row in data:
                print(row[1])
                if reg == row[1]:
                    print("hi")
                    return False
        return True


    # This Function will take some values from the textfields and will add the data of student to the 
    # CSV FIle if the registration number is Written is not added before.
    def Add_student(self):
        name = self.NameEdit.text()
        regNo = self.RegEdit.text()
        gpa = self.gpaEdit.text()
        number = self.NumberEdit.text()
        uni = self.uniEdit.text()

        if(regNo != "Registration Number" and self.Check_regNo(regNo)):
            
            student_data = [name,regNo,gpa,number,uni]

            with open('student.csv', 'a+',encoding="utf-8",newline="") as fileInput:
                writer = csv.writer(fileInput)
                writer.writerows([student_data])
            self.resetValues()
        else:
            msg=QMessageBox()
            msg.setWindowTitle("--- Add a Student ---")
            msg.setText("Registration Number is already Added.")
            msg.setIcon(QMessageBox.Information)
            msg.setStandardButtons(QMessageBox.Ok|QMessageBox.Cancel)
            font=QtGui.QFont()
            font.setPointSize(12)
            font.setBold(True)
            font.setWeight(75)
            msg.setFont(font)
            msg.exec()
        
        #This is to reload the table so that recent added data shows in the table
        self.load_table()
        
    # This FUnction will take values from the table and will edit new values according to previous
    # registration  number.
    def edit_student(self):
        row = self.StuInfoTable.currentRow()
        old_id = self.StuInfoTable.item(row,1).text()
        name = self.NameEdit.text()
        regNo = self.RegEdit.text()
        gpa = self.gpaEdit.text()
        number = self.NumberEdit.text()
        uni = self.uniEdit.text()

        index_student = None
        updated_data = []
        with open('student.csv', "r", encoding="utf-8") as fileInput:
            reader = csv.reader(fileInput)
            counter = 0
            for row in reader:
                if len(row) > 0:
                    if old_id == row[1]:
                        student_found = True
                        student_data = []
                        student_data.append(name)
                        student_data.append(regNo)
                        student_data.append(gpa)
                        student_data.append(number)
                        student_data.append(uni)
                        updated_data.append(student_data)
                    else:
                        updated_data.append(row)
                    
        if student_found is True:
            fileName = 'C:/Users/monti/A-CRUD/students.csv'
            with open('student.csv', "w", encoding="utf-8",newline="") as fileInput:
                writer = csv.writer(fileInput)
                writer.writerows(updated_data)
            self.load_table()
            self.resetValues()
        
    # This Function will delete the student from the csv file depending upon the reg Number.
    def Delete_student(self):
        if(self.RegEdit.text() != "Registration Number"):
            ID = self.RegEdit.text()
            student_found = False
            updated_data = []
            with open('student.csv', "r", encoding="utf-8") as fileInput:
                reader = csv.reader(fileInput)
                for row in reader:
                    if len(row) > 0:
                        if ID != row[1]:
                            updated_data.append(row)
                        else:
                            student_found = True
            

            if student_found is True:
                with open('student.csv', "w", encoding="utf-8", newline="") as fileInput:
                    writer = csv.writer(fileInput)
                    writer.writerows(updated_data)
                self.load_table()
                self.resetValues()
        
        
    # This is a helping Function to load the content of the table after every event.
    def load_table(self):
        with open('student.csv', "r",encoding="utf-8") as fileInput:
            roww = 0
            data = list(csv.reader(fileInput))
            
            self.StuInfoTable.setRowCount(len(data))
            for row in data:
                self.StuInfoTable.setItem(roww, 0 , QtWidgets.QTableWidgetItem((row[0])))
                self.StuInfoTable.setItem(roww, 1 , QtWidgets.QTableWidgetItem((row[1])))
                self.StuInfoTable.setItem(roww, 2 , QtWidgets.QTableWidgetItem((row[2])))
                self.StuInfoTable.setItem(roww, 3 , QtWidgets.QTableWidgetItem((row[3])))
                self.StuInfoTable.setItem(roww, 4 , QtWidgets.QTableWidgetItem((row[4])))
                roww =+ 1
# main

app = QApplication(sys.argv)
window = Mainwindow()
window.show()
sys.exit(app.exec_())



