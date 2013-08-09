#!/bin/sh
# connects to localhost:4223 by default, use --host and --port to change it

# change to your UID
uid=XYZ

# get threshold callbacks with a debounce time of 10 seconds (10000ms)
tinkerforge call current25-bricklet $uid set-debounce-period 10000

# configure threshold for "greater than 5A" (unit is mA)
tinkerforge call current25-bricklet $uid set-current-callback-threshold greater 5000 0

# handle incoming current-reached callbacks (unit is mA)
tinkerforge dispatch current25-bricklet $uid current-reached\
 --execute "echo Current is greater than 5A: {current} mA"
