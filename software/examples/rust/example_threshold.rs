use std::{error::Error, io, thread};
use tinkerforge::{current25_bricklet::*, ip_connection::IpConnection};

const HOST: &str = "localhost";
const PORT: u16 = 4223;
const UID: &str = "XYZ"; // Change XYZ to the UID of your Current25 Bricklet.

fn main() -> Result<(), Box<dyn Error>> {
    let ipcon = IpConnection::new(); // Create IP connection.
    let c = Current25Bricklet::new(UID, &ipcon); // Create device object.

    ipcon.connect((HOST, PORT)).recv()??; // Connect to brickd.
                                          // Don't use device before ipcon is connected.

    // Get threshold receivers with a debounce time of 10 seconds (10000ms).
    c.set_debounce_period(10000);

    let current_reached_receiver = c.get_current_reached_callback_receiver();

    // Spawn thread to handle received callback messages.
    // This thread ends when the `c` object
    // is dropped, so there is no need for manual cleanup.
    thread::spawn(move || {
        for current_reached in current_reached_receiver {
            println!("Current: {} A", current_reached as f32 / 1000.0);
        }
    });

    // Configure threshold for current "greater than 5 A".
    c.set_current_callback_threshold('>', 5 * 1000, 0);

    println!("Press enter to exit.");
    let mut _input = String::new();
    io::stdin().read_line(&mut _input)?;
    ipcon.disconnect();
    Ok(())
}
