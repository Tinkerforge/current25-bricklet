#!/bin/sh
# connects to localhost:4223 by default, use --host and --port to change it

# change to your UID
uid=XYZ

# get current current (unit is mA)
tinkerforge call current25-bricklet $uid get-current
