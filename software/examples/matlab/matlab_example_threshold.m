function matlab_example_threshold()
    import com.tinkerforge.IPConnection;
    import com.tinkerforge.BrickletCurrent25;

    HOST = 'localhost';
    PORT = 4223;
    UID = 'XYZ'; % Change XYZ to the UID of your Current25 Bricklet

    ipcon = IPConnection(); % Create IP connection
    c = handle(BrickletCurrent25(UID, ipcon), 'CallbackProperties'); % Create device object

    ipcon.connect(HOST, PORT); % Connect to brickd
    % Don't use device before ipcon is connected

    % Get threshold callbacks with a debounce time of 10 seconds (10000ms)
    c.setDebouncePeriod(10000);

    % Register current reached callback to function cb_current_reached
    set(c, 'CurrentReachedCallback', @(h, e) cb_current_reached(e));

    % Configure threshold for current "greater than 5 A"
    c.setCurrentCallbackThreshold('>', 5*1000, 0);

    input('Press key to exit\n', 's');
    ipcon.disconnect();
end

% Callback function for current reached callback
function cb_current_reached(e)
    fprintf('Current: %g A\n', e.current/1000.0);
end
