#include <stdio.h>

#include "ip_connection.h"
#include "bricklet_current25.h"

#define HOST "localhost"
#define PORT 4223
#define UID "XYZ" // Change to your UID

// Callback function for current greater than 5 A (parameter has unit mA)
void cb_current_reached(int16_t current, void *user_data) {
	(void)user_data; // avoid unused parameter warning

	printf("Current: %f A\n", current/1000.0);
}

int main(void) {
	// Create IP connection
	IPConnection ipcon;
	ipcon_create(&ipcon);

	// Create device object
	Current25 c;
	current25_create(&c, UID, &ipcon);

	// Connect to brickd
	if(ipcon_connect(&ipcon, HOST, PORT) < 0) {
		fprintf(stderr, "Could not connect\n");
		return 1;
	}
	// Don't use device before ipcon is connected

	// Get threshold callbacks with a debounce time of 10 seconds (10000ms)
	current25_set_debounce_period(&c, 10000);

	// Register threshold reached callback to function cb_current_reached
	current25_register_callback(&c,
	                            CURRENT25_CALLBACK_CURRENT_REACHED,
	                            (void *)cb_current_reached,
	                            NULL);

	// Configure threshold for "greater than 5 A" (unit is mA)
	current25_set_current_callback_threshold(&c, '>', 5*1000, 0);

	printf("Press key to exit\n");
	getchar();
	ipcon_destroy(&ipcon); // Calls ipcon_disconnect internally
	return 0;
}
