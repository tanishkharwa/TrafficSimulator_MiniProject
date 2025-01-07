# Traffic Signal Management System 🚦

## Overview
The Traffic Signal Management System is a simulation program that models the behavior of traffic signals and vehicles in a city. It uses dynamic data structures and logical algorithms to simulate real-time traffic conditions. Users can monitor traffic signals, view dashboards, and modify traffic rules through interactive menus designed for Traffic Engineers and City Planners.  

This project showcases the integration of signal timers, vehicle movements, waiting queues, and dynamic dashboards, offering a comprehensive view of urban traffic management.

---

## Features
1. **Dynamic Signal Behavior:**
   - Signals cycle through **Red**, **Yellow**, and **Green** states based on timers.
   - Waiting queues are influenced by the signal color.

2. **Real-Time Dashboard:**
   - Displays the current state of traffic signals, including light colors, vehicle counts, and waiting queues.
   - Color-coded output for better visualization:
     - **Red**:  Vehicles must stop and wait.
     - **Yellow**:  Vehicles proceed cautiously.
     - **Green**: Vehicles move freely.

3. **Vehicle Movement Simulation:**
   - Vehicles move across the road dynamically and loop back when they reach their destination.
   - Vehicle counts and positions update in real-time.

4. **Customizable Rules:**
   - Traffic Engineers can modify signal properties or add new signals through an interactive menu.
   - Users can update light colors, timers, and queue rules dynamically.

5. **Interactive Menus:**
   - Separate menus for **Traffic Engineers** and **City Planners**, offering tailored functionalities.

6. **Dynamic Redistribution:**
   - Vehicle counts are dynamically updated across signals, maintaining a consistent total.

---

## How It Works
The program simulates a city’s traffic system by modeling traffic signals and vehicles using C structures. Here's how the system works:

1. **Initialization:**
   - Traffic signals and vehicles are initialized with default or randomly generated data.
   - Signal properties include name, number, vehicle count, light color, waiting queue, and timers.

2. **Signal Updates:**
   - Signals transition between Red, Yellow, and Green states based on timers.
   - Timers for each light state:
     - **Red:** 7 seconds
     - **Yellow:** 3 seconds
     - **Green:** 10 seconds

3. **Vehicle Movement:**
   - Vehicles move across the road based on their speed and destination.
   - If a vehicle encounters a red signal, it waits until the light turns green.

4. **Dashboard:**
   - Displays traffic data in real-time, including updated signal states, vehicle counts, and waiting queues.

5. **Editing Rules:**
   - Users can modify signal properties or add new signals interactively.

6. **Dynamic Redistribution:**
   - Ensures the total number of vehicles remains constant across all signals.

---

## Code Workflow
### **Main Components**
1. **Traffic Signals (`TrafficSignal`):**
   - Models the properties of each traffic signal, including light color, timer, vehicle count, and waiting queue.

2. **Vehicles (`Vehicle`):**
   - Models individual vehicle properties like ID, speed, position, and destination.

3. **Key Functions:**
   - `initializeSignals()`: Sets up initial traffic signal data.
   - `generateVehicles()`: Randomly generates vehicle properties.
   - `updateLightColors()`: Updates signal colors based on timers.
   - `moveVehicles()`: Simulates vehicle movement and redistribution.
   - `viewDashboard()`: Displays the traffic dashboard in real-time.
   - `editRules()`: Allows editing of traffic signal rules.

4. **Interactive Menus:**
   - **Traffic Engineer Menu:**
     - View the dashboard.
     - Edit traffic signal properties or add new signals.
   - **City Planner Menu:**
     - View the dashboard.

---

## Usage
### **How to Compile and Run**
To use the system:
1. Compile the code using a C compiler.
2. Run the program and provide the file name when prompted.
3. View/Edit the dashboard of the major signals of Mumbai.

## Contributions
- **BC46 DARSHAN PATEL:**
- 1.Added features for managing light colors and structured the traffic signal and vehicle data.
- 2.Developed logic for dynamic waiting queue and vehicle count updates.

- **BC47 TANSIH KHARWA:**
- 1.Added features for managing light colors and structured the traffic signal and vehicle data.
- 2.Developed logic for dynamic waiting queue and vehicle count updates.
- 3.Integrated time-based functionalities for light color transitions.
- 4.Contributed to the logical flow of vehicle and signal interactions.
 
- **BC55 VARUN MANGE:**
- 1.Fixed typos and refined the code for smoother execution.
- 2.Developed the menu driven part of the program.
