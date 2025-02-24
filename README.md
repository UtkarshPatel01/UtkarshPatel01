
🚀 Embedded Systems Project (STM32 & Arduino)
<br>Welcome to the Embedded Systems Project repository! This project focuses on STM32F103C8 (Blue Pill) and Arduino UNO R3, with development using STM32Cube Programmer and Arduino IDE. The repository includes firmware, circuit schematics, and project examples for embedded applications.

📌 Features
✅ STM32F103C8 & Arduino UNO R3 support
✅ Bare-metal and Arduino-based programming
✅ Peripheral interfacing: GPIO, UART, SPI, I2C, PWM, ADC
✅ STM32Cube Programmer for flashing STM32
✅ Arduino IDE for easy development
✅ Sensor & actuator integration (DHT11, OLED, Motors, etc.)
✅ Interrupts & power management
✅ Communication: Serial, I2C, SPI, Bluetooth

📂 Repository Structure
bash
Copy
Edit
📦 Embedded-Systems-Project  
│── 📁 docs          # Documentation and guides  
│── 📁 firmware      # STM32 & Arduino firmware source code  
│── 📁 hardware      # Circuit schematics and PCB designs  
│── 📁 examples      # Example projects & test programs  
│── 📄 LICENSE       # License information  
│── 📄 README.md     # Project overview  
🛠️ Getting Started
1️⃣ Prerequisites
Before you begin, ensure you have the following installed:

🔹 For STM32F103C8 (Blue Pill)
STM32Cube Programmer (Download Here)
STM32duino (for Arduino IDE) (Installation Guide)
USB-to-Serial Adapter (CP2102, CH340G) or ST-Link v2
STM32CubeIDE (Optional for advanced development)
🔹 For Arduino UNO R3
Arduino IDE (Download Here)
Drivers for USB (CH340/ATmega16U2)
2️⃣ Clone the Repository
sh
Copy
Edit
git clone https://github.com/your-username/Embedded-Systems-Project.git
cd Embedded-Systems-Project
🔋 Flashing Firmware
🔹 Uploading Code to STM32F103C8 (Blue Pill)
Method 1: Using STM32Cube Programmer & USB-to-Serial (CP2102)

Connect USB-to-Serial (CP2102/CH340G) to STM32:
VCC → 3.3V
GND → GND
TX → PA10 (RX1)
RX → PA9 (TX1)
Set BOOT0 = 1 (Programming Mode), BOOT1 = 0
Open STM32Cube Programmer
Select Serial Port, connect, and flash firmware
Set BOOT0 = 0 (Normal Mode), reset STM32
Method 2: Using ST-Link V2

Connect ST-Link to STM32:
3.3V → 3.3V
GND → GND
SWDIO → SWDIO
SWCLK → SWCLK
Open STM32Cube Programmer, select ST-Link, and flash firmware
🔹 Uploading Code to Arduino UNO R3
Connect Arduino to PC via USB
Open Arduino IDE
Select Board: Arduino UNO
Select Port (Tools > Port > COMx)
Write or open an example code
Click Upload
📚 Example Projects
Project	Description	Board
Blink LED	Basic LED blinking	STM32 & Arduino
UART Communication	Serial communication between STM32 & Arduino	STM32 & Arduino
I2C OLED Display	Display text on OLED via I2C	STM32 & Arduino
Temperature Sensor (DHT11)	Read temperature & humidity data	STM32 & Arduino
Motor Control (PWM)	Control DC Motor speed using PWM	STM32 & Arduino
Bluetooth Communication (HC-05)	Wireless communication using Bluetooth	STM32 & Arduino
Find the code inside the examples folder!

🤝 Contributing
We welcome contributions! Follow these steps:

Fork the repository.
Create a new branch: git checkout -b feature-xyz.
Commit your changes: git commit -m "Added new feature".
Push the changes: git push origin feature-xyz.
Open a Pull Request.
📜 License
This project is licensed under the MIT License – see the LICENSE file for details.

<br>💬 Contact & Support
<br>📧 Email: utkarshpatel0008@gmail.com
<br>🖇️Linkedin: https://www.linkedin.com/in/utkarshpatel001
