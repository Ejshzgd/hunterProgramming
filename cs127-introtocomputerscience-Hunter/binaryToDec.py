#Name: Carey Jiang
#Email: carey.jiang65@myhunter.cuny.edu
#Date: December 17, 2024
#This program implements the pseudcode below:
#  Ask user for input, and store in the string, binString.
#     Set decNum = 0.
#     For each c in binString,
#         decNum = decNum * 2
#         if c is 1, then
#             decNum = decNum + 1
#     Print decNum

binString = input("Enter binary number: ")
decNum = 0

for i in binString:
    decNum = decNum*2
    if i == "1":
        decNum = decNum + 1

print("Your number in decimal is " , decNum)

		