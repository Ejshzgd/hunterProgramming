#Name: Carey Jiang
#Email: carey.jiang65@myhunter.cuny.edu
#Date: September 25, 2024
#This program sets the turtle cursor to be a turtle, prompts the user for a hexValue

#turtle library/module methods:
#.Turtle() ---constructor 
#.Screen ---constructor 
#.shape(String s)
#input()
#.color() --> literal color: 'red' , hex value: #00FF00 , RGB tuple (int red, int green, int blue)
#.exitonclick()


import turtle      #importing the turtle library/module

carey = turtle.Turtle()      #constructing a turtle object called 'carey', lowerCase turtle = module , Turtle = class
carey.shape("turtle")      #sets the shape of the turtle cursor to be a turtle

favColor = input("Enter a hex string:  ")      #prompts the user for a hex value in String format and stores it in the variable 'favColor'

carey.color(favColor)      #sets the color of 'carey' using 'favColor' or the hexValue the user entered 

turtle.Screen().exitonclick()      #constructs a screen object, keeps the window/screen open until the user clicks


