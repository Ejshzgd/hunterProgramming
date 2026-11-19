#Name: Carey Jiang
#Email: carey.jiang65@myhunter.cuny.edu
#Date: September 16, 2024
#This program draws a star to the screen

#turtle library/module methods:
#.Turtle() ---constructor 
#.Screen ---constructor 
#.forward(int distance)
#.left(int angle)
#.exitonclick()
#---
#range(), range(start,stop), range(start,stop,step)


import turtle      #importing the turtle library/module


thomasH = turtle.Turtle()      #constructing a turtle object called 'thomasH', lowerCase turtle = module , Turtle = class

for i in range(5):      #starts a for-loop at i = 0 , using the range() function till i = 5 not including 5 , highestNum = 4, iterations = 5
  thomasH.forward(100)  #moves'thomasH' forward by 100 pixels
  thomasH.left(720/5)   #rotates 'thomasH' counter-clockwise by a specified angle, '720/5' in place



turtle.Screen().exitonclick()      #constructs a screen object, keeps the window/screen open until the user clicks