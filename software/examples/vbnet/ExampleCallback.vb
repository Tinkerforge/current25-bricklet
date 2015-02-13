Imports Tinkerforge

Module ExampleCallback
    Const HOST As String = "localhost"
    Const PORT As Integer = 4223
    Const UID As String = "ABC" ' Change to your UID

    ' Callback function for current callback (parameter has unit mA)
    Sub CurrentCB(ByVal sender As BrickletCurrent25, ByVal current As Short)
        System.Console.WriteLine("Current: " + (current/1000.0).ToString() + " A")
    End Sub

    Sub Main()
        Dim ipcon As New IPConnection() ' Create IP connection
        Dim c25 As New BrickletCurrent25(UID, ipcon) ' Create device object

        ipcon.Connect(HOST, PORT) ' Connect to brickd
        ' Don't use device before ipcon is connected

        ' Set Period for current callback to 1s (1000ms)
        ' Note: The current callback is only called every second if the 
        '       current has changed since the last call!
        c25.SetCurrentCallbackPeriod(1000)

        ' Register current callback to function CurrentCB
        AddHandler c25.Current, AddressOf CurrentCB

        System.Console.WriteLine("Press key to exit")
        System.Console.ReadLine()
        ipcon.Disconnect()
    End Sub
End Module
