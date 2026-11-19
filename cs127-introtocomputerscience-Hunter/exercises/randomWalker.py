#Name: Carey Jiang
#Email: carey.jiang65@myhunter.cuny.edu
#Date: December 1, 2024
#This program makes a turtle walk 100 times and turn left a random number of degrees ranging from 0-360, incriminating by 10



import turtle
import random


carey = turtle.Turtle()
newWind = turtle.Screen()
carey.speed(10)

for i in range(100):
  carey.forward(30)
  a = random.randrange(0,350,10)
  print(a , end="\n")
  carey.left(a)

newWind.exitonclick()