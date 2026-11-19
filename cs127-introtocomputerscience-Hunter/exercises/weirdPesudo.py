#Name: Carey Jiang
#Email: carey.jiang65@myhunter.cuny.edu
#Date: November 20, 2024
#This program implements the pseudocode below:
# for i = 90, 88, 86, 84, 82, ... ,0:
# 	Walk forward 25 steps
# 	Turn left i degrees

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


for i in range(90,0,-2):      #starts a for-loop at i = 90 , using the range() function till i = 0 not including 0, incrementing by -2 every iteration
    carey.forward(25)      #moves 'carey' forward by 25 pixels
    carey.left(i)      #rotates 'carey' counter-clockwise by a specified angle, 'i' in place


turtle.Screen().exitonclick()      #constructs a screen object, keeps the window/screen open until the user clicks


