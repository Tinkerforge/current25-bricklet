Imports Tinkerforge

Module ExampleThreshold
    Const HOST As String = "localhost"
    Const PORT As Integer = 4223
    Const UID As String = "XYZ" ' Change to your UID

    ' Callback function for current greater than 5 A (parameter has unit mA)
    Sub CurrentReachedCB(ByVal sender As BrickletCurrent25, ByVal current As Short)
        System.Console.WriteLine("Current: " + (current/1000.0).ToString() + " A")
    End Sub

    Sub Main()
        Dim ipcon As New IPConnection() ' Create IP connection
        Dim c As New BrickletCurrent25(UID, ipcon) ' Create device object

        ipcon.Connect(HOST, PORT) ' Connect to brickd
        ' Don't use device before ipcon is connected

        ' Get threshold callbacks with a debounce time of 10 seconds (10000ms)
        c.SetDebouncePeriod(10000)

        ' Register threshold reached callback to function CurrentReachedCB
        AddHandler c.CurrentReached, AddressOf CurrentReachedCB

        ' Configure threshold for "greater than 5 A" (unit is mA)
        c.SetCurrentCallbackThreshold(">"C, 5*1000, 0)

        System.Console.WriteLine("Press key to exit")
        System.Console.ReadLine()
        ipcon.Disconnect()
    End Sub
End Module
