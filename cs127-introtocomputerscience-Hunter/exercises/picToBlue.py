#Name: Carey Jiang
#Email: carey.jiang65@myhunter.cuny.edu
#Date: November 13, 2024
#This program takes an image, loads and displays it, and then saves a new image with only the blue channel

# methods:
# plt.imread(String s)
# plt.imshow()
# plt.show()
# plt.imsave(String nameOfOutputFile, String theImage)
# ---
# input(String s)

import matplotlib.pyplot as plt
import numpy as np

inFile = input("Enter name of the input file:  ")    #Takes an image
outFile = input("Enter name of the output file:  ")  #Outputs the saved image

inFile = 'csBridge.png'      #csBridge.png

img = plt.imread(inFile)      #Takes an .png image
plt.imshow(img)                      #Loads the image into plt
plt.show()                           #Shows the image to the screen

img[:,:,0] = 0                      #Set the red channel to 0
img[:,:,1] = 0                      #Set the green channel to 0


plt.imsave(outFile, img)        #Saves img as outFile