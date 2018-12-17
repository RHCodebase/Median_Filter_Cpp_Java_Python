import time
start = time.time()
import cv2
import numpy as np
import matplotlib.pyplot as plt
import glob
import sys

png_files_array = []

for png_file in glob.glob("*.png"):
    png_files_array.append(png_file)

numOfImageFiles = len(png_files_array);
print ('\nThe variable numOfImageFiles is :', numOfImageFiles, '\n' )

endProgram = False

all_Images_matrix = np.zeros((numOfImageFiles, 557, 495, 3), dtype=np.uint8)

for i in range(numOfImageFiles):
	print ('png_files_array[',i,'] is :', png_files_array[i]  )
	if png_files_array[i].startswith('filtered'):
		print('\nIt is better to delete all the previous versions of the filtered png files')
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
					medianValue = np.median(temp_array)
					filteredImage[r][c][k] = medianValue

	# print ("outside the for loop")
	cv2.imwrite('filteredImageUsingPython.png', filteredImage)	
	print('Have a look at the image that was created called filteredImageUsingPython.png')

end = time.time() 
print("\nPS: This Python script took ", end-start, " seconds to be executed.")
############################################################################################################################
# >python RemoveTouristUsingPython_Version_1.py
# 
# The variable numOfImageFiles is : 9
# 
# png_files_array[ 0 ] is : G0010099.png
# png_files_array[ 1 ] is : G0010108.png
# png_files_array[ 2 ] is : G0010109.png
# png_files_array[ 3 ] is : G0010110.png
# png_files_array[ 4 ] is : G0010111.png
# png_files_array[ 5 ] is : G0010132.png
# png_files_array[ 6 ] is : G0010159.png
# png_files_array[ 7 ] is : G0010161.png
# png_files_array[ 8 ] is : G0010163.png
# after the first for loop and endProgram is False
# r is  0
# r is  1
# r is  2
# r is  3
# r is  4
# r is  5
# r is  6
# r is  7
# r is  8
# r is  9
# r is  10
# r is  11
# r is  12
# ...
# ...
# ...
# r is  550
# r is  551
# r is  552
# r is  553
# r is  554
# r is  555
# r is  556
# Have a look at the image that was created called filteredImageUsingPython.png
# 
# PS: This Python script took  823.5625691413879  seconds to be executed.
# 
# >
####################################################################################################
# >python RemoveTouristUsingPython_Version_1.py
# 
# The variable numOfImageFiles is : 10
# 
# png_files_array[ 0 ] is : filteredImageUsingPython.png
# 
# It is better to delete all the previous versions of the filtered png files
# before running this program
# 
# PS: This Python script took  1.4169750213623047  seconds to be executed.
# 
# >
####################################################################################################