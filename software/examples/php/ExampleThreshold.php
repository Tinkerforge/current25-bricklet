<?php

require_once('Tinkerforge/IPConnection.php');
require_once('Tinkerforge/BrickletCurrent25.php');

use Tinkerforge\IPConnection;
use Tinkerforge\BrickletCurrent25;

const HOST = 'localhost';
const PORT = 4223;
const UID = '7tS'; // Change to your UID

// Callback for current greater than 5A
function cb_reached($current)
{
    echo "Current is greater than 5A: " . $current / 1000.0 . "\n";
}

$ipcon = new IPConnection(); // Create IP connection
$c = new BrickletCurrent25(UID, $ipcon); // Create device object

$ipcon->connect(HOST, PORT); // Connect to brickd
// Don't use device before ipcon is connected

// Get threshold callbacks with a debounce time of 10 seconds (10000ms)
$c->setDebouncePeriod(10000);

// Register threshold reached callback to function cb_reached
$c->registerCallback(BrickletCurrent25::CALLBACK_CURRENT_REACHED, 'cb_reached');

// Configure threshold for "greater than 5A" (unit is mA)
$c->setCurrentCallbackThreshold('>', 5*1000, 0);

echo "Press ctrl+c to exit\n";
$ipcon->dispatchCallbacks(-1); // Dispatch callbacks forever

?>
