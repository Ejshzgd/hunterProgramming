#Name: Carey Jiang
#Email: carey.jiang65@myhunter.cuny.edu
#Date: December 17, 2024
#This program asks ask the user for the borough, an name for the output file, and then display the fraction of the population that has lived in that borough, over time.

borName = input("Enter borough name: ")
outName = input("Enter output file name: ")

import matplotlib.pyplot as plt
import pandas as pd

pop = pd.read_csv('nycHistPop.csv',skiprows=5)
print(pop)
pop['Fraction'] = pop[borName]/pop['Total']
pop.plot(x="Year" , y = 'Fraction')

fig = plt.gcf()
fig.savefig(outName)