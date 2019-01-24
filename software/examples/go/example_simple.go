package main

import (
	"fmt"
	"github.com/Tinkerforge/go-api-bindings/current25_bricklet"
	"github.com/Tinkerforge/go-api-bindings/ipconnection"
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

	// Get current current.
	current, _ := c.GetCurrent()
	fmt.Printf("Current: %f A\n", float64(current)/1000.0)

	fmt.Print("Press enter to exit.")
	fmt.Scanln()
}
