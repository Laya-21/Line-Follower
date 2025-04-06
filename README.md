
# Line Follower

Welcome to the Line Follower Robot repository!
This project is developed by the Robot Study Circle, COEP. It is an autonomous robot designed to follow a path using sensors and PID control.


## Roadmap

- PCB Design

- Code Overview

- PID Control



## Hardware Components

- Microcontroller :- Arduino Nano
- Motor Driver :- L298N
- IR Sensor Array
- DC Motor 300rpm
- Custom PCB
- 3D Printed Chassy and Wheel
- 12V Lipo Battery


## PCB Design

The **Printed Circuit Board (PCB)** serves as the foundation of the Line Follower robot's electronics.

### Tools Used
- Software :- Altium Designer
- Board Material:-  Epoxy (commonly FR4)
- Copper Layer:- Single-sided or double-sided depending on complexity

### Design Steps
**1. Schematic Design**:-
- A schematic diagram was created to define the connections between the components: ATmega16, L293D, IR sensors, LM7805, etc.

- Each component's electrical properties and pin configurations are specified here.
![App Screenshot](https://raw.githubusercontent.com/Laya-21/Line-Follower/refs/heads/main/Media/schematic.jpg)

**2. PCB Design**:-
- Components are logically arranged to minimize trace length and noise.

- Routing involves drawing copper traces that form the electrical pathways between pins.

- Power and ground planes are incorporated to ensure stable power delivery and minimize EMI (Electromagnetic Interference).

- Proper width traces are used for high-current lines, especially motor driver connections.

## Main Board PCB

| ![Main PCB](https://raw.githubusercontent.com/Laya-21/Line-Follower/refs/heads/main/Media/pcb_2.jpg) | ![Main PCB 3D](https://raw.githubusercontent.com/Laya-21/Line-Follower/refs/heads/main/Media/pcb_3.jpg) |
|:--:|:--:|
| Main PCB | Main PCB 3D View |



## CODE Overview

The code for the Line Follower Robot is written in Arduino C++ and uploaded to an Arduino Nano.

**1.PID Control**

- A PID (Proportional, Integral, Derivative) algorithm is implemented to minimize deviation from the center of the line.

- The error is computed based on the sensor values, and the PID output is used to adjust the speed of left and right motors.

- This enables smoother and more accurate path tracking, even at curves or junctions.

**2. Color Inversion Logic**

- The robot supports track color inversion (e.g., black-on-white or white-on-black).

- This is handled by inverting the motor directions:

- For left-right inversion, motor directions are swapped accordingly.

- For forward-backward inversion, the robot adjusts to reverse the behavior.
## Media

![App Screenshot](https://raw.githubusercontent.com/Laya-21/Line-Follower/refs/heads/main/Media/img2.jpg)

| ![Line Following](Media/gif_1.gif) | ![Color Inversion](Media/gif_1.gif) |
|:--:|:--:|
| Line Following | Color Inversion |

![Line Follower Demo](Media/gif_1.gif)

![Line Follower Demo](Media/gif_1.gif)
