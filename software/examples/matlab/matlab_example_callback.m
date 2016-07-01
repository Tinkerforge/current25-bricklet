function matlab_example_callback()
    import com.tinkerforge.IPConnection;
    import com.tinkerforge.BrickletCurrent25;

    HOST = 'localhost';
    PORT = 4223;
    UID = 'XYZ'; % Change XYZ to the UID of your Current25 Bricklet

    ipcon = IPConnection(); % Create IP connection
    c = handle(BrickletCurrent25(UID, ipcon), 'CallbackProperties'); % Create device object

    ipcon.connect(HOST, PORT); % Connect to brickd
    % Don't use device before ipcon is connected

    % Register current callback to function cb_current
    set(c, 'CurrentCallback', @(h, e) cb_current(e));

    % Set period for current callback to 1s (1000ms)
    % Note: The current callback is only called every second
    %       if the current has changed since the last call!
    c.setCurrentCallbackPeriod(1000);

    input('Press key to exit\n', 's');
    ipcon.disconnect();
end

% Callback function for current callback (parameter has unit mA)
function cb_current(e)
    fprintf('Current: %g A\n', e.current/1000.0);
end
