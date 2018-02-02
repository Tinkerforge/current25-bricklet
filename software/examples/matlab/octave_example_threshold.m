function octave_example_threshold()
    more off;

    HOST = "localhost";
    PORT = 4223;
    UID = "XYZ"; % Change XYZ to the UID of your Current25 Bricklet

    ipcon = javaObject("com.tinkerforge.IPConnection"); % Create IP connection
    c = javaObject("com.tinkerforge.BrickletCurrent25", UID, ipcon); % Create device object

    ipcon.connect(HOST, PORT); % Connect to brickd
    % Don't use device before ipcon is connected

    % Get threshold callbacks with a debounce time of 10 seconds (10000ms)
    c.setDebouncePeriod(10000);

    % Register current reached callback to function cb_current_reached
    c.addCurrentReachedCallback(@cb_current_reached);

    % Configure threshold for current "greater than 5 A"
    c.setCurrentCallbackThreshold(">", 5*1000, 0);

    input("Press key to exit\n", "s");
    ipcon.disconnect();
end

% Callback function for current reached callback
function cb_current_reached(e)
    fprintf("Current: %g A\n", java2int(e.current)/1000.0);
end

function int = java2int(value)
    if compare_versions(version(), "3.8", "<=")
        int = value.intValue();
    else
        int = value;
    end
end
