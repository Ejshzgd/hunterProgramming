#Name: Carey Jiang
#Email: carey.jiang65@myhunter.cuny.edu
#Date: September 25, 2024
#This program implement the pseudocode:
# For i = 5, 10, 15, 20, 25, ... ,300:
#     Walk forward i steps
#     Turn left 91 degrees

#turtle library/module methods:
#.Turtle() ---constructor 
#.Screen ---constructor 
#.forward(int distance)
#.left(int angle)
#.exitonclick()
#---
#range(), range(start,stop), range(start,stop,step)


import turtle      #importing the turtle library/module

carey = turtle.Turtle()      #constructing a turtle object called 'carey', lowerCase turtle = module , Turtle = class

for i in range (5, 305, 5):      #starts a for-loop at i = 5 , using the range() function till i = 305 not including 305 , incrementing by +5 every iteration, highestNum = 300 , iterations = 60 (highestNum/step)
    carey.forward(i)       #moves 'carey' forward by i pixels
    carey.left(91)       #rotates 'carey' counter-clockwise by a specified angle, '91' in place

turtle.Screen().exitonclick()      #constructs a screen object, keeps the window/screen open until the user clicks