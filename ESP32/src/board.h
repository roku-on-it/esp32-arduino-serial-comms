#ifndef BOARD_H
#define BOARD_H

class Board
{
public:
    const char *connectToWifi(char *ssid, char *password);
    void flickerLed(int count);
    void turnOnLed();
    void turnOffLed();
    bool isBtnPressed();
    void init();
};

#endif // BOARD_H
