/* ZenJN (GUI) - nudges the mouse cursor 1 pixel every 5 seconds.
 * Runs as a normal windowed app: no console window, shows in the taskbar.
 * Right 1px then left 1px each tick, so the cursor stays in place.
 * Build: x86_64-w64-mingw32-gcc -O2 -mwindows -o ZenJN.exe zenjn_gui.c -luser32
 */
#include <windows.h>

#define TIMER_ID 1
#define INTERVAL 5000  /* 5 seconds */

static LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp)
{
    static BOOL right = TRUE;
    switch (msg) {
    case WM_CREATE:
        CreateWindowW(L"STATIC", L"ZenJN is active\r\nMoving cursor 1px every 5 seconds.\r\nClose this window to stop.",
                      WS_CHILD | WS_VISIBLE, 15, 15, 300, 80, hwnd, NULL, NULL, NULL);
        SetTimer(hwnd, TIMER_ID, INTERVAL, NULL);
        return 0;
    case WM_TIMER: {
        POINT p;
        if (GetCursorPos(&p))
            SetCursorPos(p.x + (right ? 1 : -1), p.y);
        right = !right;
        return 0;
    }
    case WM_DESTROY:
        KillTimer(hwnd, TIMER_ID);
        PostQuitMessage(0);
        return 0;
    }
    return DefWindowProcW(hwnd, msg, wp, lp);
}

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrev, LPSTR cmd, int show)
{
    (void)hPrev; (void)cmd;
    WNDCLASSW wc = {0};
    wc.lpfnWndProc = WndProc;
    wc.hInstance = hInst;
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wc.lpszClassName = L"ZenJNWindow";
    RegisterClassW(&wc);

    HWND hwnd = CreateWindowW(L"ZenJNWindow", L"ZenJN",
        WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX,
        CW_USEDEFAULT, CW_USEDEFAULT, 350, 160,
        NULL, NULL, hInst, NULL);
    if (!hwnd) return 1;

    ShowWindow(hwnd, show);
    UpdateWindow(hwnd);

    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0) > 0) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return 0;
}
