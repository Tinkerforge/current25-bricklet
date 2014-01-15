<?php

require_once('Tinkerforge/IPConnection.php');
require_once('Tinkerforge/BrickletCurrent25.php');

use Tinkerforge\IPConnection;
use Tinkerforge\BrickletCurrent25;

const HOST = 'localhost';
const PORT = 4223;
const UID = '7tS'; // Change to your UID

$ipcon = new IPConnection(); // Create IP connection
$c = new BrickletCurrent25(UID, $ipcon); // Create device object

$ipcon->connect(HOST, PORT); // Connect to brickd
// Don't use device before ipcon is connected

// Get current current (unit is mA)
$current = $c->getCurrent() / 1000.0;

echo "Current: $current A\n";

echo "Press key to exit\n";
fgetc(fopen('php://stdin', 'r'));
$ipcon->disconnect();

?>
