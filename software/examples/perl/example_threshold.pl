#!/usr/bin/perl

use Tinkerforge::IPConnection;
use Tinkerforge::BrickletCurrent25;

use constant HOST => 'localhost';
use constant PORT => 4223;
use constant UID => 'abd2'; # Change to your UID

my $ipcon = Tinkerforge::IPConnection->new(); # Create IP connection
my $c25 = Tinkerforge::BrickletCurrent25->new(&UID, $ipcon); # Create device object

# Callback for current greater than 5A
sub cb_reached
{
    my ($current) = @_;
    print "\nCurrent is greater than 5A: ".$current/1000.0." \n";
}

$ipcon->connect(&HOST, &PORT); # Connect to brickd
# Don't use device before ipcon is connected

# Get threshold callbacks with a debounce time of 10 seconds (10000ms)
$c25->set_debounce_period(1000);

# Register threshold reached callback to function cb_reached
$c25->register_callback($c25->CALLBACK_CURRENT_REACHED, 'cb_reached');

# Configure threshold for "greater than 5A" (unit is mA)
$c25->set_current_callback_threshold('>', 5*1000, 0);

print "\nPress any key to exit...\n";
<STDIN>;
$ipcon->disconnect();
