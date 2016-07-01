#!/bin/sh
# Connects to localhost:4223 by default, use --host and --port to change this

uid=XYZ # Change XYZ to the UID of your Current25 Bricklet

# Handle incoming current callbacks (parameter has unit mA)
tinkerforge dispatch current25-bricklet $uid current &

# Set period for current callback to 1s (1000ms)
# Note: The current callback is only called every second
#       if the current has changed since the last call!
tinkerforge call current25-bricklet $uid set-current-callback-period 1000

echo "Press key to exit"; read dummy

kill -- -$$ # Stop callback dispatch in background
