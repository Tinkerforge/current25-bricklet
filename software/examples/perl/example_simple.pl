#!/usr/bin/perl

use Tinkerforge::IPConnection;
use Tinkerforge::BrickletCurrent25;

use constant HOST => 'localhost';
use constant PORT => 4223;
use constant UID => 'XYZ'; # Change XYZ to the UID of your Current25 Bricklet

my $ipcon = Tinkerforge::IPConnection->new(); # Create IP connection
my $c = Tinkerforge::BrickletCurrent25->new(&UID, $ipcon); # Create device object

$ipcon->connect(&HOST, &PORT); # Connect to brickd
# Don't use device before ipcon is connected

# Get current current
my $current = $c->get_current();
print "Current: " . $current/1000.0 . " A\n";

print "Press key to exit\n";
<STDIN>;
$ipcon->disconnect();
