#include <Windows.h>
#include <tchar.h>

#include "CheatFunctions.h"
#include "Dialog.h"
#include "GUI.h"

DWORD monitorGameProcess(LPVOID lpThreadParameter) {
	while (1) {
		HWND hGameHandle = FindWindow(_T("MainWindow"), _T("Plants vs. Zombies"));
		if (hGameHandle == NULL) {
			// 当游戏进程未运行时，直接禁用按钮、菜单：
			EnableMenuItem(hMenu, (UINT)hModifyMenu, MF_DISABLED);
			EnableMenuItem(hMenu, (UINT)hChangeMenu, MF_DISABLED);
			EnableWindow(hNoCoolingDownTime, FALSE);
			EnableWindow(hSunNotDecrease, FALSE);
			EnableWindow(hKillZombiesImmediately, FALSE);
			EnableWindow(hInfiniteSun, FALSE);
			EnableWindow(hInfiniteCoin, FALSE);
			EnableWindow(hFeelFreePlantPlants, FALSE);

			isSunNotDecrease = FALSE;
			isNoCoolingDownTime = FALSE;
			isKillZombiesImmediately = FALSE;
			isFeelFreePlantPlants = FALSE;

			SetWindowText(hSunNotDecrease, TEXT("阳光不减少"));
			SetWindowText(hNoCoolingDownTime, TEXT("植物无冷却时间"));
			SetWindowText(hKillZombiesImmediately, TEXT("僵尸一键秒杀"));
			SetWindowText(hFeelFreePlantPlants, TEXT("植物堆叠"));
		}
		else {
			// 反之亦然
			EnableMenuItem(hMenu, (UINT)hModifyMenu, MF_ENABLED);
			EnableMenuItem(hMenu, (UINT)hChangeMenu, MF_ENABLED);
			EnableWindow(hNoCoolingDownTime, TRUE);
			EnableWindow(hSunNotDecrease, TRUE);
			EnableWindow(hKillZombiesImmediately, TRUE);
			EnableWindow(hInfiniteSun, TRUE);
			EnableWindow(hInfiniteCoin, TRUE);
			EnableWindow(hFeelFreePlantPlants, TRUE);

			DWORD gameProcess_pid;
			GetWindowThreadProcessId(hGameHandle, &gameProcess_pid);
			g_processHandle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, gameProcess_pid);
		}
		Sleep(1000);
	}
	return NULL;
}


