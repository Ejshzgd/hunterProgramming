#Name: Carey Jiang
#Email: carey.jiang67@myhunter.cuny.edu
#Date: November 20, 2024
#This program loads and reads a .csv file and computes the minimum, average, and maximum population over time for a borough (entered by the user)

import pandas as pd         #Used for data manipulation 
import matplotlib as plt    #Loading files and visualization 

nycPopFile = pd.read_csv('nycHistPop.csv' , header=5)
boroughName = input("Enter borough: ")

borValue = nycPopFile[boroughName]

minValue = borValue.min()
avgValue = borValue.mean()
maxValue = borValue.max()

print("Minimum population:  " , minValue)
print("Average population:  " , avgValue)
print("Maximum population:  " , maxValue)

