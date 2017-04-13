using System;
using Tinkerforge;

class Example
{
	private static string HOST = "localhost";
	private static int PORT = 4223;
	private static string UID = "XYZ"; // Change XYZ to the UID of your Current25 Bricklet

	// Callback function for current reached callback (parameter has unit mA)
	static void CurrentReachedCB(BrickletCurrent25 sender, short current)
	{
		Console.WriteLine("Current: " + current/1000.0 + " A");
	}

	static void Main()
	{
		IPConnection ipcon = new IPConnection(); // Create IP connection
		BrickletCurrent25 c = new BrickletCurrent25(UID, ipcon); // Create device object

		ipcon.Connect(HOST, PORT); // Connect to brickd
		// Don't use device before ipcon is connected

		// Get threshold callbacks with a debounce time of 10 seconds (10000ms)
		c.SetDebouncePeriod(10000);

		// Register current reached callback to function CurrentReachedCB
		c.CurrentReachedCallback += CurrentReachedCB;

		// Configure threshold for current "greater than 5 A" (unit is mA)
		c.SetCurrentCallbackThreshold('>', 5*1000, 0);

		Console.WriteLine("Press enter to exit");
		Console.ReadLine();
		ipcon.Disconnect();
	}
}
