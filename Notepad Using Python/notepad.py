from tkinter import *
from tkinter.messagebox import showinfo
from tkinter.filedialog import askopenfilename, asksaveasfilename
import os


def newFile():
    global file
    root.title("Untitled - Notepad")
    file = None
    TextArea.delete(1.0,  END)

def openFile():
    global file
    file = askopenfilename(defaultextension=".txt", filetypes=[("All Files", "*.*"),("Text Files", "*.txt")])
    if file == "":
        File = None
    else:
        root.title(os.path.basename(file) + " - Notepad")
        TextArea.delete(1.0, END)
        f = open(file, "r")
        TextArea.insert(1.0, f.read())
        f.close()

def saveFile():
    global file
    if file == None:
        file = asksaveasfilename(initialfile='Untitled.txt', defaultextension=".txt", filetypes=[("All Files", "*.*"),("Text Files", "*.txt")])
        if file == "":
            file = None
        else:
            # Save as new file
            f = open(file, "w")
            f.write(TextArea.get(1.0, END))

            root.title(os.path.basename(file) + " - Notepad")
            print("File Saved")
    else:
        # Saving the file
        f = open(file, "w")
        f.write(TextArea.get(1.0, END))

def exit():
    root.destroy()

def cut():
    TextArea.event_generate(("<<Cut>>"))

def copy():
    TextArea.event_generate(("<<Copy>>"))

def paste():
    TextArea.event_generate(("<<Paste>>"))

def aboutUs():
    showinfo("Notepad", "Nodepad By Rohit Kumar Saini")


if __name__ == '__main__':
    #Basic tkinter setup
    root =Tk()
    root.geometry("600x500")
    root.title("Untitled - Notepad")
    root.wm_iconbitmap("notepad.ico")

    #Adding TextArea
    TextArea = Text(root, font="lucida 13")
    file = None
    TextArea.pack(fill="both", expand=True)

    #Creating a MenuBar
    MenuBar = Menu(root)
    # FileMenu Startting from here
    FileMenu = Menu(MenuBar, tearoff=0)

    # Creating New File
    FileMenu.add_command(label="New", command=newFile)

    # Opening a file
    FileMenu.add_command(label="Open", command=openFile)

    # Saving the file
    FileMenu.add_command(label="Save", command=saveFile)
    FileMenu.add_separator()

    FileMenu.add_command(label="Exit", command=exit)
    MenuBar.add_cascade(label="File", menu=FileMenu)
    # FileMenu Ending Here

    # Edit Menu Starting here
    EditMenu = Menu(MenuBar, tearoff=0)
    # Cut Feature
    EditMenu.add_command(label="Cut ", command=cut)
    EditMenu.add_command(label="Copy", command=copy)
    EditMenu.add_command(label="Paste", command=paste)
    MenuBar.add_cascade(label="Edit", menu=EditMenu)

    # Edit menu ends here
    # Help Menu Starts here
    HelpMenu = Menu(MenuBar, tearoff=0)
    HelpMenu.add_command(label="About Us", command=aboutUs)
    MenuBar.add_cascade(label="Help", menu=HelpMenu)
    # Help Menu ends here
    root.config(menu=MenuBar)

    # Adding Scrollbar
    Scroll = Scrollbar(TextArea)
    Scroll.pack(side=RIGHT, fill=Y)
    Scroll.config(command=TextArea.yview)
    TextArea.config(yscrollcommand=Scroll.set)


    root.mainloop()