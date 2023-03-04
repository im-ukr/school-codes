from tkinter import *
from tkinter.ttk import *
from time import strftime, time
root=Tk()
root.title("My clock")
def time():
    string=strftime("%H:%M:%S %p")
    label.config(text=string)
    label.after(1000,time)

label=Label(root, font=("times new roman",80),background="black",foreground="blue")
label.pack(anchor="center")
time()

mainloop()