program ExampleSimple;

{$ifdef MSWINDOWS}{$apptype CONSOLE}{$endif}
{$ifdef FPC}{$mode OBJFPC}{$H+}{$endif}

uses
  SysUtils, IPConnection, BrickletCurrent25;

type
  TExample = class
  private
    ipcon: TIPConnection;
    c: TBrickletCurrent25;
  public
    procedure Execute;
  end;

const
  HOST = 'localhost';
  PORT = 4223;
  UID = '9yW'; { Change to your UID }

var
  e: TExample;

procedure TExample.Execute;
var current: smallint;
begin
  { Create IP connection }
  ipcon := TIPConnection.Create;

  { Create device object }
  c := TBrickletCurrent25.Create(UID, ipcon);

  { Connect to brickd }
  ipcon.Connect(HOST, PORT);
  { Don't use device before ipcon is connected }

  { Get current current (unit is mA) }
  current := c.GetCurrent;
  WriteLn(Format('Current: %f A', [current/1000.0]));

  WriteLn('Press key to exit');
  ReadLn;
  ipcon.Destroy; { Calls ipcon.Disconnect internally }
end;

begin
  e := TExample.Create;
  e.Execute;
  e.Destroy;
end.
