#Name: Carey Jiang
#Email: carey.jiang65@myhunter.cuny.edu
#Date: December 17, 2024
#This program implements the pseudocode below:
    # 1.  Ask the user for the number of seconds until lecture starts.
    # 2.  Print out the hours until lecture (hours = seconds //3600).
    # 3.  Compute the remaining seconds (rem = seconds % 3600).
    # 4.  Print out the minutes until lecture (minutes = rem // 60).
    # 5.  Print out the remaining seconds (remSec = rem % 60).

numSec = int(input("Enter number of seconds: "))
numHou = numSec //3600
rem = numSec % 3600
numMin = rem // 60
remSec = rem % 60

print("Hours: " , numHou)
print("Minutes: " , numMin)
print("Seconds: " , remSec)