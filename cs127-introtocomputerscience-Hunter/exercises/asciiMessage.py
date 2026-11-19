#Name: Carey Jiang
#Email: carey.jiang65@myhunter.cuny.edu
#Date: September 19, 2024
#This program prints the message based on the ASCII table

#methods:
#input(String s)
#print(String s)
#len(String s)
#ord(String s)
#---
#range(), range(start,stop), range(start,stop,step)


askMessage = input("Enter a phrase: ")        #prompts the user for a message and stores it in the variable 'askMessage'
print("In ASCII:")      #prints 'In ASCII:' to the terminal

for i in range(len(askMessage)):      #starts a for-loop at i = 0 , using the range() function till i = length of the message not including length , highestNum = lengthOfMessage-1, iterations = lengthOfMessage
    print(ord(askMessage[i:i+1]))      #breaks up the message into substrings/ indivudal letters, uses the ord() function to get it's ASCII value, prints it and then skips a line


