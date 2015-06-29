function octave_example_threshold()
    more off;

    HOST = "localhost";
    PORT = 4223;
    UID = "555"; % Change to your UID

    ipcon = java_new("com.tinkerforge.IPConnection"); % Create IP connection
    vc = java_new("com.tinkerforge.BrickletCurrent25", UID, ipcon); % Create device object

    ipcon.connect(HOST, PORT); % Connect to brickd
    % Don't use device before ipcon is connected

    % Get threshold callbacks with a debounce time of 10 seconds (10000ms)
    vc.setDebouncePeriod(10000);

    % Register threshold reached callback to function cb_reached
    vc.addCurrentReachedCallback(@cb_reached);

    % Configure threshold for "greater than 5A" (unit is mA)
    vc.setCurrentCallbackThreshold(vc.THRESHOLD_OPTION_GREATER, 5*1000, 0);

    input("Press any key to exit...\n", "s");
    ipcon.disconnect();
end

% Callback for current greater than 5A
function cb_reached(e)
    fprintf("Current is greater than 5A: %g \n", short2int(e.current)/1000);
end

function int = short2int(short)
    if compare_versions(version(), "3.8", "<=")
        int = short.intValue();
    else
        int = short;
    end
end
