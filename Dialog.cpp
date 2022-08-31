#include <Windows.h>
#include <tchar.h>

#include "CheatFunctions.h"
#include "Dialog.h"
#include "resource.h"
#include "GUI.h"

void registerModifyDialog(HINSTANCE hInstance) {
	WNDCLASSEX ModifydialogWnd = { 0 };

	ModifydialogWnd.cbSize = sizeof(ModifydialogWnd);
	ModifydialogWnd.hbrBackground = (HBRUSH)COLOR_WINDOW;
	ModifydialogWnd.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_ICON1));
	ModifydialogWnd.hInstance = hInstance;
	ModifydialogWnd.hCursor = LoadCursor(NULL, IDC_ARROW);
	ModifydialogWnd.lpszClassName = TEXT("ModifyDialogClass");
	ModifydialogWnd.lpfnWndProc = ModifyDialogWndProc;

	if (!RegisterClassEx(&ModifydialogWnd)) {
		MessageBox(NULL, TEXT("无法注册窗口类"), TEXT("错误"), MB_OK | MB_ICONERROR);
	}
}

void registerIncreaseDialog(HINSTANCE hInstance) {
	WNDCLASSEX IncreasedialogWnd = { 0 };

	IncreasedialogWnd.cbSize = sizeof(IncreasedialogWnd);
	IncreasedialogWnd.hbrBackground = (HBRUSH)COLOR_WINDOW;
	IncreasedialogWnd.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_ICON1));
	IncreasedialogWnd.hInstance = hInstance;
	IncreasedialogWnd.hCursor = LoadCursor(NULL, IDC_ARROW);
	IncreasedialogWnd.lpszClassName = TEXT("IncreaseDialogClass");
	IncreasedialogWnd.lpfnWndProc = IncreaseDialogWndProc;

	if (!RegisterClassEx(&IncreasedialogWnd)) {
		MessageBox(NULL, TEXT("无法注册窗口类"), TEXT("错误"), MB_OK | MB_ICONERROR);
	}
}

void registerDecreaseDialog(HINSTANCE hInstance) {
	WNDCLASSEX DecreasedialogWnd = { 0 };

	DecreasedialogWnd.cbSize = sizeof(DecreasedialogWnd);
	DecreasedialogWnd.hbrBackground = (HBRUSH)COLOR_WINDOW;
	DecreasedialogWnd.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_ICON1));
	DecreasedialogWnd.hInstance = hInstance;
	DecreasedialogWnd.hCursor = LoadCursor(NULL, IDC_ARROW);
	DecreasedialogWnd.lpszClassName = TEXT("DecreaseDialogClass");
	DecreasedialogWnd.lpfnWndProc = DecreaseDialogWndProc;

	if (!RegisterClassEx(&DecreasedialogWnd)) {
		MessageBox(NULL, TEXT("无法注册窗口类"), TEXT("错误"), MB_OK | MB_ICONERROR);
	}
}

void displayModifyDialog(HWND hwnd, int item) {
	itemToModify = item;

	HWND hModifyDialog = CreateWindowEx(WS_EX_OVERLAPPEDWINDOW, TEXT("ModifyDialogClass"), TEXT("数值修改"), WS_VISIBLE | WS_SYSMENU |WS_CAPTION , CW_USEDEFAULT, CW_USEDEFAULT, 455, 130, hwnd, NULL, NULL, NULL);

	HFONT hFont = (HFONT)GetStockObject(DEFAULT_GUI_FONT);
	hEdit = CreateWindowEx(NULL, TEXT("Edit"), TEXT(""), WS_VISIBLE | WS_CHILD | WS_TABSTOP | WS_BORDER | ES_AUTOHSCROLL, 8, 31, 423, 20, hModifyDialog, NULL, NULL, NULL);
	hOKButton = CreateWindowEx(WS_EX_OVERLAPPEDWINDOW, TEXT("Button"), TEXT("确定"), WS_VISIBLE | WS_CHILD | WS_TABSTOP, 266, 55, 75, 23, hModifyDialog, (HMENU)ENTER_ACTION, NULL, NULL);
	hStatic = CreateWindowEx(NULL, TEXT("Static"), TEXT("输入修改的数值"), WS_VISIBLE | WS_CHILD | WS_GROUP | SS_LEFT, 11, 11, 98, 15, hModifyDialog, NULL, NULL, NULL);
	hCancelButton = CreateWindowEx(WS_EX_OVERLAPPEDWINDOW, TEXT("Button"), TEXT("取消"), WS_VISIBLE | WS_CHILD | WS_TABSTOP, 356, 55, 75, 23, hModifyDialog, (HMENU)CANCEL_ACTION, NULL, NULL);

	SendMessage(hEdit, WM_SETFONT, (WPARAM)hFont, FALSE);
	SendMessage(hOKButton, WM_SETFONT, (WPARAM)hFont, FALSE);
	SendMessage(hStatic, WM_SETFONT, (WPARAM)hFont, FALSE);
	SendMessage(hCancelButton, WM_SETFONT, (WPARAM)hFont, FALSE);
}

