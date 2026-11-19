#Name: Carey Jiang
#Email: carey.jiang65@myhunter.cuny.edu
#Date: December 18, 2024
#This program only allows the user to type a non-negative number


x = int(input(""))

while(x < 0):
    x = int(input("Negative number.  Try again: "))
print(x)