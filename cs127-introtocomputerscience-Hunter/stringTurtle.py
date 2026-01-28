#Author:    Katherine St. John
#Date:      August 2014
#A program that uses command strings to control turtle drawing
#Modified by:  Carey Jiang
#Date:      November 4, 2024

#turtle library/module methods:
#.Turtle() ---constructor 
#.Screen ---constructor 
#.forward(int distance)
#.left(int angle)
# .right(int angle)
# .penup()
# .pendown()
# .backward(int distance)
# .stamp()
#.color() --> literal color: 'red' , hex value: #00FF00 , RGB tuple (int red, int green, int blue)
#.exitonclick()
#---
#print(String s)
#range(), range(start,stop), range(start,stop,step)


import turtle      #importing the turtle library/module

tess = turtle.Turtle()      #constructing a turtle object called 'tess', lowerCase turtle = module , Turtle = class
myWin = turtle.Screen()     #constructs a screen and saves it to the variable 'myWin', The graphics window
commands = input("Please enter a command string: ")       #prompts the user for a string and stores it in the variable 'commands'


for ch in commands:      #starts a for-loop at ch = firstLetterInCommands , using the range() function till i = lastLetterInCommands not including the lastLetterInCommands, there's always an empty space at the very end
    #perform action indicated by the character
    if ch == 'F':            #move forward 50 pixels
        tess.forward(50)
    elif ch == 'L':          #turn left 90 degrees
        tess.left(90)
    elif ch == 'R':          #turn right 90 degrees
        tess.right(90)
    elif ch == '^':          #lift pen
        tess.penup()
    elif ch == 'v':          #lower pen
        tess.pendown()
    elif ch == 'B':          #move backward 50 pixels
        tess.backward(50)    
    elif ch == 'S':          #leave a stamp
        tess.stamp()
    elif ch == 'l':          #turn left 45 degrees
        tess.left(45)
    elif ch == 'r':          #turn right 45 degrees
        tess.right(45)
    elif ch == 'p':          #change 'tess' color to purple
        tess.color("purple")
    else:                   #for any other character, print an error message 
        print("Error: do not know the command:", ch) #typo, was c before

print("See graphics window for your image")    #print statement to let the user know that the graphics window updated
myWin.exitonclick()         #Close the window when clicked




