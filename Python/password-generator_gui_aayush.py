# importing Libraries

import random
import string
import tkinter

import pyperclip

# initialize window

root = tkinter.Tk()
root.geometry("400x200")
root.resizable(0, 0)
root.title("RANDOM PASSWORD GENERATOR")

# heading
heading = tkinter.Label(root, text='PASSWORD GENERATOR TOOL', font='arial 15 bold').pack()

# select password length
pass_label = tkinter.Label(root, text='SELECT PASSWORD LENGTH', font='arial 10 bold').pack()
pass_len = tkinter.IntVar()
length = tkinter.Spinbox(root, from_=8, to_=32, textvariable=pass_len, width=15).pack()

# define function

pass_str = tkinter.StringVar()


def Generator():
    password = ''
    for x in range(0, 4):
        password = random.choice(string.ascii_uppercase) + random.choice(string.ascii_lowercase) + random.choice(
            string.digits) + random.choice(string.punctuation)
    for y in range(pass_len.get() - 4):
        password = password + random.choice(
            string.ascii_uppercase + string.ascii_lowercase + string.digits + string.punctuation)
    pass_str.set(password)


# button

tkinter.Button(root, text="GENERATE PASSWORD", command=Generator).pack(pady=5)

tkinter.Entry(root, textvariable=pass_str).pack()


# function to copy

def Copy_password():
    pyperclip.copy(pass_str.get())


tkinter.Button(root, text='COPY TO CLIPBOARD', command=Copy_password).pack(pady=5)

# loop to run program
root.mainloop()
