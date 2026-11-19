#Name: Carey Jiang
#Email: carey.jiang65@myhunter.cuny.edu
#Date: November 20, 2024
#The programs modifys the region of the map with elevation greater than 6 feet and less than or equal 20 feet above sea level to the color grey


# methods:
# np.loadtxt(String file)
# .shape
# np.zeros(shape)
# plt.imshow
# plt.show()
# plt.imsave()
# ---
# input(String s)


#Import the libraries for arrays and displaying images:
import numpy as np
import matplotlib.pyplot as plt


#Read in the data to an array, called elevations:
elevations = np.loadtxt('elevationsNYC.txt')

#Take the shape (dimensions) of the elevations
#  and add another dimension to hold the 3 color channels:
mapShape = elevations.shape + (3,)

#Create a blank image that's all zeros:
floodMap = np.zeros(mapShape)

amountBlue = float(input("How blue is the ocean:  "))
outFile = input("What is the output file:  ")

for row in range(mapShape[0]):
    for col in range(mapShape[1]):
        if elevations[row][col] <= 0:
            floodMap[row,col,0:2] = 0
            floodMap[row,col,2] = amountBlue
        elif elevations[row][col] % 10 == 0:
            floodMap[row,col,:] = 0
        else:
            floodMap[row,col,:] = 1


# Load the flood map image into matplotlib.pyplot:
plt.imshow(floodMap)

# Display the plot:
plt.show()

#Save the image:
plt.imsave(outFile, floodMap)

print("Thank you for using my program!" + "\n" + "Your map is stored " + outFile)