void addMenu(HWND hwnd) {
	// 主要菜单
	AppendMenu(hModifyMenu, MF_POPUP, (UINT_PTR)hModifyValueMenu, TEXT("数值修改"));
	AppendMenu(hModifyMenu, MF_POPUP, (UINT_PTR)hInfiniteValueMenu, TEXT("数值无限"));
	AppendMenu(hModifyMenu, MF_POPUP, (UINT_PTR)hIncreaseValueMenu, TEXT("数值增加"));
	AppendMenu(hModifyMenu, MF_POPUP, (UINT_PTR)hDecreaseValueMenu, TEXT("数值减少"));
	AppendMenu(hModifyMenu, MF_POPUP, (UINT_PTR)hClearValueMenu, TEXT("数值清零"));

	// 数值修改菜单
	AppendMenu(hModifyValueMenu, MF_STRING, MODIFYSUN, TEXT("修改阳光数值"));
	AppendMenu(hModifyValueMenu, MF_STRING, MODIFYCOIN, TEXT("修改金币数值"));
	AppendMenu(hModifyValueMenu, MF_STRING, MODIFYFERTILIZER, TEXT("修改肥料数值"));
	AppendMenu(hModifyValueMenu, MF_STRING, MODIFYBUGSPRAY, TEXT("修改杀虫剂数值"));
	AppendMenu(hModifyValueMenu, MF_STRING, MODIFYCHOCOLATE, TEXT("修改巧克力数值"));
	AppendMenu(hModifyValueMenu, MF_STRING, MODIFYTREEFOOD, TEXT("修改树肥数值"));

	// 数值无限菜单
	AppendMenu(hInfiniteValueMenu, MF_STRING, INFINITESUN, TEXT("无限阳光"));
	AppendMenu(hInfiniteValueMenu, MF_STRING, INFINITECOIN, TEXT("无限金币"));
	AppendMenu(hInfiniteValueMenu, MF_STRING, INFINITEFERTILIZER, TEXT("无限肥料"));
	AppendMenu(hInfiniteValueMenu, MF_STRING, INFINITEBUGSPRAY, TEXT("无限杀虫剂"));
	AppendMenu(hInfiniteValueMenu, MF_STRING, INFINITECHOCOLATE, TEXT("无限巧克力"));
	AppendMenu(hInfiniteValueMenu, MF_STRING, INFINITETREEFOOD, TEXT("无限树肥"));

	// 数值增加菜单
	AppendMenu(hIncreaseValueMenu, MF_STRING, INCREASESUN, TEXT("增加阳光数值"));
	AppendMenu(hIncreaseValueMenu, MF_STRING, INCREASECOIN, TEXT("增加金币数值"));
	AppendMenu(hIncreaseValueMenu, MF_STRING, INCREASEFERTILIZER, TEXT("增加肥料数值"));
	AppendMenu(hIncreaseValueMenu, MF_STRING, INCREASEBUGSPRAY, TEXT("增加杀虫剂数值"));
	AppendMenu(hIncreaseValueMenu, MF_STRING, INCREASECHOCOLATE, TEXT("增加巧克力数值"));
	AppendMenu(hIncreaseValueMenu, MF_STRING, INCREASETREEFOOD, TEXT("增加树肥数值"));

	// 数值减少菜单
	AppendMenu(hDecreaseValueMenu, MF_STRING, DECREASESUN, TEXT("减少阳光数值"));
	AppendMenu(hDecreaseValueMenu, MF_STRING, DECREASECOIN, TEXT("减少金币数值"));
	AppendMenu(hDecreaseValueMenu, MF_STRING, DECREASEFERTILIZER, TEXT("减少肥料数值"));
	AppendMenu(hDecreaseValueMenu, MF_STRING, DECREASEBUGSPRAY, TEXT("减少杀虫剂数值"));
	AppendMenu(hDecreaseValueMenu, MF_STRING, DECREASECHOCOLATE, TEXT("减少巧克力数值"));
	AppendMenu(hDecreaseValueMenu, MF_STRING, DECREASETREEFOOD, TEXT("减少树肥数值"));

	// 数值清零菜单
	AppendMenu(hClearValueMenu, MF_STRING, CLEARSUN, TEXT("清零阳光数值"));
	AppendMenu(hClearValueMenu, MF_STRING, CLEARCOIN, TEXT("清零金币数值"));
	AppendMenu(hClearValueMenu, MF_STRING, CLEARFERTILIZER, TEXT("清零肥料数值"));
	AppendMenu(hClearValueMenu, MF_STRING, CLEARBUGSPRAY, TEXT("清零杀虫剂数值"));
	AppendMenu(hClearValueMenu, MF_STRING, CLEARCHOCOLATE, TEXT("清零巧克力数值"));
	AppendMenu(hClearValueMenu, MF_STRING, CLEARTREEFOOD, TEXT("清零树肥数值"));

	// 常用功能菜单
	AppendMenu(hChangeMenu, MF_STRING, NOCOOLINGDOWNTIME, TEXT("植物无冷却时间"));
	AppendMenu(hChangeMenu, MF_STRING, SUNNOTDECREASE, TEXT("阳光不减少"));
	AppendMenu(hChangeMenu, MF_STRING, KILLZOMBIESIMMEDIATELY, TEXT("僵尸一键秒杀"));
	AppendMenu(hChangeMenu, MF_STRING, INFINITESUN, TEXT("无限阳光"));
	AppendMenu(hChangeMenu, MF_STRING, INFINITECOIN, TEXT("无限金币"));
	AppendMenu(hChangeMenu, MF_STRING, FEELFREEPLANTPLANTS, TEXT("植物堆叠"));

	AppendMenu(hMenu, MF_POPUP, (UINT_PTR)hModifyMenu, TEXT("物品数量修改"));
	AppendMenu(hMenu, MF_POPUP, (UINT_PTR)hChangeMenu, TEXT("常用功能")); 
	SetMenu(hwnd, hMenu);
}

