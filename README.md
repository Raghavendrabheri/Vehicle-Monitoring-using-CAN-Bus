# Vehicle Monitoring System Using CAN Protocol

## Overview

This project is a **multi-node vehicle monitoring system** designed using the **Controller Area Network (CAN) protocol** and the LPC2129 microcontroller. It integrates sensors and actuators to monitor and control various aspects of a vehicle, such as temperature, distance from obstacles, and window position.

## Project Features

1. **Centralized Monitoring:** The main node (Node 1) acts as the system’s controller, displaying temperature and coordinating the data exchange between nodes.
2. **Ultrasonic Sensing (Node 3):** Measures distance to nearby obstacles and transmits the data to other nodes via the CAN bus.
3. **Window Control (Node 2):** Dynamically adjusts the vehicle’s windows based on the data received over CAN.

## System Architecture

The system consists of three nodes:

1. **Node 1 (Main Monitoring Node):**

   - **Functions:**
     - Reads temperature using a DS18B20 sensor.
     - Displays vehicle data (e.g., temperature) on an LCD.
     - Acts as the central controller, initiating and receiving CAN messages.

2. **Node 2 (Window Control Node):**

   - **Functions:**
     - Adjusts window positions dynamically.
     - Receives CAN messages from Node 1 and updates the window state accordingly.

3. **Node 3 (Ultrasonic Sensor Node):**

   - **Functions:**
     - Measures the distance of obstacles using ultrasonic sensors.
     - Sends distance data to the main node via the CAN bus.

## Key Technologies

- **CAN Protocol:** Enables efficient and reliable communication between nodes.
- **Embedded C Programming:** Used for developing the system firmware.
- **Interrupt Handling:** Ensures real-time system performance.
- **Microcontroller:** LPC21xx microcontroller for all nodes.
- **Sensors:** Ultrasonic and DS18B20 temperature sensors for monitoring.

## Workflow

1. **Initialization:**

   - Each node initializes its hardware components (e.g., CAN controller, sensors, LCD).
   - Nodes establish communication via the CAN bus.

2. **Node Interactions:**

   - Node 3 measures the distance to obstacles and transmits this data as a CAN message to the main node.
   - Node 1 processes the data and, if necessary, forwards instructions to Node 2 to adjust the window positions.
   - Node 2 receives the CAN message and performs the required adjustments.

3. **Display:**

   - Node 1 continuously displays real-time temperature and system status on the LCD.

## Highlights

- **Robust Communication:** Utilizes the CAN protocol for error-resilient data exchange.
- **Real-Time Processing:** Ensures timely and synchronized operation of all nodes.
- **Scalability:** The system can easily integrate additional nodes and functionalities.

## Learning Outcomes

This project provided hands-on experience in:

- Designing and implementing multi-node systems with CAN communication.
- Sensor integration and actuator control.
- Developing efficient interrupt-driven routines.
- Real-time embedded system design and debugging.

## Future Enhancements

- Adding more sensors and nodes for advanced vehicle monitoring (e.g., speed, fuel level).
- Integrating wireless connectivity for remote monitoring and control.
- Enhancing the graphical display for a more user-friendly interface.

## Conclusion

This project demonstrates how the CAN protocol can be effectively used to build a multi-node embedded system for vehicle monitoring. It highlights the importance of robust communication and real-time data processing in automotive applications.

