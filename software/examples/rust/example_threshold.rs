use std::{error::Error, io, thread};
use tinkerforge::{current25_bricklet::*, ipconnection::IpConnection};

const HOST: &str = "127.0.0.1";
const PORT: u16 = 4223;
const UID: &str = "XYZ"; // Change XYZ to the UID of your Current25 Bricklet

fn main() -> Result<(), Box<dyn Error>> {
    let ipcon = IpConnection::new(); // Create IP connection
    let current25_bricklet = Current25Bricklet::new(UID, &ipcon); // Create device object

    ipcon.connect(HOST, PORT).recv()??; // Connect to brickd
                                        // Don't use device before ipcon is connected

    // Get threshold listeners with a debounce time of 10 seconds (10000ms)
    current25_bricklet.set_debounce_period(10000);

    //Create listener for current reached events.
    let current_reached_listener = current25_bricklet.get_current_reached_receiver();
    // Spawn thread to handle received events. This thread ends when the current25_bricklet
    // is dropped, so there is no need for manual cleanup.
    thread::spawn(move || {
        for event in current_reached_listener {
            println!("Current: {}{}", event as f32 / 1000.0, " A");
        }
    });

    // Configure threshold for current "greater than 5 A"
    current25_bricklet.set_current_callback_threshold('>', 5 * 1000, 0);

    println!("Press enter to exit.");
    let mut _input = String::new();
    io::stdin().read_line(&mut _input)?;
    ipcon.disconnect();
    Ok(())
}
