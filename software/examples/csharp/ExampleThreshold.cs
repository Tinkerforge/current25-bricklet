using Tinkerforge;

class Example
{
	private static string HOST = "localhost";
	private static int PORT = 4223;
	private static string UID = "ABC"; // Change to your UID

	// Callback for current greater than 5A
	static void ReachedCB(object sender, short current)
	{
		System.Console.WriteLine("Current is greater than 5A: " + current/1000.0 + "A");
	}

	static void Main() 
	{
		IPConnection ipcon = new IPConnection(); // Create IP connection
		BrickletCurrent25 c25 = new BrickletCurrent25(UID, ipcon); // Create device object

		ipcon.Connect(HOST, PORT); // Connect to brickd
		// Don't use device before ipcon is connected

		// Get threshold callbacks with a debounce time of 1 seconds (1000ms)
		c25.SetDebouncePeriod(1000);

		// Register threshold reached callback to function ReachedCB
		c25.CurrentReached += ReachedCB;

		// Configure threshold for "greater than 5A" (unit is mA)
		c25.SetCurrentCallbackThreshold('>', 5*1000, 0);

		System.Console.WriteLine("Press key to exit");
		System.Console.ReadKey();
	}
}
