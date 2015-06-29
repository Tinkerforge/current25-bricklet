function octave_example_simple()
    more off;

    HOST = "localhost";
    PORT = 4223;
    UID = "555"; % Change to your UID

    ipcon = java_new("com.tinkerforge.IPConnection"); % Create IP connection
    vc = java_new("com.tinkerforge.BrickletCurrent25", UID, ipcon); % Create device object

    ipcon.connect(HOST, PORT); % Connect to brickd
    % Don't use device before ipcon is connected

    % Get current current (unit is mA)
    current = vc.getCurrent();
    fprintf("Current: %g A\n", short2int(current)/1000.0);

    input("Press any key to exit...\n", "s");
    ipcon.disconnect();
end

function int = short2int(short)
    if compare_versions(version(), "3.8", "<=")
        int = short.intValue();
    else
        int = short;
    end
end
