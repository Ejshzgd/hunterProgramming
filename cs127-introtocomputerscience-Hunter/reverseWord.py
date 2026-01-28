#Name: Carey Jiang
#Email: carey.jiang65@myhunter.cuny.edu
#Date: September 30, 2024
#This program asks the user for a message then prints out that message in reverse twice per line.

#methods:
#input(String s)
#print(String s)
#len(String s)
#---
#range(), range(start,stop), range(start,stop,step)



ogWord = input("Enter a message: ")      #prompts the user for a message and stores it in the variable 'ogWord'


for i in range(len(ogWord) , 0 , -1):      #starts a for-loop at i = lengthOfTheWord , using the range() function till i = 0 not including 0 , incrementing by -1 every iteration
    revWord = ogWord[i-1:i]      #slice ogWord into substrings of individual letters, taking from the back going forward, and stores it to revWord
    print(revWord + " " + revWord)      #prints 'revWord' twice with a space in between then skips a line
