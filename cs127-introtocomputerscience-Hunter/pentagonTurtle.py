#Name: Carey Jiang
#Email: carey.jiang65@myhunter.cuny.edu
#Date: September 30, 2024
#This program draws a cornflower blue pentagon 

#turtle library/module methods:
#.Turtle() ---constructor 
#.Screen ---constructor 
#.colormode(int RBGColorScale) Mode1: 0.0-1.0 , Mode2: 0-255
#.forward(int distance)
#.left(int angle)
#.stamp()
#.exitonclick()
#---
#range(), range(start,stop), range(start,stop,step)


import turtle      #importing the turtle library/module

carey = turtle.Turtle()      #constructing a turtle object called 'carey', lowerCase turtle = module , Turtle = class
turtle.colormode(255)      #sets the colormode to 0-255, by default it's set to 0.0-1.0
carey.shape("turtle")      #sets the turtle cursor to a turtle shape
carey.color("cornflowerblue")      #sets 'carey' to color 'cornflowerblue'


for i in range (5):      #starts a for-loop at i = 0 , using the range() function till i = 5 not including 5 , incrementing by +1 every iteration, highestNum = 4 , iterations = 5 (highestNum/step)
    carey.forward(100)      #moves 'carey' forward by 100 pixels
    carey.left(360/5)      #rotates 'carey' counter-clockwise by a specified angle, '360/5' in place
    carey.stamp()      #leaves a stamp image of a turtle

turtle.Screen().exitonclick()      #constructs a screen object, keeps the window/screen open until the user clicks
