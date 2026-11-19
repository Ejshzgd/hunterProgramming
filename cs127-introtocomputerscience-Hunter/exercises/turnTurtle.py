#Name: Carey Jiang
#Email: carey.jiang65@myhunter.cuny.edu
#Date: September 30, 2024
#This program asks the user for 5 whole (integer) numbers. For each number, the turtle turns left the degrees entered and then the turtle moves forward 100 pixels.

#turtle library/module methods:
#.Turtle() ---constructor 
#.Screen ---constructor 
#.forward(int distance)
#.left(int angle)
#.exitonclick()
#int() ??? (Function perhaps)
#---
#range(), range(start,stop), range(start,stop,step)


import turtle      #importing the turtle library/module

carey = turtle.Turtle()      #constructing a turtle object called 'carey', lowerCase turtle = module , Turtle = class


for i in range (5):      #starts a for-loop at i = 0 , using the range() function till i = 5 not including 5 , highestNum = 4, iterations = 5
    deGree = int(input("Enter a number: "))      #prompts the user for a number, checks that it's an int type, then stores it in the variable 'deGree'
    carey.left(deGree)      #rotates 'carey' counter-clockwise by a specified angle, 'deGree', what the user input, in place
    carey.forward(100)      #moves'thomasH' forward by 100 pixels

turtle.Screen().exitonclick()      #constructs a screen object, keeps the window/screen open until the user clicks
