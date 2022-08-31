#pragma once
#include <Windows.h>

// 进程句柄
HANDLE g_processHandle;

// 检查功能是否打开
BOOL isSunNotDecrease;
BOOL isNoCoolingDownTime;
BOOL isKillZombiesImmediately;
BOOL isFeelFreePlantPlants;

// 常用功能宏定义：
#define SUNNOTDECREASE 1
#define NOCOOLINGDOWNTIME 2
#define KILLZOMBIESIMMEDIATELY 3
#define FEELFREEPLANTPLANTS 6

// 数值无限宏定义
#define INFINITESUN 4
#define INFINITECOIN 5
#define INFINITEFERTILIZER 7
#define INFINITEBUGSPRAY 8
#define INFINITECHOCOLATE 9
#define INFINITETREEFOOD 10

// 数值修改宏定义
#define MODIFYSUN 11
#define MODIFYCOIN 12
#define MODIFYFERTILIZER 13
#define MODIFYBUGSPRAY 14
#define MODIFYCHOCOLATE 15
#define MODIFYTREEFOOD 16

// 数值增加宏定义
#define INCREASESUN 17
#define INCREASECOIN 18
#define INCREASEFERTILIZER 19
#define INCREASEBUGSPRAY 20
#define INCREASECHOCOLATE 21
#define INCREASETREEFOOD 22

// 数值减少宏定义
#define DECREASESUN 23
#define DECREASECOIN 24
#define DECREASEFERTILIZER 25
#define DECREASEBUGSPRAY 26
#define DECREASECHOCOLATE 27
#define DECREASETREEFOOD 28

// 数值清零宏定义
#define CLEARSUN 29
#define CLEARCOIN 30
#define CLEARFERTILIZER 31
#define CLEARBUGSPRAY 32
#define CLEARCHOCOLATE 33
#define CLEARTREEFOOD 34

// 菜单
HMENU hMenu = CreateMenu();
HMENU hModifyMenu = CreateMenu(); // 游戏内数值修改菜单
HMENU hModifyValueMenu = CreateMenu(); // 修改数值
HMENU hInfiniteValueMenu = CreateMenu(); // 数值无限
HMENU hChangeMenu = CreateMenu(); // 功能修改
HMENU hIncreaseValueMenu = CreateMenu(); // 数值增加
HMENU hDecreaseValueMenu = CreateMenu(); // 数值减少
HMENU hClearValueMenu = CreateMenu(); // 数值清零

// 常用功能：
HWND hNoCoolingDownTime; // 无冷却时间
HWND hSunNotDecrease; // 阳光数值不减少
HWND hKillZombiesImmediately; // 僵尸秒杀
HWND hInfiniteSun; // 无限阳光
HWND hInfiniteCoin; // 无限金币
HWND hFeelFreePlantPlants; // 植物堆叠

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);
void addMenu(HWND hwnd);
void addControlComponet(HWND hwnd);
DWORD monitorGameProcess(LPVOID lpThreadParameter); // 监控游戏进程
