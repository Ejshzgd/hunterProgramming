#Name: Carey Jiang
#Email: carey.jiang65@myhunter.cuny.edu
#Date: October 21, 2024
#This program asks the user for the number of hours till weekend. Then, it takes the number and converts it to days and the remanining hours

#methods:
#input(String s)
#print(String s)
#int() ??? function perhaps 


hoursTillWeekend = int(input("Enter number of hours:  "))      #prompts the user for the number of hours till weekend, checks that it's an int type, and stores it in the variable 'hoursTillWeekend'

days = int(hoursTillWeekend/24)      #divides hours by 24, checks that it's an int type so no decimal, to get the number of days and stores it in 'days'
hours = hoursTillWeekend%24      #mod hours by 24 to get the remainder/remaining hours, to get the remanining hours and stores it in 'hours'

print("Days: " , days)      #prints remaining days
print("Hours: ", hours)      #print remanining hours on a separate line