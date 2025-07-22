# Auto-Pick-Drop-Robotic-Arm
Watch video: https://www.youtube.com/watch?v=FFQAYzntxq0

### **Project Description: Ultrasonic-Controlled Robotic Arm**  

This project demonstrates an **autonomous 4-DOF (Degree of Freedom) robotic arm** that detects, picks, and places objects using an **HC-SR04 ultrasonic sensor**. The system scans its surroundings by rotating the base servo (0°–180°) and triggers a pickup sequence when an object is detected within **8cm**. The arm uses four **SG90 servo motors** for precise movement—controlling the base rotation, dual-joint arm elevation, and gripper mechanism. After pickup, it drops the object into a designated container before resetting to its default position.  

### **Key Features**  
- **Autonomous Object Detection**: Uses ultrasonic ranging (2cm–400cm) to locate objects.  
- **Smooth Servo Control**: Implements slow, incremental movements for jerk-free operation.  
- **Pick-and-Drop Mechanism**: Customizable servo angles for gripping and releasing objects.  
- **Real-Time Feedback**: Serial Monitor outputs distance and servo angles for debugging.  

### **Hardware Components**  
- **Microcontroller**: Arduino Uno (5V, 16MHz)  
- **Sensors**: HC-SR04 Ultrasonic (Trig: Pin 10, Echo: Pin 11)  
- **Actuators**: 4x SG90 Servos (Pins 3, 5, 6, 9)  
- **Power**: 5V 2A external supply recommended for stable servo operation.  

### **Applications & Scalability**  
Ideal for **educational robotics**, **warehouse automation prototypes**, or **hobbyist projects**. The modular design allows upgrades like IR sensors for object sorting or wireless control (Bluetooth/WiFi). Future enhancements could include computer vision for object recognition.  

*(Note: No code modifications are needed for basic operation—adjust detection range or servo angles in the provided Arduino script.)*