void addControlComponet(HWND hwnd) {
	HFONT hFont = (HFONT)GetStockObject(DEFAULT_GUI_FONT);

	hNoCoolingDownTime = CreateWindowEx(WS_EX_OVERLAPPEDWINDOW, TEXT("Button"), TEXT("植物无冷却时间"), WS_VISIBLE | WS_CHILD | WS_EX_LEFT, 13, 17, 130, 30, hwnd, HMENU(NOCOOLINGDOWNTIME), NULL, NULL);
	hSunNotDecrease = CreateWindowEx(WS_EX_OVERLAPPEDWINDOW, TEXT("Button"), TEXT("阳光不减少"), WS_VISIBLE | WS_CHILD | WS_EX_LEFT, 13, 60, 130, 30, hwnd, HMENU(SUNNOTDECREASE), NULL, NULL);
	hKillZombiesImmediately = CreateWindowEx(WS_EX_OVERLAPPEDWINDOW, TEXT("Button"), TEXT("僵尸一键秒杀"), WS_VISIBLE | WS_CHILD | WS_EX_LEFT, 13, 103, 130, 30, hwnd, HMENU(KILLZOMBIESIMMEDIATELY), NULL, NULL);
	hInfiniteSun = CreateWindowEx(WS_EX_OVERLAPPEDWINDOW, TEXT("Button"), TEXT("无限阳光"), WS_VISIBLE | WS_CHILD | WS_EX_LEFT, 140, 17, 100, 30, hwnd, HMENU(INFINITESUN), NULL, NULL);
	hInfiniteCoin = CreateWindowEx(WS_EX_OVERLAPPEDWINDOW, TEXT("Button"), TEXT("无限金币"), WS_VISIBLE | WS_CHILD | WS_EX_LEFT, 140, 60, 100, 30, hwnd, HMENU(INFINITECOIN), NULL, NULL);
	hFeelFreePlantPlants = CreateWindowEx(WS_EX_OVERLAPPEDWINDOW, TEXT("Button"), TEXT("植物堆叠"), WS_VISIBLE | WS_CHILD | WS_EX_LEFT, 140, 103, 100, 30, hwnd, HMENU(FEELFREEPLANTPLANTS), NULL, NULL);

	SendMessage(hNoCoolingDownTime, WM_SETFONT, (WPARAM)hFont, 1);
	SendMessage(hSunNotDecrease, WM_SETFONT, (WPARAM)hFont, 1);
	SendMessage(hKillZombiesImmediately, WM_SETFONT, (WPARAM)hFont, 1);
	SendMessage(hInfiniteSun, WM_SETFONT, (WPARAM)hFont, 1);
	SendMessage(hInfiniteCoin, WM_SETFONT, (WPARAM)hFont, 1);
	SendMessage(hFeelFreePlantPlants, WM_SETFONT, (WPARAM)hFont, 1);
}


LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam) {
	switch (message) {
	case WM_COMMAND:
		switch (wParam) {
		case SUNNOTDECREASE:
			sunNotDecrease(g_processHandle, isSunNotDecrease);

			// 如果功能未开启
			if (isSunNotDecrease == FALSE) {
				SetWindowText(hSunNotDecrease, TEXT("取消阳光不减少"));
				isSunNotDecrease = TRUE;
			}

			// 如果功能已开启
			else {
				SetWindowText(hSunNotDecrease, TEXT("阳光不减少"));
				isSunNotDecrease = FALSE;
			}

			break;
		case NOCOOLINGDOWNTIME:
			noCoolingDownTime(g_processHandle, isNoCoolingDownTime);

			// 如果功能未开启
			if (isNoCoolingDownTime == FALSE) {
				SetWindowText(hNoCoolingDownTime, TEXT("取消植物无冷却时间"));
				isNoCoolingDownTime = TRUE;
			}

			// 如果功能已开启
			else {
				SetWindowText(hNoCoolingDownTime, TEXT("植物无冷却时间"));
				isNoCoolingDownTime = FALSE;
			}

			break;
		case KILLZOMBIESIMMEDIATELY:
			killZombiesImmediately(g_processHandle, isKillZombiesImmediately);

			// 如果功能未开启
			if (isKillZombiesImmediately == FALSE) {
				SetWindowText(hKillZombiesImmediately, TEXT("取消僵尸一键秒杀"));
				isKillZombiesImmediately = TRUE;
			}

			// 如果功能已开启
			else {
				SetWindowText(hKillZombiesImmediately, TEXT("僵尸一键秒杀"));
				isKillZombiesImmediately = FALSE;
			}

			break;
		case INFINITESUN:
			infiniteSun(g_processHandle);
			break;
		case INFINITECOIN:
			infiniteCoin(g_processHandle);
			break;
		case FEELFREEPLANTPLANTS:
			feelfreePlantPlants(g_processHandle, isFeelFreePlantPlants);

			// 如果功能未开启
			if (isFeelFreePlantPlants == FALSE) {
				SetWindowText(hFeelFreePlantPlants, TEXT("取消植物堆叠"));
				isFeelFreePlantPlants = TRUE;
			}

			// 如果功能已开启
			else {
				SetWindowText(hFeelFreePlantPlants, TEXT("植物堆叠"));
				isFeelFreePlantPlants = FALSE;
			}

			break;
		case INFINITEFERTILIZER:
			infiniteFertilizer(g_processHandle);
			break;
		case INFINITEBUGSPRAY:
			infiniteBugSpray(g_processHandle);
			break;
		case INFINITECHOCOLATE:
			infiniteChocolate(g_processHandle);
			break;
		case INFINITETREEFOOD:
			infiniteTreeFood(g_processHandle);
			break;
		case MODIFYSUN:
			displayModifyDialog(hwnd, VALUEOFSUN);
			break;
		case MODIFYCOIN:
			displayModifyDialog(hwnd, VALUEOFCOIN);
			break;
		case MODIFYFERTILIZER:
			displayModifyDialog(hwnd, VALUEOFFERTILIZER);
			break;
		case MODIFYBUGSPRAY:
			displayModifyDialog(hwnd, VALUEOFBUGSPRAY);
			break;
		case MODIFYCHOCOLATE:
			displayModifyDialog(hwnd, VALUEOFCHOCOLATE);
			break;
		case MODIFYTREEFOOD:
			displayModifyDialog(hwnd, VALUEOFTREEFOOD);
			break;
		case INCREASESUN:
			displayIncreaseDialog(hwnd, VALUEOFSUN);
			break;
		case INCREASECOIN:
			displayIncreaseDialog(hwnd, VALUEOFCOIN);
			break;
		case INCREASEFERTILIZER:
			displayIncreaseDialog(hwnd, VALUEOFFERTILIZER);
			break;
		case INCREASEBUGSPRAY:
			displayIncreaseDialog(hwnd, VALUEOFBUGSPRAY);
			break;
		case INCREASECHOCOLATE:
			displayIncreaseDialog(hwnd, VALUEOFCHOCOLATE);
			break;
		case INCREASETREEFOOD:
			displayIncreaseDialog(hwnd, VALUEOFTREEFOOD);
			break;
		case DECREASESUN:
			displayDecreaseDialog(hwnd, VALUEOFSUN);
			break;
		case DECREASECOIN:
			displayDecreaseDialog(hwnd, VALUEOFCOIN);
			break;
		case DECREASEFERTILIZER:
			displayDecreaseDialog(hwnd, VALUEOFFERTILIZER);
			break;
		case DECREASEBUGSPRAY:
			displayDecreaseDialog(hwnd, VALUEOFBUGSPRAY);
			break;
		case DECREASECHOCOLATE:
			displayDecreaseDialog(hwnd, VALUEOFCHOCOLATE);
			break;
		case DECREASETREEFOOD:
			displayDecreaseDialog(hwnd, VALUEOFTREEFOOD);
			break;
		case CLEARSUN:
			clearSun(g_processHandle);
			break;
		case CLEARCOIN:
			clearNumberOfCoin(g_processHandle);
			break;
		case CLEARFERTILIZER:
			clearFertilizer(g_processHandle);
			break;
		case CLEARBUGSPRAY:
			clearBugSpray(g_processHandle);
			break;
		case CLEARCHOCOLATE:
			clearChocolate(g_processHandle);
			break;
		case CLEARTREEFOOD:
			clearTreeFood(g_processHandle);
			break;
		}
		break;
	case WM_CREATE:
		HANDLE hMonitorProcessThread;
		hMonitorProcessThread = CreateThread(NULL, NULL, monitorGameProcess, NULL, NULL, NULL);
		addMenu(hwnd);
		addControlComponet(hwnd);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hwnd, message, wParam, lParam);
		break;
	}
}