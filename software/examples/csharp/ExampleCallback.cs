using Tinkerforge;

class Example
{
	private static string HOST = "localhost";
	private static int PORT = 4223;
	private static string UID = "ABC"; // Change to your UID

	// Callback function for current callback (parameter has unit mA)
	static void CurrentCB(short current)
	{
		System.Console.WriteLine("Current: " + current/1000.0 + " A");
	}

	static void Main() 
	{
		IPConnection ipcon = new IPConnection(HOST, PORT); // Create connection to brickd
		BrickletCurrent25 c25 = new BrickletCurrent25(UID); // Create device object
		ipcon.AddDevice(c25); // Add device to IP connection
		// Don't use device before it is added to a connection

		// Set Period for current callback to 1s (1000ms)
		// Note: The current callback is only called every second if the 
		//       current has changed since the last call!
		c25.SetCurrentCallbackPeriod(1000);

		// Register current callback to function CurrentCB
		c25.RegisterCallback(new BrickletCurrent25.Current(CurrentCB));

		System.Console.WriteLine("Press ctrl+c to exit");
		ipcon.JoinThread();
	}
}
