#include "include/window.h"
#include "include/input.h"
#include "include/render.h"
#include "config.h"

LRESULT CALLBACK WindowProc(HWND hwnd, UINT msg, WPARAM w_param, LPARAM l_param) {
    switch (msg) {
        case WM_CREATE:
            CreateEditControl(hwnd);
            return 0;

        case WM_DESTROY:
            PostQuitMessage(0);
            return 0;  

        case WM_PAINT:
            PaintResults(hwnd);
            return 0;
    }
    return DefWindowProc(hwnd, msg, w_param, l_param);
}

HWND CreateMainWindow(HINSTANCE hInstance) {
    const wchar_t CLASS_NAME[] = L"WinfiWindowClass";

    WNDCLASS wc = {0};
    wc.lpfnWndProc   = WindowProc;
    wc.hInstance     = hInstance;
    wc.lpszClassName = CLASS_NAME;
    wc.hCursor       = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground = (HBRUSH) (COLOR_WINDOW + 1);

    RegisterClass(&wc);

    //center window
    int screen_width = GetSystemMetrics(SM_CXSCREEN);
    int screen_height = GetSystemMetrics(SM_CYSCREEN);
    
    int x_pos = (screen_width - WINDOW_WIDTH) / 2;
    int y_pos = (screen_height - WINDOW_HEIGHT) / 2;

    return CreateWindowEx(
        WS_EX_TOPMOST,
        CLASS_NAME,
        L"winfi",
        WS_POPUP,
        x_pos, y_pos,
        WINDOW_WIDTH, WINDOW_HEIGHT,
        NULL, NULL,
        hInstance, NULL
    );
}