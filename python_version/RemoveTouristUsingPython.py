import cv2
import numpy as np
import matplotlib.pyplot as plt
import glob
import sys

png_files_array = []

for png_file in glob.glob("*.png"):
    png_files_array.append(png_file)

numOfImageFiles = len(png_files_array);
print ('\nnumOfImageFiles is :', numOfImageFiles, '\n' )

endProgram = False

all_Images_matrix = np.zeros((numOfImageFiles, 557, 495, 3), dtype=np.uint8)

for i in range(numOfImageFiles):
	print ('png_files_array[',i,'] is :', png_files_array[i]  )
	if png_files_array[i].startswith('filtered'):
		print('It is better to delete all the previous versions of the filtered png files')
		print('before running this program' )
		endProgram = True
		break
				 			 
	if numOfImageFiles < 3:
		print('You need more than 3 png images files')
		endProgram = True
		break


    # img = cv2.imread('G0010099.png', cv2.IMREAD_COLOR)
	img = cv2.imread(png_files_array[i], cv2.IMREAD_COLOR)

    # print(img)
    # print("img[556][493]    is ", img[556][493])
    # print("img[556][493][2] is ", img[556][493][2])

	for r in range(557):
		for c in range(495):
			for k in range(3):
				all_Images_matrix[i][r][c][k] = img[r][c][k]
				# print ("i is ", i, "r is ", r, "c is ", c, "k is ", k, "all_Images_matrix[i][r][c][k] is ", all_Images_matrix[i][r][c][k])        

if endProgram == False:
	print('after the first for loop and endProgram is False' )

	filteredImage = np.zeros((557, 495, 3), dtype=np.uint8)
	
	for r in range(557):       
		print ("r is ", r)
		for c in range(495):               
			for k in range(3):	
				temp_array = []
				for i in range(numOfImageFiles):
					#print ("i is ", i, "r is ", r, "c is ", c, "k is ", k, "all_Images_matrix[i][r][c][k] is ", all_Images_matrix[i][r][c][k])        
					temp_array.append(all_Images_matrix[i][r][c][k])										
					median_of_temp_array = np.median(temp_array)
					filteredImage[r][c][k] = median_of_temp_array

	# print ("outside the for loop")
	cv2.imwrite('filteredImageUsingPython.png', filteredImage)	
  
#print(mynmatrix)
print('Have a look at the image that was created called filteredImageUsingPython.png')

# > python RemoveTouristUsingPython.py