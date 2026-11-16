using System;
using System.Runtime.InteropServices;
using System.Threading;

// Minimal mouse mover: nudges the cursor 1 pixel every 5 seconds.
// It moves right 1px on one tick and left 1px on the next, so the
// cursor stays roughly where it was instead of drifting over time.
class Program
{
    [DllImport("user32.dll")]
    static extern bool GetCursorPos(out POINT p);

    [DllImport("user32.dll")]
    static extern bool SetCursorPos(int x, int y);

    struct POINT { public int X; public int Y; }

    const int IntervalMs = 5000; // 5 seconds

    static void Main()
    {
        Console.WriteLine("Mouse mover running (1px every 5s). Press Ctrl+C to stop.");
        bool right = true;
        while (true)
        {
            POINT p;
            if (GetCursorPos(out p))
            {
                SetCursorPos(p.X + (right ? 1 : -1), p.Y);
                right = !right;
            }
            Thread.Sleep(IntervalMs);
        }
    }
}
