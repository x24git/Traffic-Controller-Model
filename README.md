# Introduction and Background
I decided to create a system that simulates a four-way traffic intersection. I sought to develop a circuit-based system that replicate aspects of everyday four-way traffic light intersections, such red, yellow, and green lights that transition appropriately to avoid collisions. In addition, I set out to include features such as vehicular detection, in order to notify the lights to switch to green for a particular direction of the four-way intersection, and emergency vehicle detection, in order to signal all lights to turn to red to simulate emergency vehicles having the right of way to pass through. 

The design I selected for accomplishing my project goals involved using indicator LEDs to simulate the traffic lights, Hall effect sensors—which detect magnetic fields—to detect vehicles, an infrared photodiode to simulate the emergency vehicle signal, and an Arduino to program the necessary logic to control the traffic light transition process. The basic theory required for understanding the components I utilized in this project was mainly the concepts of photodiodes and of Kirchhoff’s loop laws for electrical current.

# Operations
The System Abides by the following rules:

1)	By default, the system should have one direction set to green, while the other direction should be set to red. No change in signals should occur unless a vehicle is present in a direction stopped by a red signal. 

2)	When a vehicle is detected in a direction which the corresponding signal is red, simulated by a magnet being placed beside the Hall effect sensor, the green light in the direction perpendicular to the direction the vehicle is waiting should turn off and the yellow light should be activated. After 5 seconds, the light should switch from yellow to red. 

3)	Simultaneously with the changing of the lights from yellow to red in the previous step, the signal corresponding to the direction the car is waiting in should now switch to green, allowing this car to proceed through the intersection. There is now a 10 second cool down before the light can switch back to red. 

4)	Repeat #2 and #3 for all instances of vehicular detection. (In the event of continual vehicular flow or constant detection by the sensors, the lights will cycle in each direction for 10 seconds. 

5)	If the infrared photodiode is activated, the traffic signals indicating green should immediately complete step 2, disregarding any cool down that may be in effect. The perpendicular direction that is indicating red should remain red. There is also a 10 second cool down for this override and once completed, signal will return to normal operation.

#Design
##Schematic: 
![alt text][schematic]

##3D Design: 
See [trafficlight.stl](trafficlight.stl)

![alt text][3d]

##Final Design:
![alt text][actual]

[schematic]: traffic%20light_schem.jpg "Traffic Light Controller Schematic"
[3d]: 3dModel.png "Traffic Light Controller Schematic"
[actual]: Final%20Protoype.png "Traffic Light Controller Schematic"
