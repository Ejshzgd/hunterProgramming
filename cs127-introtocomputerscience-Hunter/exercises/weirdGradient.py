#Name: Carey Jiang
#Email: carey.jiang65@myhunter.cuny.edu
#Date: September 25, 2024
#This program displays different shades of a color

#turtle library/module methods:
#.Turtle() ---constructor 
#.Screen ---constructor 
#.backward(int distance)
#.colormode(int RBGColorScale) Mode1: 0.0-1.0 , Mode2: 0-255
#.forward(int distance)
#.pensize(int size)
#.color() --> literal color: 'red' , hex value: #00FF00 , RGB tuple (int red, int green, int blue)
#.exitonclick()
#---
#range(), range(start,stop), range(start,stop,step)


import turtle      #importing the turtle library/module

carey = turtle.Turtle()       #constructing a turtle object called 'carey', lowerCase turtle = module , Turtle = class
turtle.colormode(255)     #sets the colormode to 0-255, by default it's set to 0.0-1.0
carey.backward(100)      #moves 'carey' backward by 100 pixels


for i in range(0, 260, 10):      #starts a for-loop at i = 0 , using the range() function till i = 260 not including 260 , incrementing by +10 every iteration, highestNum = 250, iterations = 26 (highestNum/step)
    carey.forward(10)      #moves 'carey' forward by 10 pixels
    carey.pensize(i)      #scale up the size of 'carey', the cursor, by i
    carey.color(0,0,i)      #set the color of 'carey' to have no red, green, i # of blue

turtle.Screen().exitonclick()      #constructs a screen object, keeps the window/screen open until the user clicks