#Name: Carey Jiang
#Email: carey.jiang65@myhunter.cuny.edu
#Date: September 9, 2024
#This program draws an Octagon using the turtle library.

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

for i in range(8):      #starts a for-loop at i = 0 , using the range() function till i = 8 not including 8 , highestNum = 7, iterations = 8
  thomasH.forward(50)      #moves'thomasH' forward by 50 pixels
  thomasH.left(360/8)      #rotates 'thomasH' counter-clockwise by a specified angle, '360/8' in place



turtle.Screen().exitonclick()      #constructs a screen object, keeps the window/screen open until the user clicks

