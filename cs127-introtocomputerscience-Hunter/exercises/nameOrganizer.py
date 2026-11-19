#Name: Carey Jiang
#Email: carey.jiang65@myhunter.cuny.edu
#Date: December 17, 2024
#This program prompts the user to enter a list of names. 
# Each person's name is separated from the next by a semi-colon and a space ('; ') and the names are entered lastName, firstName (i.e. separated by ', '). 
# The program should then print out the names, one per line, with the first initial of the first name, followed by ".", and followed by the last name.

allNames = " " + input("Please enter your list of names:  ")

nameList = allNames.split(";")

print("\n" + "You entered:" + "\n")

for i in range(len(nameList)):
    indvNameList = nameList[i].split(",")
    print(indvNameList[1][1:2] + "." + indvNameList[0])

print("\n" + "Thank you for using my name organizer!")