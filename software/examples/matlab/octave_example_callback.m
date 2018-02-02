function octave_example_callback()
    more off;

    HOST = "localhost";
    PORT = 4223;
    UID = "XYZ"; % Change XYZ to the UID of your Current25 Bricklet

    ipcon = javaObject("com.tinkerforge.IPConnection"); % Create IP connection
    c = javaObject("com.tinkerforge.BrickletCurrent25", UID, ipcon); % Create device object

    ipcon.connect(HOST, PORT); % Connect to brickd
    % Don't use device before ipcon is connected

    % Register current callback to function cb_current
    c.addCurrentCallback(@cb_current);

    % Set period for current callback to 1s (1000ms)
    % Note: The current callback is only called every second
    %       if the current has changed since the last call!
    c.setCurrentCallbackPeriod(1000);

    input("Press key to exit\n", "s");
    ipcon.disconnect();
end

% Callback function for current callback
function cb_current(e)
    fprintf("Current: %g A\n", java2int(e.current)/1000.0);
end

function int = java2int(value)
    if compare_versions(version(), "3.8", "<=")
        int = value.intValue();
    else
        int = value;
    end
end
