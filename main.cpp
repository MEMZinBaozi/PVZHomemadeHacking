#include <Windows.h>
#include <tchar.h>

#include "GUI.h"
#include "Dialog.h"
#include "resource.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	WNDCLASSEX wndClass = { 0 };
	static TCHAR windowClassName[] = TEXT("MyWindowClass");
	static TCHAR windowTitleName[] = TEXT("植物大战僵尸修改器 By MEMZinBaozi");

	wndClass.cbSize = sizeof(WNDCLASSEX);
	wndClass.style = CS_VREDRAW | CS_HREDRAW;
	wndClass.hbrBackground = (HBRUSH)COLOR_WINDOW;
	wndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndClass.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_ICON1));
	wndClass.hInstance = hInstance;
	wndClass.lpszClassName = windowClassName;
	wndClass.lpfnWndProc = WndProc;

	if (!RegisterClassEx(&wndClass)) {
		MessageBox(NULL, TEXT("Cannot register a window class."), TEXT("An error occured"), MB_OK | MB_ICONERROR);
	}

	registerModifyDialog(hInstance);
	registerIncreaseDialog(hInstance);
	registerDecreaseDialog(hInstance);

	HWND hwnd = CreateWindowEx(WS_EX_OVERLAPPEDWINDOW, windowClassName, windowTitleName, DS_3DLOOK | DS_CENTER | DS_MODALFRAME | DS_SHELLFONT | WS_CAPTION | WS_VISIBLE | WS_SYSMENU
		, CW_USEDEFAULT, CW_USEDEFAULT, 272, 250, NULL, NULL, NULL, NULL);

	if (!hwnd) {
		MessageBox(NULL, TEXT("Cannot create a window."), TEXT("An error occured"), MB_OK | MB_ICONERROR);
	}

	ShowWindow(hwnd, nCmdShow);
	UpdateWindow(hwnd);

	MSG msg = { 0 };

	while (GetMessage(&msg, NULL, NULL, NULL)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return msg.wParam;
}

