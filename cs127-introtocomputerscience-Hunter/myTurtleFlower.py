#Name: Carey Jiang
#Email: carey.jiang65@myhunter.cuny.edu
#Date: September 10, 2024
#This program draws a flower to the screen using the pseudocode:
# Repeat 36 times: 
#   Walk forward 100 steps
#   Turn left 145 degrees 
#   Walk forward 10 steps 
#   Turn right 90 degrees 
#   Walk forward 10 steps 
#   Turn left 135 degrees 
#   Walk forward 100 steps 
         
#turtle library/module methods:
#.Turtle() ---constructor 
#.Screen ---constructor 
#.forward(int distance)
#.left(int angle)
#.right(int angle)
#.exitonclick()
#---
#range(), range(start,stop), range(start,stop,step)



import turtle      #importing the turtle library/module


thomasH = turtle.Turtle()      #constructing a turtle object called 'thomasH', lowerCase turtle = module , Turtle = class

for i in range(36):      #starts a for-loop at i = 0 , using the range() function till i = 36 not including 36 , highestNum = 35, iterations = 36
  thomasH.forward(100)      #moves 'thomasH' forward by 100 pixels
  thomasH.left(145)      #rotates 'thomasH' counter-clockwise by a specified angle, '145' in place
  thomasH.forward(10)      #moves 'thomasH' forward by 10 pixels
  thomasH.right(90)      #rotates 'thomasH' clockwise by a specified angle, '90' in place
  thomasH.forward(10)      #moves 'thomasH' forward by 10 pixels
  thomasH.left(135)      #rotates 'thomasH' counter-clockwise by a specified angle, '135' in place
  thomasH.forward(100)      #moves 'thomasH' forward by 100 pixels


turtle.Screen().exitonclick()      #constructs a screen object, keeps the window/screen open until the user clicks