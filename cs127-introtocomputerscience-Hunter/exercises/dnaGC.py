#Name: Carey Jiang
#Email: carey.jiang65@myhunter.cuny.edu
#Date: October 28, 2024
#This program prompts the user for a DNA string, and then prints the length and GC-content of that string.
#These strings are made up of the letters A, C, G, and T. For a given DNA string, the GC-content is the percent of the string that is C or G, written as a decimal.

# methods:
# input(String s)
# print(String s)
# float()


dnaString = input("Enter a DNA string: ")      #prompts the user for a DNA string and stores it in the variable 'dnaString'

countGC = 0      #creates a variable 'countGC' and set it to 0
lengthOfDNA = len(dnaString)      #creates a variable 'lengthOfDNA' and store it's length


for i in dnaString:      #starts a for-loop at i = the first letter of the dnaString , using the range() function till i = last number of dnaString not including the last, there's always an empty space at the very end
    if i == "C" or i == "G":      #if the letter == 'C' or letter == 'G'
        countGC+=1      #increase countGC by 1

print("Length is " , lengthOfDNA)      #print the length of lengthOfDNA, ',' separated by a space
print("GC-content is " , float(countGC/lengthOfDNA))      #find the percentage of GC content as a decimal, checks that it's a float, and prints it out, ',' separated by a space
    