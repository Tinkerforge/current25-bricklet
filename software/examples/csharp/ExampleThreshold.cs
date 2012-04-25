using Tinkerforge;

class Example
{
	private static string HOST = "localhost";
	private static int PORT = 4223;
	private static string UID = "ABC"; // Change to your UID

	// Callback for current greater than 5A
	static void ReachedCB(short current)
	{
		System.Console.WriteLine("Current is greater than 5A: " + current/1000.0 + "A");
	}

	static void Main() 
	{
		IPConnection ipcon = new IPConnection(HOST, PORT); // Create connection to brickd
		BrickletCurrent25 c25 = new BrickletCurrent25(UID); // Create device object
		ipcon.AddDevice(c25); // Add device to IP connection
		// Don't use device before it is added to a connection

		// Get threshold callbacks with a debounce time of 1 seconds (1000ms)
		c25.SetDebouncePeriod(1000);

		// Register threshold reached callback to function ReachedCB
		c25.RegisterCallback(new BrickletCurrent25.CurrentReached(ReachedCB));

		// Configure threshold for "greater than 5A" (unit is mA)
		c25.SetCurrentCallbackThreshold('>', 5*1000, 0);

		System.Console.WriteLine("Press ctrl+c to exit");
		ipcon.JoinThread();
	}
}
