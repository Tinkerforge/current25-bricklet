<?php

require_once('Tinkerforge/IPConnection.php');
require_once('Tinkerforge/BrickletCurrent25.php');

use Tinkerforge\IPConnection;
use Tinkerforge\BrickletCurrent25;

const HOST = 'localhost';
const PORT = 4223;
const UID = 'XYZ'; // Change XYZ to the UID of your Current25 Bricklet

// Callback function for current callback
function cb_current($current)
{
    echo "Current: " . $current/1000.0 . " A\n";
}

$ipcon = new IPConnection(); // Create IP connection
$c = new BrickletCurrent25(UID, $ipcon); // Create device object

$ipcon->connect(HOST, PORT); // Connect to brickd
// Don't use device before ipcon is connected

// Register current callback to function cb_current
$c->registerCallback(BrickletCurrent25::CALLBACK_CURRENT, 'cb_current');

// Set period for current callback to 1s (1000ms)
// Note: The current callback is only called every second
//       if the current has changed since the last call!
$c->setCurrentCallbackPeriod(1000);

echo "Press ctrl+c to exit\n";
$ipcon->dispatchCallbacks(-1); // Dispatch callbacks forever

?>
