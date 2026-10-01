# Automated Waste Classifier

<<<<<<< HEAD
An automated waste sorting system based on a microcontroller, designed to identify and classify waste into multiple categories using a combination of sensors and actuators.

## 📌 Description

**Automated Waste Classifier** is a smart trash bin prototype that uses multiple sensors to detect the characteristics of waste materials and automatically directs them into the appropriate category using servo-based mechanisms.

This project was developed as an implementation of embedded systems and automation technology for waste management.

## 🚨 The Problem

Manual waste sorting is highly inefficient and poses dangerous exposure risks to sanitation workers, particularly when handling **Hazardous and Toxic Materials (B3)**.

Direct human contact with potentially hazardous waste can increase occupational risks and makes the waste sorting process more difficult, time-consuming, and less efficient.

## 💡 The Solution

The project implements a **smart trash bin prototype based on Arduino Uno**, integrated with multiple sensors to identify material characteristics such as:

* Gas detection
* Dielectric properties
* Light reflection
* Metal detection

The system uses sequential **IF-ELSE control logic programmed in C/C++** to process sensor readings and autonomously control **5 servo motors**.

Each servo motor directs the detected waste into its corresponding compartment according to the classification result.

## ♻️ Waste Categories

The system is designed to automatically classify waste into five specific categories:

1. **Hazardous and Toxic Materials (B3)**
2. **Metal**
3. **Organic**
4. **Paper**
5. **Residual Waste**

## ⚙️ Technologies

* Arduino Uno
* HC-SR04 Ultrasonic Sensor
* MQ-2 Gas Sensor
* MQ-135 Gas Sensor
* Inductive Sensor
* LDR + Laser
* Capacitive Proximity Sensor
* 5 Servo Motors
* C/C++ Programming
* Proteus

## 🎯 The Impact

* The system successfully categorized waste into **5 specific categories automatically**, reducing the need for direct human contact with hazardous **B3 materials**.
* The system demonstrates how embedded systems and sensor-based automation can be applied to improve the safety and efficiency of waste sorting.
* The algorithmic innovation received an official **Intellectual Property Right (HKI No. 000602222)** certification from the **Ministry of Law and Human Rights of the Republic of Indonesia**.

## 📁 Repository Structure

```text
automated-waste-classifier/
├── README.md
├── schematics/
│   ├── Automatic_Waste_Sorting_System.pdf
│   ├── sensor_circuit_diagram.pdf
│   ├── servo_circuit_diagram.pdf
│   └── proteus/
│       └── Automatic_Waste_Sorting_System.pdsprj
│
└── src/
    └── main/
        └── main.ino
```

## 🔧 Program

The main Arduino program is located at:

```text
src/main/main.ino
```

The program contains the sequential IF-ELSE control logic responsible for processing sensor readings and controlling the servo motors according to the detected waste category.

## 📐 Schematics

The circuit documentation and Proteus simulation files are available in the:

```text
schematics/
```

directory.

These files contain the wiring diagrams and simulation resources used during the development of the prototype.

## 👨‍💻 Author

**Sendy Tegar Mahendra**

Computer Engineering
Universitas Muhammadiyah Karanganyar
=======
*An Arduino-based smart waste sorting prototype that automatically identifies and classifies waste into five categories using multiple sensors and servo-driven mechanisms.*

## 📌 The Problem

Manual waste sorting is highly inefficient and poses dangerous exposure risks to sanitation workers, particularly when handling **Hazardous and Toxic Materials (B3)**.

Direct human contact with potentially hazardous waste can increase occupational risks and makes the waste sorting process more difficult, time-consuming, and less efficient.

## 💡 The Solution

Developed a smart **waste sorting prototype based on Arduino Uno**, integrating multiple sensors to identify material characteristics such as gas, dielectric properties, light reflection, and metal.

The system uses sequential **IF-ELSE control logic programmed in C/C++** to process sensor readings and autonomously control **5 servo motors**, directing waste into the appropriate compartment based on its classification.

The system is designed to classify waste into five categories:

1. **Hazardous and Toxic Materials (B3)**
2. **Metal**
3. **Organic**
4. **Paper**
5. **Residual Waste**

## 🚀 The Impact / Results

* The system successfully categorized waste into **5 specific categories automatically**, reducing the need for direct human contact with hazardous **B3 materials**.
* The prototype demonstrates the application of embedded systems and sensor-based automation to improve the safety and efficiency of waste sorting.
* The algorithmic innovation received an official **Intellectual Property Right (HKI No. 000602222)** certification from the **Ministry of Law and Human Rights of the Republic of Indonesia**.

## 📂 Repository Structure

The repository contains the Arduino source code, electrical schematics, and Proteus simulation files used to develop the automated waste sorting prototype.

```text
automated-waste-classifier/
├── README.md
│
├── schematics/
│   ├── Automatic_Waste_Sorting_System.PDF
│   ├── sensor_circuit_diagram.PDF
│   ├── servo_circuit_diagram.PDF
│   │
│   └── proteus/
│       └── Automatic_Waste_Sorting_System.pdsprj
│
└── src/
    └── main/
        └── main.ino
```

## 🛠️ Tech Stack

* **Arduino Uno**
* **C/C++**
* **HC-SR04 Ultrasonic Sensor**
* **MQ-2 Gas Sensor**
* **MQ-135 Gas Sensor**
* **Inductive Sensor**
* **LDR + Laser**
* **Capacitive Proximity Sensor**
* **5 Servo Motors**
* **Proteus**

## 📸 Project Gallery

### System Wiring Diagram

<p align="center">
  <img src="schematics/Automatic_Waste_Sorting_System.PDF" alt="Automated Waste Sorting System" width="700">
</p>

### Sensor Circuit Diagram

<p align="center">
  <img src="schematics/sensor_circuit_diagram.PDF" alt="Sensor Circuit Diagram" width="700">
</p>

### Servo Circuit Diagram

<p align="center">
  <img src="schematics/servo_circuit_diagram.PDF" alt="Servo Circuit Diagram" width="700">
</p>

### Proteus Simulation

The Proteus simulation project is available in:

```text
schematics/proteus/Automatic_Waste_Sorting_System.pdsprj
```

### Arduino Source Code

The main Arduino program is available at:

```text
src/main/main.ino
```
>>>>>>> 117df56 (Update README and project gallery)
