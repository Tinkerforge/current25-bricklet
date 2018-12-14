package main

import (
	"fmt"
	"tinkerforge/current25_bricklet"
	"tinkerforge/ipconnection"
)

const ADDR string = "localhost:4223"
const UID string = "XYZ" // Change XYZ to the UID of your Current25 Bricklet.

func main() {
	ipcon := ipconnection.New()
	defer ipcon.Close()
	c, _ := current25_bricklet.New(UID, &ipcon) // Create device object.

	ipcon.Connect(ADDR) // Connect to brickd.
	defer ipcon.Disconnect()
	// Don't use device before ipcon is connected.

	// Get threshold receivers with a debounce time of 10 seconds (10000ms).
	c.SetDebouncePeriod(10000)

	c.RegisterCurrentReachedCallback(func(current int16) {
		fmt.Printf("Current: %f A\n", float64(current)/1000.0)
	})

	// Configure threshold for current "greater than 5 A".
	c.SetCurrentCallbackThreshold('>', 5*1000, 0)

	fmt.Print("Press enter to exit.")
	fmt.Scanln()

}