void displayIncreaseDialog(HWND hwnd, int item) {
	itemToModify = item;

	HWND hIncreaseDialog = CreateWindowEx(WS_EX_OVERLAPPEDWINDOW, TEXT("IncreaseDialogClass"), TEXT("数值增加"), WS_VISIBLE | WS_SYSMENU | WS_CAPTION, CW_USEDEFAULT, CW_USEDEFAULT, 455, 130, hwnd, NULL, NULL, NULL);

	HFONT hFont = (HFONT)GetStockObject(DEFAULT_GUI_FONT);
	hEdit = CreateWindowEx(NULL, TEXT("Edit"), TEXT(""), WS_VISIBLE | WS_CHILD | WS_TABSTOP | WS_BORDER | ES_AUTOHSCROLL, 8, 31, 423, 20, hIncreaseDialog, NULL, NULL, NULL);
	hOKButton = CreateWindowEx(WS_EX_OVERLAPPEDWINDOW, TEXT("Button"), TEXT("确定"), WS_VISIBLE | WS_CHILD | WS_TABSTOP, 266, 55, 75, 23, hIncreaseDialog, (HMENU)ENTER_ACTION, NULL, NULL);
	hStatic = CreateWindowEx(NULL, TEXT("Static"), TEXT("输入增加的数值"), WS_VISIBLE | WS_CHILD | WS_GROUP | SS_LEFT, 11, 11, 98, 15, hIncreaseDialog, NULL, NULL, NULL);
	hCancelButton = CreateWindowEx(WS_EX_OVERLAPPEDWINDOW, TEXT("Button"), TEXT("取消"), WS_VISIBLE | WS_CHILD | WS_TABSTOP, 356, 55, 75, 23, hIncreaseDialog, (HMENU)CANCEL_ACTION, NULL, NULL);

	SendMessage(hEdit, WM_SETFONT, (WPARAM)hFont, FALSE);
	SendMessage(hOKButton, WM_SETFONT, (WPARAM)hFont, FALSE);
	SendMessage(hStatic, WM_SETFONT, (WPARAM)hFont, FALSE);
	SendMessage(hCancelButton, WM_SETFONT, (WPARAM)hFont, FALSE);
}

void displayDecreaseDialog(HWND hwnd, int item) {
	itemToModify = item;

	HWND hDecreaseDialog = CreateWindowEx(WS_EX_OVERLAPPEDWINDOW, TEXT("DecreaseDialogClass"), TEXT("数值减少"), WS_VISIBLE | WS_SYSMENU | WS_CAPTION, CW_USEDEFAULT, CW_USEDEFAULT, 455, 130, hwnd, NULL, NULL, NULL);

	HFONT hFont = (HFONT)GetStockObject(DEFAULT_GUI_FONT);
	hEdit = CreateWindowEx(NULL, TEXT("Edit"), TEXT(""), WS_VISIBLE | WS_CHILD | WS_TABSTOP | WS_BORDER | ES_AUTOHSCROLL, 8, 31, 423, 20, hDecreaseDialog, NULL, NULL, NULL);
	hOKButton = CreateWindowEx(WS_EX_OVERLAPPEDWINDOW, TEXT("Button"), TEXT("确定"), WS_VISIBLE | WS_CHILD | WS_TABSTOP, 266, 55, 75, 23, hDecreaseDialog, (HMENU)ENTER_ACTION, NULL, NULL);
	hStatic = CreateWindowEx(NULL, TEXT("Static"), TEXT("输入减少的数值"), WS_VISIBLE | WS_CHILD | WS_GROUP | SS_LEFT, 11, 11, 98, 15, hDecreaseDialog, NULL, NULL, NULL);
	hCancelButton = CreateWindowEx(WS_EX_OVERLAPPEDWINDOW, TEXT("Button"), TEXT("取消"), WS_VISIBLE | WS_CHILD | WS_TABSTOP, 356, 55, 75, 23, hDecreaseDialog, (HMENU)CANCEL_ACTION, NULL, NULL);

	SendMessage(hEdit, WM_SETFONT, (WPARAM)hFont, FALSE);
	SendMessage(hOKButton, WM_SETFONT, (WPARAM)hFont, FALSE);
	SendMessage(hStatic, WM_SETFONT, (WPARAM)hFont, FALSE);
	SendMessage(hCancelButton, WM_SETFONT, (WPARAM)hFont, FALSE);
}

