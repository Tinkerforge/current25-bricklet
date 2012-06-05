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

# Get threshold callbacks with a debounce time of 10 seconds (10000ms)
c.set_debounce_period 10000

# Register threshold reached callback for "greater than 5A" (unit is mA)
c.register_callback(BrickletCurrent25::CALLBACK_CURRENT_REACHED) do |current|
  puts "Current is greater than 5A: #{current/1000.0}"
end

# Configure threshold for "greater than 5A" (unit is mA)
c.set_current_callback_threshold '>', 5*1000, 0

puts 'Press key to exit'
$stdin.gets
ipcon.destroy
