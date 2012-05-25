#!/usr/bin/env ruby
# -*- ruby encoding: utf-8 -*-

require 'tinkerforge/ip_connection'
require 'tinkerforge/bricklet_current25'

include Tinkerforge

HOST = 'localhost'
PORT = 4223
UID = '7tS' # Change to your UID

ipcon = IPConnection.new HOST, PORT # Create IP connection to brickd
c = BrickletCurrent25.new UID # Create device object
ipcon.add_device c # Add device to IP connection
# Don't use device before it is added to a connection

# Get current current (unit is mA)
current = c.get_current / 1000.0
puts "Current: #{current} A"

puts 'Press key to exit'
$stdin.gets
ipcon.destroy
