function matlab_example_threshold()
    import com.tinkerforge.IPConnection;
    import com.tinkerforge.BrickletCurrent25;

    HOST = 'localhost';
    PORT = 4223;
    UID = '555'; % Change to your UID
    
    ipcon = IPConnection(); % Create IP connection
    vc = BrickletCurrent25(UID, ipcon); % Create device object

    ipcon.connect(HOST, PORT); % Connect to brickd
    % Don't use device before ipcon is connected

    % Get threshold callbacks with a debounce time of 10 seconds (10000ms)
    vc.setDebouncePeriod(10000);

    % Register threshold reached callback to function cb_reached
    set(vc, 'CurrentCallback', @(h, e) cb_reached(e));

    % Configure threshold for "greater than 5A" (unit is mA)
    vc.setCurrentCallbackThreshold('>', 5*1000, 0);

    input('Press any key to exit...\n', 's');
    ipcon.disconnect();
end

% Callback for current greater than 5A
function cb_reached(e)
    fprintf('Current is greater than 5A: %g \n', e.current/1000.0);
end
