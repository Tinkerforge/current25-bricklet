import com.tinkerforge.BrickletCurrent25;
import com.tinkerforge.IPConnection;

public class ExampleSimple {
	private static final String host = new String("localhost");
	private static final int port = 4223;
	private static final String UID = new String("ABC"); // Change to your UID
	
	// Note: To make the example code cleaner we do not handle exceptions. Exceptions you
	//       might normally want to catch are described in the commnents below
	public static void main(String args[]) throws Exception {
		IPConnection ipcon = new IPConnection(host, port); // Create connection to brickd (Can throw IOException)

		BrickletCurrent25 c25 = new BrickletCurrent25(UID); // Create device object
		ipcon.addDevice(c25); // Add device to ip connection (Can throw IPConnection.TimeoutException)
		// Don't use device before it is added to a connection
		

		// Get current current (unit is mA)
		short current = c25.getCurrent(); // Can throw IPConnection.TimeoutException

		System.out.println("Current: " + current/1000.0 + " A");
		
		System.out.println("Press ctrl+c to exit");
		ipcon.joinThread();
	}
}
