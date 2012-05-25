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

# Set Period for current callback to 1s (1000ms)
# Note: The callback is only called every second if the 
#       current has changed since the last call!
c.set_current_callback_period 1000

# Register current callback (parameter has unit mA)
c.register_callback BrickletCurrent25::CALLBACK_CURRENT, do |current|
  puts "Current: #{current/1000.0} A"
end

puts 'Press key to exit'
$stdin.gets
ipcon.destroy
