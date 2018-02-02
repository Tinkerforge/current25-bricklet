#!/usr/bin/env ruby
# -*- ruby encoding: utf-8 -*-

require 'tinkerforge/ip_connection'
require 'tinkerforge/bricklet_current25'

include Tinkerforge

HOST = 'localhost'
PORT = 4223
UID = 'XYZ' # Change XYZ to the UID of your Current25 Bricklet

ipcon = IPConnection.new # Create IP connection
c = BrickletCurrent25.new UID, ipcon # Create device object

ipcon.connect HOST, PORT # Connect to brickd
# Don't use device before ipcon is connected

# Get threshold callbacks with a debounce time of 10 seconds (10000ms)
c.set_debounce_period 10000

# Register current reached callback
c.register_callback(BrickletCurrent25::CALLBACK_CURRENT_REACHED) do |current|
  puts "Current: #{current/1000.0} A"
end

# Configure threshold for current "greater than 5 A"
c.set_current_callback_threshold '>', 5*1000, 0

puts 'Press key to exit'
$stdin.gets
ipcon.disconnect
