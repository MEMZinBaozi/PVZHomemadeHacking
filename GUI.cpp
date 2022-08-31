#include <Windows.h>
#include <tchar.h>

#include "CheatFunctions.h"
#include "Dialog.h"
#include "GUI.h"

DWORD monitorGameProcess(LPVOID lpThreadParameter) {
	while (1) {
		HWND hGameHandle = FindWindow(_T("MainWindow"), _T("Plants vs. Zombies"));
		if (hGameHandle == NULL) {
			// ����Ϸ����δ����ʱ��ֱ�ӽ��ð�ť���˵���
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

			SetWindowText(hSunNotDecrease, TEXT("���ⲻ����"));
			SetWindowText(hNoCoolingDownTime, TEXT("ֲ������ȴʱ��"));
			SetWindowText(hKillZombiesImmediately, TEXT("��ʬһ����ɱ"));
			SetWindowText(hFeelFreePlantPlants, TEXT("ֲ��ѵ�"));
		}
		else {
			// ��֮��Ȼ
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
	// ��Ҫ�˵�
	AppendMenu(hModifyMenu, MF_POPUP, (UINT_PTR)hModifyValueMenu, TEXT("��ֵ�޸�"));
	AppendMenu(hModifyMenu, MF_POPUP, (UINT_PTR)hInfiniteValueMenu, TEXT("��ֵ����"));
	AppendMenu(hModifyMenu, MF_POPUP, (UINT_PTR)hIncreaseValueMenu, TEXT("��ֵ����"));
	AppendMenu(hModifyMenu, MF_POPUP, (UINT_PTR)hDecreaseValueMenu, TEXT("��ֵ����"));
	AppendMenu(hModifyMenu, MF_POPUP, (UINT_PTR)hClearValueMenu, TEXT("��ֵ����"));

	// ��ֵ�޸Ĳ˵�
	AppendMenu(hModifyValueMenu, MF_STRING, MODIFYSUN, TEXT("�޸�������ֵ"));
	AppendMenu(hModifyValueMenu, MF_STRING, MODIFYCOIN, TEXT("�޸Ľ����ֵ"));
	AppendMenu(hModifyValueMenu, MF_STRING, MODIFYFERTILIZER, TEXT("�޸ķ�����ֵ"));
	AppendMenu(hModifyValueMenu, MF_STRING, MODIFYBUGSPRAY, TEXT("�޸�ɱ�����ֵ"));
	AppendMenu(hModifyValueMenu, MF_STRING, MODIFYCHOCOLATE, TEXT("�޸��ɿ�����ֵ"));
	AppendMenu(hModifyValueMenu, MF_STRING, MODIFYTREEFOOD, TEXT("�޸�������ֵ"));

	// ��ֵ���޲˵�
	AppendMenu(hInfiniteValueMenu, MF_STRING, INFINITESUN, TEXT("��������"));
	AppendMenu(hInfiniteValueMenu, MF_STRING, INFINITECOIN, TEXT("���޽��"));
	AppendMenu(hInfiniteValueMenu, MF_STRING, INFINITEFERTILIZER, TEXT("���޷���"));
	AppendMenu(hInfiniteValueMenu, MF_STRING, INFINITEBUGSPRAY, TEXT("����ɱ���"));
	AppendMenu(hInfiniteValueMenu, MF_STRING, INFINITECHOCOLATE, TEXT("�����ɿ���"));
	AppendMenu(hInfiniteValueMenu, MF_STRING, INFINITETREEFOOD, TEXT("��������"));

	// ��ֵ���Ӳ˵�
	AppendMenu(hIncreaseValueMenu, MF_STRING, INCREASESUN, TEXT("����������ֵ"));
	AppendMenu(hIncreaseValueMenu, MF_STRING, INCREASECOIN, TEXT("���ӽ����ֵ"));
	AppendMenu(hIncreaseValueMenu, MF_STRING, INCREASEFERTILIZER, TEXT("���ӷ�����ֵ"));
	AppendMenu(hIncreaseValueMenu, MF_STRING, INCREASEBUGSPRAY, TEXT("����ɱ�����ֵ"));
	AppendMenu(hIncreaseValueMenu, MF_STRING, INCREASECHOCOLATE, TEXT("�����ɿ�����ֵ"));
	AppendMenu(hIncreaseValueMenu, MF_STRING, INCREASETREEFOOD, TEXT("����������ֵ"));

	// ��ֵ���ٲ˵�
	AppendMenu(hDecreaseValueMenu, MF_STRING, DECREASESUN, TEXT("����������ֵ"));
	AppendMenu(hDecreaseValueMenu, MF_STRING, DECREASECOIN, TEXT("���ٽ����ֵ"));
	AppendMenu(hDecreaseValueMenu, MF_STRING, DECREASEFERTILIZER, TEXT("���ٷ�����ֵ"));
	AppendMenu(hDecreaseValueMenu, MF_STRING, DECREASEBUGSPRAY, TEXT("����ɱ�����ֵ"));
	AppendMenu(hDecreaseValueMenu, MF_STRING, DECREASECHOCOLATE, TEXT("�����ɿ�����ֵ"));
	AppendMenu(hDecreaseValueMenu, MF_STRING, DECREASETREEFOOD, TEXT("����������ֵ"));

	// ��ֵ����˵�
	AppendMenu(hClearValueMenu, MF_STRING, CLEARSUN, TEXT("����������ֵ"));
	AppendMenu(hClearValueMenu, MF_STRING, CLEARCOIN, TEXT("��������ֵ"));
	AppendMenu(hClearValueMenu, MF_STRING, CLEARFERTILIZER, TEXT("���������ֵ"));
	AppendMenu(hClearValueMenu, MF_STRING, CLEARBUGSPRAY, TEXT("����ɱ�����ֵ"));
	AppendMenu(hClearValueMenu, MF_STRING, CLEARCHOCOLATE, TEXT("�����ɿ�����ֵ"));
	AppendMenu(hClearValueMenu, MF_STRING, CLEARTREEFOOD, TEXT("����������ֵ"));

	// ���ù��ܲ˵�
	AppendMenu(hChangeMenu, MF_STRING, NOCOOLINGDOWNTIME, TEXT("ֲ������ȴʱ��"));
	AppendMenu(hChangeMenu, MF_STRING, SUNNOTDECREASE, TEXT("���ⲻ����"));
	AppendMenu(hChangeMenu, MF_STRING, KILLZOMBIESIMMEDIATELY, TEXT("��ʬһ����ɱ"));
	AppendMenu(hChangeMenu, MF_STRING, INFINITESUN, TEXT("��������"));
	AppendMenu(hChangeMenu, MF_STRING, INFINITECOIN, TEXT("���޽��"));
	AppendMenu(hChangeMenu, MF_STRING, FEELFREEPLANTPLANTS, TEXT("ֲ��ѵ�"));

	AppendMenu(hMenu, MF_POPUP, (UINT_PTR)hModifyMenu, TEXT("��Ʒ�����޸�"));
	AppendMenu(hMenu, MF_POPUP, (UINT_PTR)hChangeMenu, TEXT("���ù���")); 
	SetMenu(hwnd, hMenu);
}

void addControlComponet(HWND hwnd) {
	HFONT hFont = (HFONT)GetStockObject(DEFAULT_GUI_FONT);

	hNoCoolingDownTime = CreateWindowEx(WS_EX_OVERLAPPEDWINDOW, TEXT("Button"), TEXT("ֲ������ȴʱ��"), WS_VISIBLE | WS_CHILD | WS_EX_LEFT, 13, 17, 130, 30, hwnd, HMENU(NOCOOLINGDOWNTIME), NULL, NULL);
	hSunNotDecrease = CreateWindowEx(WS_EX_OVERLAPPEDWINDOW, TEXT("Button"), TEXT("���ⲻ����"), WS_VISIBLE | WS_CHILD | WS_EX_LEFT, 13, 60, 130, 30, hwnd, HMENU(SUNNOTDECREASE), NULL, NULL);
	hKillZombiesImmediately = CreateWindowEx(WS_EX_OVERLAPPEDWINDOW, TEXT("Button"), TEXT("��ʬһ����ɱ"), WS_VISIBLE | WS_CHILD | WS_EX_LEFT, 13, 103, 130, 30, hwnd, HMENU(KILLZOMBIESIMMEDIATELY), NULL, NULL);
	hInfiniteSun = CreateWindowEx(WS_EX_OVERLAPPEDWINDOW, TEXT("Button"), TEXT("��������"), WS_VISIBLE | WS_CHILD | WS_EX_LEFT, 140, 17, 100, 30, hwnd, HMENU(INFINITESUN), NULL, NULL);
	hInfiniteCoin = CreateWindowEx(WS_EX_OVERLAPPEDWINDOW, TEXT("Button"), TEXT("���޽��"), WS_VISIBLE | WS_CHILD | WS_EX_LEFT, 140, 60, 100, 30, hwnd, HMENU(INFINITECOIN), NULL, NULL);
	hFeelFreePlantPlants = CreateWindowEx(WS_EX_OVERLAPPEDWINDOW, TEXT("Button"), TEXT("ֲ��ѵ�"), WS_VISIBLE | WS_CHILD | WS_EX_LEFT, 140, 103, 100, 30, hwnd, HMENU(FEELFREEPLANTPLANTS), NULL, NULL);

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

			// �������δ����
			if (isSunNotDecrease == FALSE) {
				SetWindowText(hSunNotDecrease, TEXT("ȡ�����ⲻ����"));
				isSunNotDecrease = TRUE;
			}

			// ��������ѿ���
			else {
				SetWindowText(hSunNotDecrease, TEXT("���ⲻ����"));
				isSunNotDecrease = FALSE;
			}

			break;
		case NOCOOLINGDOWNTIME:
			noCoolingDownTime(g_processHandle, isNoCoolingDownTime);

			// �������δ����
			if (isNoCoolingDownTime == FALSE) {
				SetWindowText(hNoCoolingDownTime, TEXT("ȡ��ֲ������ȴʱ��"));
				isNoCoolingDownTime = TRUE;
			}

			// ��������ѿ���
			else {
				SetWindowText(hNoCoolingDownTime, TEXT("ֲ������ȴʱ��"));
				isNoCoolingDownTime = FALSE;
			}

			break;
		case KILLZOMBIESIMMEDIATELY:
			killZombiesImmediately(g_processHandle, isKillZombiesImmediately);

			// �������δ����
			if (isKillZombiesImmediately == FALSE) {
				SetWindowText(hKillZombiesImmediately, TEXT("ȡ����ʬһ����ɱ"));
				isKillZombiesImmediately = TRUE;
			}

			// ��������ѿ���
			else {
				SetWindowText(hKillZombiesImmediately, TEXT("��ʬһ����ɱ"));
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

			// �������δ����
			if (isFeelFreePlantPlants == FALSE) {
				SetWindowText(hFeelFreePlantPlants, TEXT("ȡ��ֲ��ѵ�"));
				isFeelFreePlantPlants = TRUE;
			}

			// ��������ѿ���
			else {
				SetWindowText(hFeelFreePlantPlants, TEXT("ֲ��ѵ�"));
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