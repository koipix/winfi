#include <windows.h>

#ifndef WINDOW_H
#define WINDOW_H

//message handler windows called
LRESULT CALLBACK WindowProc(HWND hwnd, UINT msg, WPARAM w_param, LPARAM l_param);

//register window class and returns window handle
HWND CreateMainWindow(HINSTANCE h_instance);

#endif