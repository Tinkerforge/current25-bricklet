Imports System
Imports Tinkerforge

Module ExampleThreshold
    Const HOST As String = "localhost"
    Const PORT As Integer = 4223
    Const UID As String = "XYZ" ' Change XYZ to the UID of your Current25 Bricklet

    ' Callback subroutine for current reached callback
    Sub CurrentReachedCB(ByVal sender As BrickletCurrent25, ByVal current As Short)
        Console.WriteLine("Current: " + (current/1000.0).ToString() + " A")
    End Sub

    Sub Main()
        Dim ipcon As New IPConnection() ' Create IP connection
        Dim c As New BrickletCurrent25(UID, ipcon) ' Create device object

        ipcon.Connect(HOST, PORT) ' Connect to brickd
        ' Don't use device before ipcon is connected

        ' Get threshold callbacks with a debounce time of 10 seconds (10000ms)
        c.SetDebouncePeriod(10000)

        ' Register current reached callback to subroutine CurrentReachedCB
        AddHandler c.CurrentReachedCallback, AddressOf CurrentReachedCB

        ' Configure threshold for current "greater than 5 A"
        c.SetCurrentCallbackThreshold(">"C, 5*1000, 0)

        Console.WriteLine("Press key to exit")
        Console.ReadLine()
        ipcon.Disconnect()
    End Sub
End Module
