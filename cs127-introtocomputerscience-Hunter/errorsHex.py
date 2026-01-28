#Name: Carey Jiang
#Email: carey.jiang65@myhunter.cuny.edu
#Date: December 18, 2024
#This program fixes the errors

def convert(s):
    """ Takes a hex string as input.
    Returns decimal equivalent.
    """

    total = 0

    for c in s:
        total = total * 16  # Shift left (multiply by 16)

        ascii_val = ord(c)  # Get the ASCII value of the character

        # Check if the character is a decimal digit (0-9)
        if ord('0') <= ascii_val <= ord('9'):
            total = total + ascii_val - ord('0')
        
        # Check if the character is an uppercase hex digit (A-F)
        elif ord('A') <= ascii_val <= ord('F'):
            total = total + ascii_val - ord('A') + 10
        
        # Check if the character is a lowercase hex digit (a-f)
        elif ord('a') <= ascii_val <= ord('f'):
            total = total + ascii_val - ord('a') + 10
        
        else:
            # If the character is not a valid hex digit
            return -1  # Return -1 to indicate an invalid input
    
    return total

def main():
    hexString = input("Enter a number in hex: ")  # Corrected input prompt
    print("The number in decimal is", convert(hexString))  # Corrected print statement

# Allow script to be run directly:
if __name__ == "__main__":
    main()
