package main

import (
	"machine"
	"time"
)

const (
	echoPin    = machine.D2
	triggerPin = machine.D3
	boardLed   = machine.D13
)

var sensor = New(triggerPin, echoPin)

func main() {
	for {
		distanceCM := sensor.ReadDistance() / 10

		boardLed.Set(distanceCM < 10)

		// Turning on/off the LED on the board if sensor is close to an object
		if distanceCM != 0 {
			println(distanceCM)
		}

		time.Sleep(50 * time.Millisecond)
	}
}

func init() {
	machine.Serial.Configure(machine.UARTConfig{BaudRate: 115200})

	boardLed.Configure(machine.PinConfig{Mode: machine.PinOutput})

	sensor.Configure()

	println("restarted arduino")
}
