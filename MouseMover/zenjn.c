/* ZenJN - nudges the mouse cursor 1 pixel every 5 seconds.
 * Moves right 1px, then left 1px on the next tick, so the cursor
 * stays roughly in place instead of drifting over time.
 * Build: x86_64-w64-mingw32-gcc -O2 -o ZenJN.exe zenjn.c -luser32
 */
#include <windows.h>

int main(void)
{
    BOOL right = TRUE;
    POINT p;
    for (;;) {
        if (GetCursorPos(&p))
            SetCursorPos(p.x + (right ? 1 : -1), p.y);
        right = !right;
        Sleep(5000); /* 5 seconds */
    }
    return 0;
}
