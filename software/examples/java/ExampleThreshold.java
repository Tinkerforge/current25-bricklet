import com.tinkerforge.BrickletCurrent25;
import com.tinkerforge.IPConnection;

public class ExampleThreshold {
	private static final String host = new String("localhost");
	private static final int port = 4223;
	private static final String UID = new String("ABC"); // Change to your UID
	
	// Note: To make the example code cleaner we do not handle exceptions. Exceptions you
	//       might normally want to catch are described in the commnents below
	public static void main(String args[]) throws Exception {
		// Create connection to brickd
		IPConnection ipcon = new IPConnection(host, port); // Can throw IOException
		BrickletCurrent25 c25 = new BrickletCurrent25(UID); // Create device object

		// Add device to IP connection
		ipcon.addDevice(c25); // Can throw IPConnection.TimeoutException
		// Don't use device before it is added to a connection

		// Get threshold callbacks with a debounce time of 10 seconds (10000ms)
		c25.setDebouncePeriod(10000);

		// Configure threshold for "greater than 5A" (unit is mA)
		c25.setCurrentCallbackThreshold('>', (short)(5*1000), (short)0);

		// Add and implement current reached listener (called if current is greater than 5A)
		c25.addListener(new BrickletCurrent25.CurrentReachedListener() {
			public void currentReached(short current) {
				System.out.println("Current is greater than 5A: " + current/1000.0);
			}
		});

		System.out.println("Press ctrl+c to exit");
		ipcon.joinThread();
	}
}
