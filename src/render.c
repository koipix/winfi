#include "include/render.h"
#include "include/render.h"
#include "config.h"

//sample data for now :3
static const wchar_t *exec[MAX_RESULTS] = {
    L"Notepad",
    L"Wubwub",
    L"Discord",
    L"Ping",
    L"Soundcloud"
};

void PaintResults(HWND hwnd) {
    PAINTSTRUCT ps;
    HDC hdc = BeginPaint(hwnd, &ps);

    for (int i = 0; i < MAX_RESULTS; i++) {
        RECT row_rect = {
            10, RESULTS_START_Y + (i * ROW_HEIGHT),
            WINDOW_WIDTH - 10,
            RESULTS_START_Y + ((i + 1) * ROW_HEIGHT)
        };

        DrawText(hdc, exec[i], -1, &row_rect , DT_LEFT | DT_VCENTER | DT_SINGLELINE);
    }

    EndPaint(hwnd, &ps);
}