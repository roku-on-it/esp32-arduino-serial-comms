#include <WiFi.h>
#include "board.h"

uint8_t LED_BUILTIN = 2;
uint8_t BUTTON_BUILTIN = 0;

void Board::turnOnLed()
{
    digitalWrite(LED_BUILTIN, HIGH);
}

void Board::turnOffLed()
{
    digitalWrite(LED_BUILTIN, LOW);
}

const char *Board::connectToWifi(char *ssid, char *password)
{
    WiFi.begin(ssid, password);

    int count = 0;
    while (WiFi.status() != WL_CONNECTED && count < 5)
    {
        delay(1000);
        count++;
    }

    if (WiFi.status() != WL_CONNECTED)
    {
        Serial.println("Failed to connect to WiFi");
        exit(1);
    }

    static char ipAddr[16]; // Increase the size of the array to hold the IP address

    WiFi.localIP().toString().toCharArray(ipAddr, 16); // Use the size of the array in the second argument
    return ipAddr; // Return the array itself, not its address

    return ipAddr;
}

void Board::flickerLed(int count)
{
    for (int i = 0; i < count; i++)
    {
        turnOnLed();
        delay(44);
        turnOffLed();

        if (i < count - 1)
        {
            delay(44);
        }
    }
}

void Board::init()
{
    Serial.begin(115200);

    pinMode(LED_BUILTIN, OUTPUT);
    pinMode(BUTTON_BUILTIN, INPUT);

    turnOnLed();

    Serial.println("Connecting to WiFi...");

    const char *ssid = "SUPERONLINE_Wi-Fi_0883";
    const char *password = "2dhee92KeNCA";
    const char *ipAddr = connectToWifi(const_cast<char*>(ssid), const_cast<char*>(password));

    flickerLed(10);

    Serial.print("Connected to WiFi. IP address: ");
    
    Serial.println(ipAddr);
}

bool Board::isBtnPressed()
{
    return !digitalRead(BUTTON_BUILTIN);
}