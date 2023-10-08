# ESP32 and Arduino communication - UART
Demonstration of communications between two different boards using UART
![Yeni Proje (1)](https://github.com/roku-on-it/esp32-arduino-serial-comms/assets/46532725/a2153620-d293-4cf1-af35-6c98a5f9a9e0)

This is a demo project that demonstrates how can ESP32 act as an Internet Gateway/Proxy for foreign boards such as Arduino and establish communication through serial ports.

<br>

The Arduino was coded in Go using TinyGo and ESP32 in C++ using the Arduino framework for ESP32 to abstract away the manufacturer's implementations.

The ESP32 board acts as a Gateway for Arduino, ESP32 writes any incoming data from the Serial port to all connected WebSocket clients, and any data sent to the WebSocket Server that runs on ESP32 is written to ESP32's Serial, thus communication between two boards is established.
![image](https://github.com/roku-on-it/esp32-arduino-serial-comms/assets/46532725/3da71615-323a-4600-83e9-5bf0db3bce89)
