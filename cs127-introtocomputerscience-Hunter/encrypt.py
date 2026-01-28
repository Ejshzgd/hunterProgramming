#Name: Carey Jiang
#Email: carey.jiang65@myhunter.cuny.edu
#Date: October 9, 2024
#This program asks the user for a word and then encrypts it in Caesar Cipher

#methods:
#input(String s)
#print(String s)
#len(String s)
#ord(String s)
#---
#range(), range(start,stop), range(start,stop,step)

startTerm = input("Enter a word: ")      #prompts the user for a word and stores it in the variable 'startTerm'
endTerm = ""      #creates a variable called 'endTerm' and stores the string ''

for i in range(len(startTerm)):      #starts a for-loop at i = 0 , using the range() function till i = lengthOfTheWord not including lengthOfTheWord , incrementing by +1 every iteration
    oneLetter = startTerm[i:i+1]      #slice up 'startTerm' to individual letters, starting from the front to the last letter
    digLetter = ord(oneLetter)+13      #takes the corresponding int ASCII value of that letter and add 13 to it

    if(digLetter > 122):      #assuming that the input is a lowercase word and not symbols, if the ASCII value is greater than 122 --> it's not within a-z anymore
        digLetter -= 26      #subtracts 26 in order to wrap back to a if the letter is z, -26 instead of -27 is to account for 'a' because going to also 'a' space
    
    endTerm += chr(digLetter)      #takes the corresponding chr ASCII value and adds/ concatenate it to 'endterm'

print(endTerm)      #print out 'endTerm'