Imports System
Imports Tinkerforge

Module ExampleCallback
    Const HOST As String = "localhost"
    Const PORT As Integer = 4223
    Const UID As String = "XYZ" ' Change XYZ to the UID of your Current25 Bricklet

    ' Callback subroutine for current callback
    Sub CurrentCB(ByVal sender As BrickletCurrent25, ByVal current As Short)
        Console.WriteLine("Current: " + (current/1000.0).ToString() + " A")
    End Sub

    Sub Main()
        Dim ipcon As New IPConnection() ' Create IP connection
        Dim c As New BrickletCurrent25(UID, ipcon) ' Create device object

        ipcon.Connect(HOST, PORT) ' Connect to brickd
        ' Don't use device before ipcon is connected

        ' Register current callback to subroutine CurrentCB
        AddHandler c.CurrentCallback, AddressOf CurrentCB

        ' Set period for current callback to 1s (1000ms)
        ' Note: The current callback is only called every second
        '       if the current has changed since the last call!
        c.SetCurrentCallbackPeriod(1000)

        Console.WriteLine("Press key to exit")
        Console.ReadLine()
        ipcon.Disconnect()
    End Sub
End Module
