#Name:  CSci 127 Teaching Staff
#Email: hunterCSci127help@gmail.com
#Date:  Fall 2017
#This program loads an image, counts the number of pixels that are
#nearly white (the fraction of red, the fraction of green, and the fraction of blue are all above 0.75) as an estimate for snow pack.

#matplotlib.plyplot methods
#plt.imread(String file)
#----

#numpy methods
#.shape[] , .shape
#---

#methods
#print(String s)
#---
#range(), range(start,stop), range(start,stop,step)


#Import the packages for images and arrays:
import matplotlib.pyplot as plt
import numpy as np


ca = plt.imread('CaliforniaDrought_02232011_md.png')   #Read in image
countSnow = 0            #Number of pixels that are almost white
t = 0.75                 #Threshold for almost white-- can adjust between 0.0 and 1.0

#For every pixel:
for i in range(ca.shape[0]):      #starts a for-loop at i = 0 , using the range() function till i = lengthOfRows not including lengthOfRows , incrementing by +1 every iteration
     for j in range(ca.shape[1]):      #starts a for-loop at j = 0 , using the range() function till j = lengthOfCols not including lengthOfCols , incrementing by +1 every iteration
          #Check if red, green, and blue are > t:
          if (ca[i,j,0] > t) and (ca[i,j,1] > t) and (ca[i,j,2] > t):
               countSnow = countSnow + 1      #if it's white, increase countSnow by 1

print("Snow count is", countSnow)      #prints out the snow cound, ',' separated by a space