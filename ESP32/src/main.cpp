#include <Arduino.h>
#include "board.h"
#include <ESPAsyncWebServer.h>

Board board;
AsyncWebServer server(80);
AsyncWebSocket ws("/ws");

void onEvent(AsyncWebSocket *server, AsyncWebSocketClient *client, AwsEventType type, void *arg, uint8_t *data, size_t len)
{
    // Pass the incoming data into UART2
    if (type == WS_EVT_DATA && len > 0)
    {
        if (len > 512)
        {
            client->text("error: message length cannot exceed 512 bytes");
        }

        Serial2.write(data, len);
    }
}

void setup()
{
    Serial2.begin(115200);

    board.init();

    ws.onEvent(onEvent);

    server.addHandler(&ws);
    server.begin();
}

void loop()
{
    if (Serial2.available())
    {
        ws.textAll(Serial2.readStringUntil('\n'));
    }

    ws.cleanupClients(10);
}