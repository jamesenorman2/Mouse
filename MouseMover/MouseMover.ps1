# MouseMover.ps1 - nudges the cursor 1px every 5 seconds. No compiling needed.
# Run with:  powershell -ExecutionPolicy Bypass -File MouseMover.ps1
Add-Type -AssemblyName System.Windows.Forms
Write-Host "Mouse mover running (1px every 5s). Press Ctrl+C to stop."
$right = $true
while ($true) {
    $p = [System.Windows.Forms.Cursor]::Position
    $dx = if ($right) { 1 } else { -1 }
    [System.Windows.Forms.Cursor]::Position = New-Object System.Drawing.Point(($p.X + $dx), $p.Y)
    $right = -not $right
    Start-Sleep -Seconds 5
}
