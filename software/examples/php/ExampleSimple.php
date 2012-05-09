<?php

require_once('Tinkerforge/IPConnection.php');
require_once('Tinkerforge/BrickletCurrent25.php');

use Tinkerforge\IPConnection;
use Tinkerforge\BrickletCurrent25;

$host = 'localhost';
$port = 4223;
$uid = '7tS'; // Change to your UID

$ipcon = new IPConnection($host, $port); // Create IP connection to brickd
$c = new BrickletCurrent25($uid); // Create device object

$ipcon->addDevice($c); // Add device to IP connection
// Don't use device before it is added to a connection

// Get current current (unit is mA)
$current = $c->getCurrent() / 1000.0;

echo "Current: $current A\n";

echo "Press key to exit\n";
fgetc(fopen('php://stdin', 'r'));
$ipcon->destroy();

?>
