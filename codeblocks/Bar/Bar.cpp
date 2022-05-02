// // Main file of the Project
// // #include <bits/stdc++.h>
// // using namespace std;
// // #include <graphics.h>
// // #include <windows.h>
// // #include <iostream>

// // int main(int arg, char *argv[])
// // {
// //     std::cout << "Hello " << argv[0] << " project" << std::endl;
// //     return 0;
// // }

// #ifndef UNICODE
// #define UNICODE
// #endif

// #include <windows.h>

// LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

// int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow)
// {
//     // Register the window class.
//     const wchar_t CLASS_NAME[] = L"Sample Window Class";

//     WNDCLASS wc = {};

//     wc.lpfnWndProc = WindowProc;
//     wc.hInstance = hInstance;
//     wc.lpszClassName = CLASS_NAME;

//     RegisterClass(&wc);

//     // Create the window.

//     HWND hwnd = CreateWindowEx(
//         0,                           // Optional window styles.
//         CLASS_NAME,                  // Window class
//         L"Learn to Program Windows", // Window text
//         WS_OVERLAPPEDWINDOW,         // Window style

//         // Size and position
//         CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,

//         NULL,      // Parent window
//         NULL,      // Menu
//         hInstance, // Instance handle
//         NULL       // Additional application data
//     );

//     if (hwnd == NULL)
//     {
//         return 0;
//     }

//     ShowWindow(hwnd, nCmdShow);

//     // Run the message loop.

//     MSG msg = {};
//     while (GetMessage(&msg, NULL, 0, 0) > 0)
//     {
//         TranslateMessage(&msg);
//         DispatchMessage(&msg);
//     }

//     return 0;
// }

// LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
// {
//     switch (uMsg)
//     {
//     case WM_DESTROY:
//         PostQuitMessage(0);
//         return 0;

//     case WM_PAINT:
//     {
//         PAINTSTRUCT ps;
//         HDC hdc = BeginPaint(hwnd, &ps);

//         // All painting occurs here, between BeginPaint and EndPaint.

//         FillRect(hdc, &ps.rcPaint, (HBRUSH)(COLOR_WINDOW + 1));

//         EndPaint(hwnd, &ps);
//     }
//         return 0;
//     }
//     return DefWindowProc(hwnd, uMsg, wParam, lParam);
// }

// int main()
// {
//     // Register the window class.
// }

// C Implementation for drawing circle
#include <bits/stdc++.h>
#include <stdio.h>
#include <windows.h>
#include <graphics.h>

// driver code
int main()
{
    // gm is Graphics mode which is
    // a computer display mode that
    // generates image using pixels.
    // DETECT is a macro defined in
    // "graphics.h" header file
    int gd = DETECT, gm;

    // initgraph initializes the
    // graphics system by loading a
    // graphics driver from disk
    initgraph(&gd, &gm, (char *)"");

    // circle function
    circle(250, 200, 50);

    getch();

    // closegraph function closes the
    // graphics mode and deallocates
    // all memory allocated by
    // graphics system .
    closegraph();

    return 0;
}