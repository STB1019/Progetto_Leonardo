import tkinter as tk
import tkinter.font as tkFont
#import rospy
import serial
#from geometry_msgs.msg import Twist

#import serial
import time


#s = serial.Serial('/dev/ttyUSB0', 9600) ####### change name, if needed
#s.open()
time.sleep(5) # the Arduino is reset after enabling the serial connectio, therefore we have to wait some seconds
 

class App:
    def __init__(self, root):
        #setting title
        root.title("Controller")
        
        #Font
        dfont="Arial";

        #setting window size
        width=580
        height=620
        screenwidth = root.winfo_screenwidth()
        screenheight = root.winfo_screenheight()
        alignstr = '%dx%d+%d+%d' % (width, height, (screenwidth - width) / 2, (screenheight - height) / 2)
        root.geometry(alignstr)
        root.resizable(width=False, height=False)

        #TODO: add speed selector

        GButton_UP=tk.Button(root)
        GButton_UP["activebackground"] = "#1872c6"
        GButton_UP["bg"] = "#1f93ff"
        GButton_UP["cursor"] = "trek"
        ft = tkFont.Font(family=dfont,size=38)
        GButton_UP["font"] = ft
        GButton_UP["fg"] = "#ffffff"
        GButton_UP["justify"] = "center"
        GButton_UP["text"] = "⇪"
        GButton_UP.place(x=240,y=100,width=100,height=100)
        GButton_UP["command"] = self.GButton_UP_command

        GButton_DOWN=tk.Button(root)
        GButton_DOWN["activebackground"] = "#1872c6"
        GButton_DOWN["bg"] = "#1f93ff"
        GButton_DOWN["cursor"] = "spraycan"
        ft = tkFont.Font(family=dfont,size=38)
        GButton_DOWN["font"] = ft
        GButton_DOWN["fg"] = "#ffffff"
        GButton_DOWN["justify"] = "center"
        GButton_DOWN["text"] = "⇩"
        GButton_DOWN.place(x=240,y=210,width=100,height=100)
        GButton_DOWN["command"] = self.GButton_DOWN_command

        GButton_234=tk.Button(root)
        GButton_234["activebackground"] = "#1872c6"
        GButton_234["bg"] = "#1f93ff"
        GButton_234["cursor"] = "star"
        ft = tkFont.Font(family=dfont,size=38)
        GButton_234["font"] = ft
        GButton_234["fg"] = "#ffffff"
        GButton_234["justify"] = "center"
        GButton_234["text"] = "⇦"
        GButton_234.place(x=130,y=210,width=100,height=100)
        GButton_234["command"] = self.GButton_234_command

        GButton_727=tk.Button(root)
        GButton_727["activebackground"] = "#1872c6"
        GButton_727["bg"] = "#1f93ff"
        GButton_727["cursor"] = "spider"
        ft = tkFont.Font(family=dfont,size=38)
        GButton_727["font"] = ft
        GButton_727["fg"] = "#ffffff"
        GButton_727["justify"] = "center"
        GButton_727["text"] = "⇨"
        GButton_727.place(x=350,y=210,width=100,height=100)
        GButton_727["command"] = self.GButton_727_command

        GLabel_493=tk.Label(root)
        GLabel_493["bg"] = "#0007ff"
        ft = tkFont.Font(family=dfont,size=28)
        GLabel_493["font"] = ft
        GLabel_493["fg"] = "#ffffff"
        GLabel_493["justify"] = "center"
        GLabel_493["text"] = "Progetto Leonardo"
        GLabel_493.place(x=130,y=20,width=320,height=50)

        GButton_320=tk.Button(root)
        GButton_320["activebackground"] = "#ffb800"
        GButton_320["bg"] = "#ffd700"
        ft = tkFont.Font(family=dfont,size=38)
        GButton_320["font"] = ft
        GButton_320["fg"] = "#000000"
        GButton_320["justify"] = "center"
        GButton_320["text"] = "☢"
        GButton_320.place(x=130,y=100,width=100,height=100)
        GButton_320["command"] = self.GButton_320_command

        GButton_69=tk.Button(root)
        GButton_69["bg"] = "#f0f0f0"
        ft = tkFont.Font(family=dfont,size=28)
        GButton_69["font"] = ft
        GButton_69["fg"] = "#000000"
        GButton_69["justify"] = "center"
        GButton_69["text"] = "↺"
        GButton_69.place(x=350,y=100,width=100,height=100)
        GButton_69["command"] = self.GButton_69_command

        GButton_293=tk.Button(root)
        GButton_293["bg"] = "#f0f0f0"
        ft = tkFont.Font(family=dfont,size=28)
        GButton_293["font"] = ft
        GButton_293["fg"] = "#000000"
        GButton_293["justify"] = "center"
        GButton_293["text"] = "↧"
        GButton_293.place(x=210,y=370,width=160,height=50)
        GButton_293["command"] = self.GButton_293_command

        GButton_949=tk.Button(root)
        GButton_949["bg"] = "#f0f0f0"
        ft = tkFont.Font(family=dfont,size=28)
        GButton_949["font"] = ft
        GButton_949["fg"] = "#000000"
        GButton_949["justify"] = "center"
        GButton_949["text"] = "↥"
        GButton_949.place(x=210,y=430,width=160,height=50)
        GButton_949["command"] = self.GButton_949_command

        GButton_754=tk.Button(root)
        GButton_754["bg"] = "#f0f0f0"
        ft = tkFont.Font(family=dfont,size=28)
        GButton_754["font"] = ft
        GButton_754["fg"] = "#000000"
        GButton_754["justify"] = "center"
        GButton_754["text"] = "↧"
        GButton_754.place(x=40,y=370,width=160,height=50)
        GButton_754["command"] = self.GButton_754_command

        GButton_572=tk.Button(root)
        GButton_572["bg"] = "#f0f0f0"
        ft = tkFont.Font(family=dfont,size=28)
        GButton_572["font"] = ft
        GButton_572["fg"] = "#000000"
        GButton_572["justify"] = "center"
        GButton_572["text"] = "↥"
        GButton_572.place(x=40,y=430,width=160,height=50)
        GButton_572["command"] = self.GButton_572_command

        GButton_490=tk.Button(root)
        GButton_490["bg"] = "#f0f0f0"
        ft = tkFont.Font(family=dfont,size=28)
        GButton_490["font"] = ft
        GButton_490["fg"] = "#000000"
        GButton_490["justify"] = "center"
        GButton_490["text"] = "↧"
        GButton_490.place(x=380,y=370,width=160,height=50)
        GButton_490["command"] = self.GButton_490_command

        GButton_567=tk.Button(root)
        GButton_567["bg"] = "#f0f0f0"
        ft = tkFont.Font(family=dfont,size=28)
        GButton_567["font"] = ft
        GButton_567["fg"] = "#000000"
        GButton_567["justify"] = "center"
        GButton_567["text"] = "↥"
        GButton_567.place(x=380,y=430,width=160,height=50)
        GButton_567["command"] = self.GButton_567_command

        GButton_415=tk.Button(root)
        GButton_415["bg"] = "#f0f0f0"
        ft = tkFont.Font(family=dfont,size=28)
        GButton_415["font"] = ft
        GButton_415["fg"] = "#000000"
        GButton_415["justify"] = "center"
        GButton_415["text"] = "↤"
        GButton_415.place(x=40,y=550,width=240,height=50)
        GButton_415["command"] = self.GButton_415_command

        GLabel_847=tk.Label(root)
        GLabel_847["bg"] = "#1e90ff"
        ft = tkFont.Font(family=dfont,size=23)
        GLabel_847["font"] = ft
        GLabel_847["fg"] = "#ffffff"
        GLabel_847["justify"] = "center"
        GLabel_847["text"] = "Linear 1"
        GLabel_847.place(x=60,y=330,width=120,height=30)

        GLabel_540=tk.Label(root)
        GLabel_540["bg"] = "#1e90ff"
        ft = tkFont.Font(family=dfont,size=23)
        GLabel_540["font"] = ft
        GLabel_540["fg"] = "#ffffff"
        GLabel_540["justify"] = "center"
        GLabel_540["text"] = "Linear 2"
        GLabel_540.place(x=230,y=330,width=120,height=30)

        GLabel_750=tk.Label(root)
        GLabel_750["bg"] = "#1e90ff"
        ft = tkFont.Font(family=dfont,size=23)
        GLabel_750["font"] = ft
        GLabel_750["fg"] = "#ffffff"
        GLabel_750["justify"] = "center"
        GLabel_750["text"] = "Linear 3"
        GLabel_750.place(x=400,y=330,width=120,height=30)

        GButton_350=tk.Button(root)
        GButton_350["bg"] = "#f0f0f0"
        ft = tkFont.Font(family=dfont,size=28)
        GButton_350["font"] = ft
        GButton_350["fg"] = "#000000"
        GButton_350["justify"] = "center"
        GButton_350["text"] = "↦"
        GButton_350.place(x=300,y=550,width=240,height=50)
        GButton_350["command"] = self.GButton_350_command

        GLabel_225=tk.Label(root)
        GLabel_225["bg"] = "#1e90ff"
        ft = tkFont.Font(family=dfont,size=23)
        GLabel_225["font"] = ft
        GLabel_225["fg"] = "#ffffff"
        GLabel_225["justify"] = "center"
        GLabel_225["text"] = "Linear 4"
        GLabel_225.place(x=230,y=510,width=120,height=30)

    def GButton_UP_command(self):
        s.write('1'.encode("ascii"))


    def GButton_DOWN_command(self):
        s.write('2'.encode("ascii"))


    def GButton_234_command(self):
        s.write('3'.encode("ascii"))


    def GButton_727_command(self):
        s.write('4'.encode("ascii"))


    def GButton_320_command(self):
        s.write('0'.encode("ascii"))
        s.close()


    def GButton_69_command(self):
        s.write('6'.encode("ascii"))


    def GButton_293_command(self):
        s.write('7'.encode("ascii"))


    def GButton_949_command(self):
        s.write('8'.encode("ascii"))


    def GButton_754_command(self):
        s.write('9'.encode("ascii"))


    def GButton_572_command(self):
        s.write('10'.encode("ascii"))


    def GButton_490_command(self):
        s.write('11'.encode("ascii"))


    def GButton_567_command(self):
        s.write('12'.encode("ascii"))


    def GButton_415_command(self):
        s.write('13'.encode("ascii"))


    def GButton_350_command(self):
        s.write('14'.encode("ascii"))



if __name__ == "__main__":
    root = tk.Tk()
    app = App(root)
    root.mainloop()