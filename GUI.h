#pragma once
#include <Windows.h>

// ���̾��
HANDLE g_processHandle;

// ��鹦���Ƿ��
BOOL isSunNotDecrease;
BOOL isNoCoolingDownTime;
BOOL isKillZombiesImmediately;
BOOL isFeelFreePlantPlants;

// ���ù��ܺ궨�壺
#define SUNNOTDECREASE 1
#define NOCOOLINGDOWNTIME 2
#define KILLZOMBIESIMMEDIATELY 3
#define FEELFREEPLANTPLANTS 6

// ��ֵ���޺궨��
#define INFINITESUN 4
#define INFINITECOIN 5
#define INFINITEFERTILIZER 7
#define INFINITEBUGSPRAY 8
#define INFINITECHOCOLATE 9
#define INFINITETREEFOOD 10

// ��ֵ�޸ĺ궨��
#define MODIFYSUN 11
#define MODIFYCOIN 12
#define MODIFYFERTILIZER 13
#define MODIFYBUGSPRAY 14
#define MODIFYCHOCOLATE 15
#define MODIFYTREEFOOD 16

// ��ֵ���Ӻ궨��
#define INCREASESUN 17
#define INCREASECOIN 18
#define INCREASEFERTILIZER 19
#define INCREASEBUGSPRAY 20
#define INCREASECHOCOLATE 21
#define INCREASETREEFOOD 22

// ��ֵ���ٺ궨��
#define DECREASESUN 23
#define DECREASECOIN 24
#define DECREASEFERTILIZER 25
#define DECREASEBUGSPRAY 26
#define DECREASECHOCOLATE 27
#define DECREASETREEFOOD 28

// ��ֵ����궨��
#define CLEARSUN 29
#define CLEARCOIN 30
#define CLEARFERTILIZER 31
#define CLEARBUGSPRAY 32
#define CLEARCHOCOLATE 33
#define CLEARTREEFOOD 34

// �˵�
HMENU hMenu = CreateMenu();
HMENU hModifyMenu = CreateMenu(); // ��Ϸ����ֵ�޸Ĳ˵�
HMENU hModifyValueMenu = CreateMenu(); // �޸���ֵ
HMENU hInfiniteValueMenu = CreateMenu(); // ��ֵ����
HMENU hChangeMenu = CreateMenu(); // �����޸�
HMENU hIncreaseValueMenu = CreateMenu(); // ��ֵ����
HMENU hDecreaseValueMenu = CreateMenu(); // ��ֵ����
HMENU hClearValueMenu = CreateMenu(); // ��ֵ����

// ���ù��ܣ�
HWND hNoCoolingDownTime; // ����ȴʱ��
HWND hSunNotDecrease; // ������ֵ������
HWND hKillZombiesImmediately; // ��ʬ��ɱ
HWND hInfiniteSun; // ��������
HWND hInfiniteCoin; // ���޽��
HWND hFeelFreePlantPlants; // ֲ��ѵ�

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);
void addMenu(HWND hwnd);
void addControlComponet(HWND hwnd);
DWORD monitorGameProcess(LPVOID lpThreadParameter); // �����Ϸ����
