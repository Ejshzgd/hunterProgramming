#Name: Carey Jiang
#Email: carey.jiang65@myhunter.cuny.edu
#Date: December 17, 2024
#This programs creates a blue 'C' logo for CUNY on a 30x30 grid.

# methods:
# np.zeros()---> int tuple
# plt.imsave()


import matplotlib.pyplot as plt 
import numpy as np 

img = np.zeros((30,30,3))      #creates a 30x30 numpy array with RGB colors
img[:10,:,2] = 1      #color the top part blue
img[20:,:,2] = 1      #color the bottom part blue
img[10:20,:10,2] = 1      #color the most left part blue
img[10:20,10:,:] = 1      #color the remaining spaces white

plt.imsave("logo.png", img)      #saves img as 'logo.png'