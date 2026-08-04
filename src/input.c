#include "include/input.h"
#include "config.h"

HWND CreateEditControl(HWND parent) {
    HINSTANCE hInstance = (HINSTANCE) GetWindowLongPtr(parent, GWLP_HINSTANCE);

    return CreateWindowEx(
        0,
        L"EDIT",
        L"",
        WS_CHILD | WS_VISIBLE | WS_BORDER,
        10, 10,
        WINDOW_WIDTH - 20, 30,
        parent,
        (HMENU) 1,
        hInstance,
        NULL
    );
}