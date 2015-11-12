function matlab_example_simple()
    import com.tinkerforge.IPConnection;
    import com.tinkerforge.BrickletCurrent25;

    HOST = 'localhost';
    PORT = 4223;
    UID = 'XYZ'; % Change to your UID

    ipcon = IPConnection(); % Create IP connection
    c = handle(BrickletCurrent25(UID, ipcon), 'CallbackProperties'); % Create device object

    ipcon.connect(HOST, PORT); % Connect to brickd
    % Don't use device before ipcon is connected

    % Get current current (unit is mA)
    current = c.getCurrent();
    fprintf('Current: %g A\n', current/1000.0);

    input('Press key to exit\n', 's');
    ipcon.disconnect();
end
