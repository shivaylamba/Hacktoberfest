import tkinter as tk
from tkinter import ttk
import random,time
from tkinter import messagebox
LARGE_FONT =("Verdana",15)
class Game(tk.Tk):
    def __init__(self,*args,**kwargs):
        tk.Tk.__init__(self,*args,**kwargs)
        tk.Tk.wm_title(self,'game')
        container = tk.Frame(self)
        container.pack(side ="top",fill= "both", expand =True)
        container.grid_rowconfigure(0,weight=1)
        container.grid_columnconfigure(0,weight=1)
        self.frames={}
        for F in (StartPage,PageOne,PageTwo):
            frame =F(container,self)
            self.frames[F] =frame
            frame.grid(row=0,column =0, sticky ="nsew")
        self.show_frame(StartPage)


    def show_frame(self,cont):
        frame = self.frames[cont]
        frame.tkraise()

class StartPage(tk.Frame):
    def __init__(self,parent,controller):
        tk.Frame.__init__(self,parent)
        label =tk.Label(self, text ="Select your level",font = LARGE_FONT)
        label.pack(pady =10, padx=10)
        btn1 = ttk.Button(self,text ="level1",
                          command =lambda:controller.show_frame(PageOne))
        btn2 = ttk.Button(self,text ="level2", command =lambda:controller.show_frame(PageTwo))
        btn1.pack()
        btn2.pack()

class PageOne(tk.Frame):
    def __init__(self,parent,controller):
        tk.Frame.__init__(self,parent)
        self.buttons = [[tk.Button(self,width=25,height=12, command=lambda row=row, column=column: self.choose_tile(row, column)) for column in range(3)] for row in range(4)]
        for row in range(4):
            for column in range(3):
                self.buttons[row][column].grid(row=row, column=column)
        self.first = None
        self.remeber_numbers=[]
        self.score =0
        self.draw_board()
    def draw_board(self):
        self.answer = list('123123123123')
        random.shuffle(self.answer)
        self.answer = [self.answer[:3], self.answer[3:6], self.answer[6:9], self.answer[9:]]
        for row in self.buttons:
            for button in row:
                button.config(text='', state=tk.NORMAL)
        self.start_time = time.monotonic()

    def choose_tile(self, row, column):
        self.buttons[row][column].config(text=self.answer[row][column],fg ='green')
        self.buttons[row][column].config(state=tk.DISABLED)
        duration = time.monotonic() - self.start_time
        if(duration<60):
            if not self.first:
                self.first = (row, column)
            else:
                a,b = self.first
                if self.answer[row][column] == self.answer[a][b]:
                    self.answer[row][column] = ''
                    self.answer[a][b] = ''
                    self.score =self.score+20
                    if not any(''.join(row) for row in self.answer):
                        timer = time.monotonic() - self.start_time
                        self.score = self.score+int(timer)
                        messagebox.showinfo(title='Winner!', message='Your score ='+str(self.score))
                        self.after(1000, self.draw_board)
                else:
                    self.score =self.score-5
                    self.after(2000, self.hide_tiles, row, column, a, b)
                self.first = None
        else:
            messagebox.showinfo(title='Game Finished!', message='Game finished! Your score = '+str(self.score))
            self.after(1000, self.draw_board)
    def hide_tiles(self, x1, y1, x2, y2):
        self.buttons[x1][y1].config(text='', state=tk.NORMAL)
        self.buttons[x2][y2].config(text='', state=tk.NORMAL)


class PageTwo(tk.Frame):
    def __init__(self,parent,controller):
        self.cont =controller
        tk.Frame.__init__(self,parent)
        self.buttons = [[tk.Button(self,width=25,height=12, command=lambda row=row, column=column: self.choose_tile(row, column)) for column in range(3)] for row in range(4)]
        for row in range(4):
            for column in range(3):
                self.buttons[row][column].grid(row=row, column=column)
        self.first = None
        self.remeber_numbers=[]
        self.score =0
        self.draw_board()
    def configBoard(self):
        for row in self.buttons:
            for button in row:
                button.config(text='', state=tk.NORMAL)
    def draw_board(self):
        self.answer = list('123123123123')
        random.shuffle(self.answer)
        self.answer = [self.answer[:3], self.answer[3:6], self.answer[6:9], self.answer[9:]]
        for i,row in enumerate(self.buttons):
            for j,button in enumerate(row):
                button.config(text=self.answer[i][j], state=tk.DISABLED)

        self.after(6000, self.configBoard)
        self.start_time = time.monotonic()

    def choose_tile(self, row, column):
        self.buttons[row][column].config(text=self.answer[row][column],fg ='green')
        self.buttons[row][column].config(state=tk.DISABLED)
        duration = time.monotonic() - self.start_time
        if(duration<60):
            if not self.first:
                self.first = (row, column)
            else:
                a,b = self.first
                if self.answer[row][column] == self.answer[a][b]:
                    self.answer[row][column] = ''
                    self.answer[a][b] = ''
                    self.score =self.score+20
                    if not any(''.join(row) for row in self.answer):
                        timer = time.monotonic() - self.start_time
                        self.score = self.score+int(timer)
                        messagebox.showinfo(title='Winner!', message='Your score ='+str(self.score))
                        self.after(1000, lambda:self.cont.show_frame(PageOne))
                else:
                    self.score =self.score-5
                    self.after(2000, self.hide_tiles, row, column, a, b)
                self.first = None
        else:
            messagebox.showinfo(title='Game Finished!', message='Game finished! Your score = '+str(self.score))
            self.after(1000,lambda:self.cont.show_frame(PageOne))
    def hide_tiles(self, x1, y1, x2, y2):
        self.buttons[x1][y1].config(text='', state=tk.NORMAL)
        self.buttons[x2][y2].config(text='', state=tk.NORMAL)
app = Game()
app.mainloop()