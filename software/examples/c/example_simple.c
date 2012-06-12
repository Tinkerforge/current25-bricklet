
#include <stdio.h>

#include "ip_connection.h"
#include "bricklet_current25.h"

#define HOST "localhost"
#define PORT 4223
#define UID "ABCD" // Change to your UID

int main() {
	// Create IP connection to brickd
	IPConnection ipcon;
	if(ipcon_create(&ipcon, HOST, PORT) < 0) {
		fprintf(stderr, "Could not create connection\n");
		exit(1);
	}

	// Create device object
	Current25 c;
	current25_create(&c, UID); 

	// Add device to IP connection
	if(ipcon_add_device(&ipcon, &c) < 0) {
		fprintf(stderr, "Could not connect to Bricklet\n");
		exit(1);
	}
	// Don't use device before it is added to a connection

	// Get current current (unit is mA)
	int16_t current;
	if(current25_get_current(&c, &current) < 0) {
		fprintf(stderr, "Could not get value, probably timeout\n");
		exit(1);
	}

	printf("Current: %f A\n", current/1000.0);

	printf("Press ctrl+c to close\n");
	ipcon_join_thread(&ipcon); // Join mainloop of IP connection
}
