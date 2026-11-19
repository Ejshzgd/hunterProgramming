#Name: Carey Jiang
#Email: carey.jiang65@myhunter.cuny.edu
#Date: December 18, 2024
#This program reads a csv file and prints out the top 10 worst offenders
import pandas as pd

csvFile = input('Enter CSV file name: ')         #Name of the CSV file
tickets = pd.read_csv(csvFile)     #Read in the file to a dataframe
attributeData = input('Enter attribute: ')
print("The 10 worst offenders are:")
print(tickets[attributeData].value_counts()[:10]) #Print out the dataframe