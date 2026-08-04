#include <windows.h>

#define WINDOW_WIDTH  500
#define WINDOW_HEIGHT 300
#define MAX_RESULTS 5

const wchar_t* exec[MAX_RESULTS] = {
    L"Notepad",
    L"Wubwub",
    L"Discord",
    L"Ping",
    L"Soundcloud"
};

LRESULT CALLBACK WindowProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    switch (msg) {
        case WM_CREATE:
            HINSTANCE hInstance = (HINSTANCE) GetWindowLongPtr(hwnd, GWLP_HINSTANCE);

            HWND hEdit = CreateWindowEx(
                0,
                L"EDIT",
                L"",
                WS_CHILD | WS_VISIBLE | WS_BORDER,
                10, 10,
                WINDOW_WIDTH - 20, 30,
                hwnd,
                (HMENU) 1,
                hInstance,
                NULL
            );
            return 0;

        case WM_DESTROY:
            PostQuitMessage(0);
            return 0;  
        
        case WM_KEYDOWN:
            if (wParam == VK_ESCAPE) {
                DestroyWindow(hwnd);
            }
            return 0;

        case WM_PAINT: {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hwnd, &ps);

            int row_height = 30;
            int start_y = 50;

            for (int i = 0; i < MAX_RESULTS; i++) {
                RECT row_rect = {
                    10, start_y + (i * row_height),
                    WINDOW_WIDTH - 10,
                    start_y + ((i + 1) * row_height)};

                DrawText(hdc, exec[i], -1, &row_rect, DT_LEFT | DT_VCENTER | DT_SINGLELINE);
            }

            EndPaint(hwnd, &ps);
            return 0;
        }
    }
    return DefWindowProc(hwnd, msg, wParam, lParam);
}

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPWSTR lpCmdLine, int nCmdShow) {
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

    HWND hwnd = CreateWindowEx(
        WS_EX_TOPMOST,
        CLASS_NAME,
        L"winfi",
        WS_POPUP,
        x_pos, y_pos,
        WINDOW_WIDTH, WINDOW_HEIGHT,
        NULL, NULL,
        hInstance, NULL
    );

    if (hwnd == NULL) {
        return 0;
    }

    ShowWindow(hwnd, nCmdShow);

    MSG msg = {0};
    while (GetMessage(&msg, NULL, 0, 0)) {
        if (msg.wParam == VK_ESCAPE) {
            DestroyWindow(hwnd);
            continue;
        }

        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return 0;
}