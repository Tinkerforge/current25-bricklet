#!/usr/bin/perl

use Tinkerforge::IPConnection;
use Tinkerforge::BrickletCurrent25;

use constant HOST => 'localhost';
use constant PORT => 4223;
use constant UID => 'XYZ'; # Change to your UID

my $ipcon = Tinkerforge::IPConnection->new(); # Create IP connection
my $c = Tinkerforge::BrickletCurrent25->new(&UID, $ipcon); # Create device object

# Callback subroutine for current callback (parameter has unit mA)
sub cb_current
{
    my ($current) = @_;

    print "Current: " . $current/1000.0 . " A\n";
}

$ipcon->connect(&HOST, &PORT); # Connect to brickd
# Don't use device before ipcon is connected

# Set period for current callback to 1s (1000ms)
# Note: The current callback is only called every second
#       if the current has changed since the last call!
$c->set_current_callback_period(1000);

# Register current callback to subroutine cb_current
$c->register_callback($c->CALLBACK_CURRENT, 'cb_current');

print "Press any key to exit...\n";
<STDIN>;
$ipcon->disconnect();
