# Engineering Documentation | Team Tesla | Palestine
----

This repository contains the engineering materials, software codebase, and documentation for "Tesla," our autonomous self-driving car model.Tesla is built by our Team  and its our entry into the World Robot Olympiad (WRO) for the 2023 season.

----

## Team Members:

- Hamed Swaiseh - email: <Hamed7710@gmail.com>
- Ameer Omar - email: <mo858769@gmail.com>
- Ibraheem Bishtawi - email: <bishtawi.ibrahim@gmail.com>
- Ameed duboos - email: <ameed.dabous@gmail.com>

----

## Repository Overview


+ `chassis` - this folder contains details of the chassis that we've used
+ `schemes` - contains the electrical systems schematics 
+ `src` - contains the main programs and control software and 
+ `t-photos` - contains one serious and one funny photo
+ `v-photos` - contains the photos of the robot from all required directions
+ `video` - contains youtube link of the video where you can see our robot in action
+ `others` - other essential photos

----
## Part 1 - Program Arrangement and Algorithm Planning:
Imports and Libraries:

The code starts by importing necessary libraries for both Arduino (Servo) and Raspberry Pi (OpenCV, NumPy, serial communication, and GPIO).
Variable Initialization:

Various variables and constants are initialized, including pins for motors, ultrasonic sensors (trigPin and echoPin), motor speed, and safe distances for obstacle avoidance.
Setup Function:

In the setup function, the code initializes the Arduino components, such as servo motor, pins, and serial communication. It also initializes the Raspberry Pi camera using OpenCV.
Loop Function:

The loop function continuously measures distances from ultrasonic sensors and performs obstacle avoidance.



----
## Part 2 - Detecting Run Direction:
getDistance Function:

This function is responsible for measuring distances using an ultrasonic sensor. It sends a trigger signal, calculates the time it takes for the echo signal to return, and converts this time into a distance measurement.
moveForward, moveLeft, moveRight Functions:

These functions control the robot's movements: forward, left, and right. They adjust the motor pins and servo angle to navigate the robot accordingly.
obstacleAvoidance Function:

This function contains the logic for obstacle avoidance. It checks distances in front, left, and right of the robot and determines whether to move forward, turn left, or turn right based on safe distances and detected obstacles.


----
## Part 3 - Completing the Run as Fast as Possible:
Image Processing with Raspberry Pi:

The Raspberry Pi section of the code captures frames from the camera and processes them to detect red and green objects. It uses OpenCV to perform color segmentation and find contours of these objects.
Centroid Calculation and Distance Estimation:

The code calculates the centroid (center of mass) of detected red and green objects. It also estimates their distances based on apparent size and the focal length of the camera.
Displaying Object Centroids and Distances:

The code displays the live video feed with object centroids and estimated distances on the screen. It differentiates between red and green objects and displays their distances.
Serial Communication with Arduino:

If the code detects objects within a certain distance range (0.00 < distance < 0.05), it sends commands ('r' for red and 'g' for green) to the Arduino via serial communication to instruct the robot to take a specific action (e.g., turn left or right).
Cleanup and Exiting:

The code handles cleanup by releasing the camera and closing OpenCV windows when the 'q' key is pressed.
This code effectively combines Arduino and Raspberry Pi to create a robot that can autonomously navigate while detecting and responding to objects in its environment. The robot avoids obstacles and follows a path based on the colors of the objects it detects.







----



# Electrical Systems Design

We've carefully selected the best possible parts for our robot after several hundred hours of R&D and have tried to achieve highest possible efficiency and reliability. The electrical systems design is explained in the following paragraph.

## Parts List

+ Adafruit HC-SR04 Ultrasonic Sensors
+ DC Motor
+ MG90S servo Motor
+ L298 Motor Driver
+ 12 v , ?? A Bettary
+ power bank 10k m.A
+ 2* arduino uno
+ raspberry pi 4 8gb
+ raspberry cam
+ rc car

## Design decisions

+  



----


# Mechanical Design

We're using a ready made Ackermann based chassis kit from YF robot and have significantly modified each aspect of the chassis. The chassis base plate is made of Aluminum and the rest of the parts involve brass spacers, acrylic top plates, front articulating axel parts and some other miscellaneous parts. We've also designed and 3D Printed some parts for making our chassis more practical.

## Design Decisions
We setteled on the YF Robot chassis because it provided a robust platform to work on and featured ackermann steering mechanism. We've deigned and 3D printed some parts which were required for the optimal operation of the robot. 