LRESULT CALLBACK ModifyDialogWndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam) {
	switch (message) {
	case WM_COMMAND:
		switch (wParam) {
		case CANCEL_ACTION:
			DestroyWindow(hwnd);
			break;
		case ENTER_ACTION: {
			// 对输入框内的数值进行转换
			wchar_t valueToModify_temp[MAX_READING_SPACE];
			GetWindowText(hEdit, valueToModify_temp, MAX_READING_SPACE);
			int valueToModify = _wtoi(valueToModify_temp);

			switch (itemToModify) {
			case VALUEOFSUN:
				modifyNumberOfSun(g_processHandle, valueToModify);
				break;
			case VALUEOFCOIN:
				modifyNumberOfCoin(g_processHandle, valueToModify);
				break;
			case VALUEOFFERTILIZER:
				modifyNumberOfFertilizer(g_processHandle, valueToModify);
				break;
			case VALUEOFBUGSPRAY:
				modifyNumberOfBugSpray(g_processHandle, valueToModify);
				break;
			case VALUEOFCHOCOLATE:
				modifyNumberOfChocolate(g_processHandle, valueToModify);
				break;
			case VALUEOFTREEFOOD:
				modifyNumberOfTreeFood(g_processHandle, valueToModify);
				break;
			}
		}
			DestroyWindow(hwnd);
			break;
		}
		break;
	case WM_CLOSE:
		DestroyWindow(hwnd);
		break;
	default:
		return DefWindowProc(hwnd, message, wParam, lParam);
	}
}

LRESULT CALLBACK IncreaseDialogWndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam) {
	switch (message) {
	case WM_COMMAND:
		switch (wParam) {
		case CANCEL_ACTION:
			DestroyWindow(hwnd);
			break;
		case ENTER_ACTION: {
			// 对输入框内的数值进行转换
			wchar_t valueToIncrease_temp[MAX_READING_SPACE];
			GetWindowText(hEdit, valueToIncrease_temp, MAX_READING_SPACE);
			int valueToIncrease = _wtoi(valueToIncrease_temp);

			switch (itemToModify) {
			case VALUEOFSUN:
				increaseSun(g_processHandle, valueToIncrease);
				break;
			case VALUEOFCOIN:
				increaseCoin(g_processHandle, valueToIncrease);
				break;
			case VALUEOFFERTILIZER:
				increaseFertilizer(g_processHandle, valueToIncrease);
				break;
			case VALUEOFBUGSPRAY:
				increaseBugSpray(g_processHandle, valueToIncrease);
				break;
			case VALUEOFCHOCOLATE:
				increaseChocolate(g_processHandle, valueToIncrease);
				break;
			case VALUEOFTREEFOOD:
				increaseTreeFood(g_processHandle, valueToIncrease);
				break;
			}
			DestroyWindow(hwnd);
			break;
		}
		}
		break;
	case WM_CLOSE:
		DestroyWindow(hwnd);
		break;
	default:
		return DefWindowProc(hwnd, message, wParam, lParam);
	}
}

LRESULT CALLBACK DecreaseDialogWndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam) {
	switch (message) {
	case WM_COMMAND:
		switch (wParam) {
		case CANCEL_ACTION:
			DestroyWindow(hwnd);
			break;
		case ENTER_ACTION: {
			// 对输入框内的数值进行转换
			wchar_t valueToDecrease_temp[MAX_READING_SPACE];
			GetWindowText(hEdit, valueToDecrease_temp, MAX_READING_SPACE);
			int valueToDecrease = _wtoi(valueToDecrease_temp);

			switch (itemToModify) {
			case VALUEOFSUN:
				decreaseSun(g_processHandle, valueToDecrease);
				break;
			case VALUEOFCOIN:
				decreaseCoin(g_processHandle, valueToDecrease);
				break;
			case VALUEOFFERTILIZER:
				decreaseFertilizer(g_processHandle, valueToDecrease);
				break;
			case VALUEOFBUGSPRAY:
				decreaseBugSpray(g_processHandle, valueToDecrease);
				break;
			case VALUEOFCHOCOLATE:
				decreaseChocolate(g_processHandle, valueToDecrease);
				break;
			case VALUEOFTREEFOOD:
				decreaseTreeFood(g_processHandle, valueToDecrease);
				break;
			}
			DestroyWindow(hwnd);
			break;
		}
	}
		break;
	case WM_CLOSE:
		DestroyWindow(hwnd);
		break;
	default:
		return DefWindowProc(hwnd, message, wParam, lParam);
	}
}