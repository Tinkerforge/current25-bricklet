import com.tinkerforge.IPConnection;
import com.tinkerforge.BrickletCurrent25;

public class ExampleThreshold {
	private static final String HOST = "localhost";
	private static final int PORT = 4223;
	private static final String UID = "XYZ"; // Change to your UID

	// Note: To make the example code cleaner we do not handle exceptions. Exceptions you
	//       might normally want to catch are described in the documentation
	public static void main(String args[]) throws Exception {
		IPConnection ipcon = new IPConnection(); // Create IP connection
		BrickletCurrent25 c25 = new BrickletCurrent25(UID, ipcon); // Create device object

		ipcon.connect(HOST, PORT); // Connect to brickd
		// Don't use device before ipcon is connected

		// Get threshold callbacks with a debounce time of 10 seconds (10000ms)
		c25.setDebouncePeriod(10000);

		// Configure threshold for "greater than 5 A" (unit is mA)
		c25.setCurrentCallbackThreshold('>', (short)(5*1000), (short)0);

		// Add threshold reached listener for current greater than 5 A (parameter has unit mA)
		c25.addCurrentReachedListener(new BrickletCurrent25.CurrentReachedListener() {
			public void currentReached(short current) {
				System.out.println("Current: " + current/1000.0 + " A");
			}
		});

		System.out.println("Press key to exit"); System.in.read();
		ipcon.disconnect();
	}
}
