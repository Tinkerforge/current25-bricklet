#!/usr/bin/env python
# -*- coding: utf-8 -*-

HOST = "localhost"
PORT = 4223
UID = "XYZ" # Change to your UID

from tinkerforge.ip_connection import IPConnection
from tinkerforge.bricklet_current25 import Current25

# Callback function for current callback (parameter has unit mA)
def cb_current(current):
    print('Current: ' + str(current/1000.0) + ' A')

if __name__ == "__main__":
    ipcon = IPConnection() # Create IP connection
    c25 = Current25(UID, ipcon) # Create device object

    ipcon.connect(HOST, PORT) # Connect to brickd
    # Don't use device before ipcon is connected

    # Set period for current callback to 1s (1000ms)
    # Note: The current callback is only called every second
    #       if the current has changed since the last call!
    c25.set_current_callback_period(1000)

    # Register current callback to function cb_current
    c25.register_callback(c25.CALLBACK_CURRENT, cb_current)

    raw_input('Press key to exit\n') # Use input() in Python 3
    ipcon.disconnect()
