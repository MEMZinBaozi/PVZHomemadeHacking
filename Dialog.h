#pragma once
#include <Windows.h>

// 宏定义
#define MAX_READING_SPACE 100

#define CANCEL_ACTION 1
#define ENTER_ACTION 2

// 数值修改宏定义
#define VALUEOFSUN 1
#define VALUEOFCOIN 2
#define VALUEOFFERTILIZER 3
#define VALUEOFBUGSPRAY 4
#define VALUEOFCHOCOLATE 5
#define VALUEOFTREEFOOD 6

int itemToModify;

// 窗口组件
HWND hEdit;
HWND hOKButton;
HWND hStatic;
HWND hCancelButton;

// 对话框类注册
void registerModifyDialog(HINSTANCE hInstance);
void registerIncreaseDialog(HINSTANCE hInstance);
void registerDecreaseDialog(HINSTANCE hInstance);

void displayModifyDialog(HWND hwnd, int item);
void displayIncreaseDialog(HWND hwnd, int item);
void displayDecreaseDialog(HWND hwnd, int item);

LRESULT CALLBACK ModifyDialogWndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK IncreaseDialogWndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK DecreaseDialogWndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);