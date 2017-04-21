#!/bin/sh
# Connects to localhost:4223 by default, use --host and --port to change this

uid=XYZ # Change XYZ to the UID of your Current25 Bricklet

# Get threshold callbacks with a debounce time of 10 seconds (10000ms)
tinkerforge call current25-bricklet $uid set-debounce-period 10000

# Handle incoming current reached callbacks (parameter has unit mA)
tinkerforge dispatch current25-bricklet $uid current-reached &

# Configure threshold for current "greater than 5 A" (unit is mA)
tinkerforge call current25-bricklet $uid set-current-callback-threshold threshold-option-greater 5000 0

echo "Press key to exit"; read dummy

kill -- -$$ # Stop callback dispatch in background
