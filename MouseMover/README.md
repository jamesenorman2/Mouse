# MouseMover

A tiny utility that nudges the mouse cursor 1 pixel every 5 seconds to keep a
session active. It moves right 1px, then left 1px on the next tick, so the
cursor doesn't drift across the screen over time.

## Option A — PowerShell (no build needed)

```
powershell -ExecutionPolicy Bypass -File MouseMover.ps1
```

## Option B — compile the C# to an .exe

Every Windows machine with .NET Framework already has the C# compiler. From a
Command Prompt in this folder:

```
%WINDIR%\Microsoft.NET\Framework64\v4.0.30319\csc.exe /target:exe /out:MouseMover.exe Program.cs
```

Then run `MouseMover.exe`.

If you have the .NET SDK instead, `dotnet run` works with a standard console
project (`dotnet new console`, then drop in `Program.cs`).

## Changing it

- Interval: edit `IntervalMs` in `Program.cs` (or `Start-Sleep -Seconds` in the
  `.ps1`).
- Movement distance: change the `1` / `-1` offsets.
