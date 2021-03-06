var Tinkerforge = require('tinkerforge');

var HOST = 'localhost';
var PORT = 4223;
var UID = 'XYZ'; // Change XYZ to the UID of your Current25 Bricklet

var ipcon = new Tinkerforge.IPConnection(); // Create IP connection
var c = new Tinkerforge.BrickletCurrent25(UID, ipcon); // Create device object

ipcon.connect(HOST, PORT,
    function (error) {
        console.log('Error: ' + error);
    }
); // Connect to brickd
// Don't use device before ipcon is connected

ipcon.on(Tinkerforge.IPConnection.CALLBACK_CONNECTED,
    function (connectReason) {
        // Set period for current callback to 1s (1000ms)
        // Note: The current callback is only called every second
        //       if the current has changed since the last call!
        c.setCurrentCallbackPeriod(1000);
    }
);

// Register current callback
c.on(Tinkerforge.BrickletCurrent25.CALLBACK_CURRENT,
    // Callback function for current callback
    function (current) {
        console.log('Current: ' + current/1000.0 + ' A');
    }
);

console.log('Press key to exit');
process.stdin.on('data',
    function (data) {
        ipcon.disconnect();
        process.exit(0);
    }
);
