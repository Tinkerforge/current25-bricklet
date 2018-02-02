import com.tinkerforge.IPConnection;
import com.tinkerforge.BrickletCurrent25;

public class ExampleThreshold {
	private static final String HOST = "localhost";
	private static final int PORT = 4223;

	// Change XYZ to the UID of your Current25 Bricklet
	private static final String UID = "XYZ";

	// Note: To make the example code cleaner we do not handle exceptions. Exceptions
	//       you might normally want to catch are described in the documentation
	public static void main(String args[]) throws Exception {
		IPConnection ipcon = new IPConnection(); // Create IP connection
		BrickletCurrent25 c = new BrickletCurrent25(UID, ipcon); // Create device object

		ipcon.connect(HOST, PORT); // Connect to brickd
		// Don't use device before ipcon is connected

		// Get threshold callbacks with a debounce time of 10 seconds (10000ms)
		c.setDebouncePeriod(10000);

		// Add current reached listener
		c.addCurrentReachedListener(new BrickletCurrent25.CurrentReachedListener() {
			public void currentReached(short current) {
				System.out.println("Current: " + current/1000.0 + " A");
			}
		});

		// Configure threshold for current "greater than 5 A"
		c.setCurrentCallbackThreshold('>', (short)(5*1000), (short)0);

		System.out.println("Press key to exit"); System.in.read();
		ipcon.disconnect();
	}
}
