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



# Program arrangement and Algorithm Planning

The robot is running on an ESP32-based development board called the JRC board locally made in our country to run all the actuators and sense the environment. It is using the Huskylens to see the red/green obstacles as well as the corner lines (blue/orange). An MPU6050 gyroscope and accelerometer sensor are used to detect the orientation of the robot and count laps.

When the robot is first powered on with the battery, it initializes the chip and starts communicating with the Huskylens and IMU sensor. Once it is ready, the servo motor gets centered and it waits for the user to push the button. The code is then divided into three major parts - 

### Part 1 - Detecting run direction:

The first part determines the direction of the robot run. The robot moves slowly through the first straightforward section to ensure it can safely detect the direction of the run with its sonar sensors. Once it detects a large distance (>90cm) from one of the sensors, it marks the direction as “L” - clockwise, or “R”  - anti-clockwise accordingly.

### Part 2 - Completing the run as fast as possible:

In this part, we run a PID loop (1st round) or a proportional+obstacle avoiding code(2nd round) to complete the run as fast as possible. 

### **Wall avoidance:**

In the first round, we only check the sonar on the inner wall side (based on the direction of run detected from Part 1) to run a PID (proportional, integral, derivative) code. The code tries to keep the robot at a fixed distance from the wall while slowing down the rear axle drive motor whenever a turn is initiated.
To complete this part as fast as possible, we use smart algorithms to detect when the robot has just finished a turning section and is about to enter a straight section. The robot then spins the drive motor at maximum speed for a short period of time (40-50mS) to give the robot a great acceleration or “boost”.

In the 2nd round, however, we decided to disable the boost and changed PID control to just P or proportional to keep the robot centered on the track, which is sufficient at the slow speed of the robot.

### **Obstacle avoidance:**

When the huskylens detects an object, the ESP32 gets the object's color and location in the X and Y axis, as well as its height (to get the distance). The robot then follows the obstacle with an offset. Meaning it follows slightly on the right side of red obstacles, and slightly to the left of green obstacles. And once it reaches a distance of less than 30 cm, it turns the front wheel proportionally to the distance of the object (calculated from height) and the position of the object on the screen's horizontal axis.

### Wall collision protection:

If the robot detects a wall within 8cm of one of the sides, it rotates the servo in the other direction for a few milliseconds to keep the robot from hitting the wall.

### Part 3 - Detecting the end of 3 laps:

The robot equips a gyroscope sensor to measure the yaw angle by integrating the rotational acceleration values on the Z axis over time. Gyroscope sensors are infamous for drift in the angle over time, but our robot runs for such a short time that it does not affect its performance.

When the start button is pressed, the robot is at a zero-degree angle starting position. After each lap of the track, the robot spins 360 degrees. So we can detect the completion of three laps as soon as the robot completes 3x360 or 1080 degrees turn (+/- 20 degrees to compensate for errors). 
However, the robot is not instantly stopped, since it may not have reached the straightforward section. We start waiting for the Huskylens to detect a blue or orange line in front of it and stop instantly with a short backward pulse to the drive motor (hard break).

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


