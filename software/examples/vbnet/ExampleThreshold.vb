Imports Tinkerforge

Module ExampleThreshold
    Const HOST As String = "localhost"
    Const PORT As Integer = 4223
    Const UID As String = "9yW" ' Change to your UID

    ' Callback for current greater than 5A
    Sub ReachedCB(ByVal sender As BrickletCurrent25, ByVal current As Short)
        System.Console.WriteLine("Current is greater than 5A: " + (current/1000.0).ToString() + "A")
    End Sub

    Sub Main()
        Dim ipcon As New IPConnection() ' Create IP connection
        Dim c25 As New BrickletCurrent25(UID, ipcon) ' Create device object

        ipcon.Connect(HOST, PORT) ' Connect to brickd
        ' Don't use device before ipcon is connected

        ' Get threshold callbacks with a debounce time of 10 seconds (10000ms)
        c25.SetDebouncePeriod(10000)

        ' Register threshold reached callback to function ReachedCB
        AddHandler c25.CurrentReached, AddressOf ReachedCB

        ' Configure threshold for "greater than 5A" (unit is mA)
        c25.SetCurrentCallbackThreshold(">"C, 5*1000, 0)

        System.Console.WriteLine("Press key to exit")
        System.Console.ReadLine()
        ipcon.Disconnect()
    End Sub
End Module
