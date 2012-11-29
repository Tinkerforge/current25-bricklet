<?php

require_once('Tinkerforge/IPConnection.php');
require_once('Tinkerforge/BrickletCurrent25.php');

use Tinkerforge\IPConnection;
use Tinkerforge\BrickletCurrent25;

$host = 'localhost';
$port = 4223;
$uid = '7tS'; // Change to your UID

$ipcon = new IPConnection(); // Create IP connection
$c = new BrickletCurrent25($uid, $ipcon); // Create device object

$ipcon->connect($host, $port); // Connect to brickd
// Don't use device before ipcon is connected

// Get current current (unit is mA)
$current = $c->getCurrent() / 1000.0;

echo "Current: $current A\n";

echo "Press key to exit\n";
fgetc(fopen('php://stdin', 'r'));

?>
