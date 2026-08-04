#include <windows.h>
#include "include/window.h"

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPWSTR lpCmdLine, int nCmdShow) {
    HWND hwnd = CreateMainWindow(hInstance);
 
    if (hwnd == NULL) {
        return 0;
    }
 
    ShowWindow(hwnd, nCmdShow);
 
    MSG msg = {0};
    while (GetMessage(&msg, NULL, 0, 0)) {

        //closes if esc is pressed
        if (msg.message == WM_KEYDOWN && msg.wParam == VK_ESCAPE) {
            DestroyWindow(hwnd);
            continue;
        }

        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}