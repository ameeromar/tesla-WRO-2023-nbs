import os,time
import cv2 
import numpy as np
import serial 
import RPI.GPIO as GPIO

focal_length = 100

GPIO.setmode(GPIO.BOARD)
port=serial.Serial("/dev/ttyAMAD",baudrate=9600,timeout=0.5)

object_size = 10  
green_distance=1
red_distance=1

cap = cv2.VideoCapture(0)

if not cap.isOpened():
    raise Exception("Error opening the camera. Make sure your camera is connected and working.")

while True:
    ret, frame = cap.read()

    if not ret:
        break

    hsv_frame = cv2.cvtColor(frame, cv2.COLOR_BGR2HSV)
    
    centroid_frame = frame.copy()        
    
    lower_red1 = np.array([0, 120, 70])    
    upper_red1 = np.array([10, 255, 255])

    lower_red2 = np.array([170, 120, 70]) 
    upper_red2 = np.array([180, 255, 255])

    lower_green = np.array([65, 139, 54])  
    upper_green = np.array([10, 255, 255])

    lower1_green =np.array([9, 117, 50])
    upper1_green =np.array([180, 255 ,255])
    
    mask1_green = cv2.inRange(hsv_frame, lower1_green, upper1_green)
    mask2_green = cv2.inRange(hsv_frame, lower_green, upper_green)
    
    mask_green = cv2.bitwise_or(mask1_green,mask2_green)
    
    contours_green, _ = cv2.findContours(mask_green, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)
    
    if contours_green:
        cnt_green = max(contours_green, key=cv2.contourArea)
        M_green = cv2.moments(cnt_green)
        if M_green['m00'] != 0:
            cx_green = int(M_green['m10'] / M_green['m00'])
            cy_green = int(M_green['m01'] / M_green['m00'])
            green_apparent_size = cv2.contourArea(cnt_green)
            green_distance = (focal_length * object_size) / green_apparent_size

            centroid_frame = frame.copy()
            cv2.drawContours(centroid_frame, [cnt_green], -1, (0, 255, 0), 2)
            cv2.circle(centroid_frame, (cx_green, cy_green), 5, (0, 0, 255), -1)
            cv2.putText(centroid_frame, f"Red Distance: {red_distance:.2f} units", (10, 60), cv2.FONT_HERSHEY_SIMPLEX, 1, (0, 0, 255), 2)
            cv2.putText(centroid_frame, f"Green Distance: {green_distance:.2f} units", (10, 30), cv2.FONT_HERSHEY_SIMPLEX, 1, (0, 255, 0), 2)
    
    mask_red1 = cv2.inRange(hsv_frame, lower_red1, upper_red1)
    mask_red2 = cv2.inRange(hsv_frame, lower_red2, upper_red2)
    mask_red = cv2.bitwise_or(mask_red1, mask_red2)
    contours_red, _ = cv2.findContours(mask_red, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)
    
    if contours_red:
        cnt_red = max(contours_red, key=cv2.contourArea)
        M_red = cv2.moments(cnt_red)
        if M_red['m00'] != 0:
            cx_red = int(M_red['m10'] / M_red['m00'])
            cy_red = int(M_red['m01'] / M_red['m00'])
            red_apparent_size = cv2.contourArea(cnt_red)
            red_distance = (focal_length * object_size) / red_apparent_size
            
            centroid_frame = frame.copy()
            cv2.drawContours(centroid_frame, [cnt_red], -1, (0, 0, 255), 2)
            cv2.circle(centroid_frame, (cx_red, cy_red), 5, (0, 255, 0), -1)
            cv2.putText(centroid_frame, f"Red Distance: {red_distance:.2f} units", (10, 60), cv2.FONT_HERSHEY_SIMPLEX, 1, (0, 0, 255), 2)
            cv2.putText(centroid_frame, f"Green Distance: {green_distance:.2f} units", (10, 30), cv2.FONT_HERSHEY_SIMPLEX, 1, (0, 255, 0), 2)
    
    cv2.imshow('Live Video with Object Centroids and Distances', centroid_frame)
    
    if cv2.waitKey(1) & 0xFF == ord('q'):  # Press 'q' to exit
        break
    
    if not ret:
        break
    
    if 0.00 < red_distance < 0.05:
        print (red_distance)
        print("Red go right===========")
        port.write('r')
    
    if  0.00 < green_distance < 0.05:
        port.write('g')
        print(green_distance)
        print("Green go lift=========")
    
    # cap.release()
    # cv2.destroyAllWindows()

cap.release()
cv2.destroyAllWindows()
