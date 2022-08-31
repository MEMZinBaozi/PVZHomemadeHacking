#include <Windows.h>
#include <tchar.h>

#include "CheatFunctions.h"

void sunNotDecrease(HANDLE needsProcessHandle, BOOL onOrOff) {
	// 如果功能没有开启：
	if (onOrOff == FALSE) {
		CHAR dataToWrite[] = { (CHAR)0x83,(CHAR)0xEE,(CHAR)0x00,(CHAR)0x90,(CHAR)0x90,(CHAR)0x90,(CHAR)0x90,(CHAR)0x90 };
		WriteProcessMemory(needsProcessHandle, (LPVOID)0x0041BA74, &dataToWrite, sizeof(dataToWrite), NULL);
	}
	// 反之亦然
	else if (onOrOff == TRUE) {
		CHAR dataToWrite[] = { (CHAR)0x29, (CHAR)0xDE, (CHAR)0x89, (CHAR)0xB7, (CHAR)0x60, (CHAR)0x55, (CHAR)0x00, (CHAR)0x00 };
		WriteProcessMemory(needsProcessHandle, (LPVOID)0x0041BA74, &dataToWrite, sizeof(dataToWrite), NULL);
	}
}

void noCoolingDownTime(HANDLE needsProcessHandle, BOOL onOrOff) {
	if (onOrOff == FALSE) {
		CHAR dataToWrite[] = { (CHAR)0x90 ,(CHAR)0x90 ,(CHAR)0x90 };
		WriteProcessMemory(needsProcessHandle, (LPVOID)0x00487293, &dataToWrite, sizeof(dataToWrite), NULL);
	}
	else {
		CHAR dataToWrite[] = { (CHAR)0x3B ,(CHAR)0x47 ,(CHAR)0x28 };
		WriteProcessMemory(needsProcessHandle, (LPVOID)0x00487293, &dataToWrite, sizeof(dataToWrite), NULL);
	}
}

void killZombiesImmediately(HANDLE needsProcessHandle, BOOL onOrOff) {

	if (onOrOff == FALSE) {
		// 普通僵尸
		CHAR dataToWrite[] = { (CHAR)0x29, (CHAR)0xFF, (CHAR)0x90, (CHAR)0x90 };
		WriteProcessMemory(needsProcessHandle, (LPVOID)0x0053130F, &dataToWrite, sizeof(dataToWrite), NULL);
		// 路障僵尸、铁通僵尸、橄榄球僵尸
		CHAR dataToWrite_two[] = { (CHAR)0x29, (CHAR)0xC9 };
		WriteProcessMemory(needsProcessHandle, (LPVOID)0x00531044, &dataToWrite_two, sizeof(dataToWrite_two), NULL);
		// 铁门僵尸、二爷
		CHAR dataToWrite_three[] = { (CHAR)0x29, (CHAR)0xC0, (CHAR)0x90, (CHAR)0x90, (CHAR)0x90, (CHAR)0x90, };
		WriteProcessMemory(needsProcessHandle, (LPVOID)0x00530CA1, &dataToWrite_three, sizeof(dataToWrite_three), NULL);
	}
	else {
		// 普通僵尸
		CHAR dataToWrite[] = { (CHAR)0x2B, (CHAR)0x7C, (CHAR)0x24, (CHAR)0x20 };
		WriteProcessMemory(needsProcessHandle, (LPVOID)0x0053130F, &dataToWrite, sizeof(dataToWrite), NULL);
		// 路障僵尸、铁通僵尸、橄榄球僵尸
		CHAR dataToWrite_two[] = { (CHAR)0x2B, (CHAR)0xC8 };
		WriteProcessMemory(needsProcessHandle, (LPVOID)0x00531044, &dataToWrite_two, sizeof(dataToWrite_two), NULL);
		// 铁门僵尸、二爷
		CHAR dataToWrite_three[] = { (CHAR)0x29, (CHAR)0x86, (CHAR)0xDC, (CHAR)0x00, (CHAR)0x00, (CHAR)0x00, };
		WriteProcessMemory(needsProcessHandle, (LPVOID)0x00530CA1, &dataToWrite_three, sizeof(dataToWrite_three), NULL);
	}
}

void feelfreePlantPlants(HANDLE needsProcessHandle, BOOL onOrOff) {
	if (onOrOff == FALSE) {
		CHAR dataToWrite[] = { (CHAR)0xE9, (CHAR)0x20, (CHAR)0x09, (CHAR)0x00, (CHAR)0x00, (CHAR)0x90 };
		WriteProcessMemory(needsProcessHandle, (LPVOID)0x0040FE2F, &dataToWrite, sizeof(dataToWrite), NULL);
	}
	else {
		CHAR dataToWrite[] = { (CHAR)0x0F, (CHAR)0x84, (CHAR)0x1F, (CHAR)0x09, (CHAR)0x00, (CHAR)0x00 };
		WriteProcessMemory(needsProcessHandle, (LPVOID)0x0040FE2F, &dataToWrite, sizeof(dataToWrite), NULL);
	}
}

void infiniteSun(HANDLE needsProcessHandle) {
	DWORD baseAddress = 0x006A9EC0;
	DWORD baseAddressValue = 0;
	DWORD firstOffset = 0x768;
	DWORD firstOffsetValue = 0;
	DWORD secondOffset = 0x5560;
	SIZE_T dwSize = 0;

	int numberOfSun = 9990;

	if (!ReadProcessMemory(needsProcessHandle, (LPVOID)baseAddress, &baseAddressValue, sizeof(DWORD), &dwSize)) {
		MessageBox(NULL, TEXT("无法获取一级指针"), TEXT("错误"), MB_ICONERROR | MB_OK);
	}

	if (!ReadProcessMemory(needsProcessHandle, (LPVOID)(baseAddressValue + firstOffset), &firstOffsetValue, sizeof(DWORD), &dwSize)) {
		MessageBox(NULL, TEXT("无法获取二级指针"), TEXT("错误"), MB_ICONERROR | MB_OK);
	}

	WriteProcessMemory(needsProcessHandle, (LPVOID)(firstOffsetValue + secondOffset), &numberOfSun, sizeof(numberOfSun), &dwSize);

}

void infiniteCoin(HANDLE needsProcessHandle) {
	DWORD baseAddress = 0x006A9EC0;
	DWORD baseAddressValue = 0;
	DWORD firstOffset = 0x82C;
	DWORD firstOffsetValue = 0;
	DWORD secondOffset = 0x28;
	SIZE_T dwSize = 0;

	int numberOfCoin = 999990 / 10;

	if (!ReadProcessMemory(needsProcessHandle, (LPVOID)baseAddress, &baseAddressValue, sizeof(DWORD), &dwSize)) {
		MessageBox(NULL, TEXT("无法获取一级指针"), TEXT("错误"), MB_ICONERROR | MB_OK);
	}

	if (!ReadProcessMemory(needsProcessHandle, (LPVOID)(baseAddressValue + firstOffset), &firstOffsetValue, sizeof(DWORD), &dwSize)) {
		MessageBox(NULL, TEXT("无法获取二级指针"), TEXT("错误"), MB_ICONERROR | MB_OK);
	}

	WriteProcessMemory(needsProcessHandle, (LPVOID)(firstOffsetValue + secondOffset), &numberOfCoin, sizeof(numberOfCoin), &dwSize);
}

void infiniteFertilizer(HANDLE needsProcessHandle) {
	DWORD baseAddress = 0x006A9EC0;
	DWORD baseAddressValue = 0;
	DWORD firstOffset = 0x82C;
	DWORD firstOffsetValue = 0;
	DWORD secondOffset = 0x1F8;
	SIZE_T dwSize = 0;

	int numberOfFertilizer = 99 + 1000;

	if (!ReadProcessMemory(needsProcessHandle, (LPVOID)baseAddress, &baseAddressValue, sizeof(DWORD), &dwSize)) {
		MessageBox(NULL, TEXT("无法获取一级指针"), TEXT("错误"), MB_ICONERROR | MB_OK);
	}

	if (!ReadProcessMemory(needsProcessHandle, (LPVOID)(baseAddressValue + firstOffset), &firstOffsetValue, sizeof(DWORD), &dwSize)) {
		MessageBox(NULL, TEXT("无法获取二级指针"), TEXT("错误"), MB_ICONERROR | MB_OK);
	}

	WriteProcessMemory(needsProcessHandle, (LPVOID)(firstOffsetValue + secondOffset), &numberOfFertilizer, sizeof(numberOfFertilizer), &dwSize);
}

void infiniteBugSpray(HANDLE needsProcessHandle) {
	DWORD baseAddress = 0x006A9EC0;
	DWORD baseAddressValue = 0;
	DWORD firstOffset = 0x82C;
	DWORD firstOffsetValue = 0;
	DWORD secondOffset = 0x1FC;
	SIZE_T dwSize = 0;

	int numberOfBugSpray = 99 + 1000;

	if (!ReadProcessMemory(needsProcessHandle, (LPVOID)baseAddress, &baseAddressValue, sizeof(DWORD), &dwSize)) {
		MessageBox(NULL, TEXT("无法获取一级指针"), TEXT("错误"), MB_ICONERROR | MB_OK);
	}

	if (!ReadProcessMemory(needsProcessHandle, (LPVOID)(baseAddressValue + firstOffset), &firstOffsetValue, sizeof(DWORD), &dwSize)) {
		MessageBox(NULL, TEXT("无法获取二级指针"), TEXT("错误"), MB_ICONERROR | MB_OK);
	}

	WriteProcessMemory(needsProcessHandle, (LPVOID)(firstOffsetValue + secondOffset), &numberOfBugSpray, sizeof(numberOfBugSpray), &dwSize);
}

void infiniteChocolate(HANDLE needsProcessHandle) {
	DWORD baseAddress = 0x006A9EC0;
	DWORD baseAddressValue = 0;
	DWORD firstOffset = 0x82C;
	DWORD firstOffsetValue = 0;
	DWORD secondOffset = 0x228;
	SIZE_T dwSize = 0;

	int numberOfChocolate = 99 + 1000;

	if (!ReadProcessMemory(needsProcessHandle, (LPVOID)baseAddress, &baseAddressValue, sizeof(DWORD), &dwSize)) {
		MessageBox(NULL, TEXT("无法获取一级指针"), TEXT("错误"), MB_ICONERROR | MB_OK);
	}

	if (!ReadProcessMemory(needsProcessHandle, (LPVOID)(baseAddressValue + firstOffset), &firstOffsetValue, sizeof(DWORD), &dwSize)) {
		MessageBox(NULL, TEXT("无法获取二级指针"), TEXT("错误"), MB_ICONERROR | MB_OK);
	}

	WriteProcessMemory(needsProcessHandle, (LPVOID)(firstOffsetValue + secondOffset), &numberOfChocolate, sizeof(numberOfChocolate), &dwSize);
}

void infiniteTreeFood(HANDLE needsProcessHandle) {
	DWORD baseAddress = 0x006A9EC0;
	DWORD baseAddressValue = 0;
	DWORD firstOffset = 0x82C;
	DWORD firstOffsetValue = 0;
	DWORD secondOffset = 0x230;
	SIZE_T dwSize = 0;

	int numberOfTreeFood = 99 + 1000;

	if (!ReadProcessMemory(needsProcessHandle, (LPVOID)baseAddress, &baseAddressValue, sizeof(DWORD), &dwSize)) {
		MessageBox(NULL, TEXT("无法获取一级指针"), TEXT("错误"), MB_ICONERROR | MB_OK);
	}

	if (!ReadProcessMemory(needsProcessHandle, (LPVOID)(baseAddressValue + firstOffset), &firstOffsetValue, sizeof(DWORD), &dwSize)) {
		MessageBox(NULL, TEXT("无法获取二级指针"), TEXT("错误"), MB_ICONERROR | MB_OK);
	}

	WriteProcessMemory(needsProcessHandle, (LPVOID)(firstOffsetValue + secondOffset), &numberOfTreeFood, sizeof(numberOfTreeFood), &dwSize);
}

void modifyNumberOfSun(HANDLE needsProcessHandle, int valueToModify) {
	DWORD baseAddress = 0x006A9EC0;
	DWORD baseAddressValue = 0;
	DWORD firstOffset = 0x768;
	DWORD firstOffsetValue = 0;
	DWORD secondOffset = 0x5560;
	SIZE_T dwSize = 0;

	if (!ReadProcessMemory(needsProcessHandle, (LPVOID)baseAddress, &baseAddressValue, sizeof(DWORD), &dwSize)) {
		MessageBox(NULL, TEXT("无法获取一级指针"), TEXT("错误"), MB_ICONERROR | MB_OK);
	}

	if (!ReadProcessMemory(needsProcessHandle, (LPVOID)(baseAddressValue + firstOffset), &firstOffsetValue, sizeof(DWORD), &dwSize)) {
		MessageBox(NULL, TEXT("无法获取二级指针"), TEXT("错误"), MB_ICONERROR | MB_OK);
	}

	WriteProcessMemory(needsProcessHandle, (LPVOID)(firstOffsetValue + secondOffset), &valueToModify, sizeof(valueToModify), &dwSize);

}

void modifyNumberOfCoin(HANDLE needsProcessHandle, int valueToModify) {
	DWORD baseAddress = 0x006A9EC0;
	DWORD baseAddressValue = 0;
	DWORD firstOffset = 0x82C;
	DWORD firstOffsetValue = 0;
	DWORD secondOffset = 0x28;
	SIZE_T dwSize = 0;

	if (!ReadProcessMemory(needsProcessHandle, (LPVOID)baseAddress, &baseAddressValue, sizeof(DWORD), &dwSize)) {
		MessageBox(NULL, TEXT("无法获取一级指针"), TEXT("错误"), MB_ICONERROR | MB_OK);
	}

	if (!ReadProcessMemory(needsProcessHandle, (LPVOID)(baseAddressValue + firstOffset), &firstOffsetValue, sizeof(DWORD), &dwSize)) {
		MessageBox(NULL, TEXT("无法获取二级指针"), TEXT("错误"), MB_ICONERROR | MB_OK);
	}

	valueToModify = valueToModify / 10;

	WriteProcessMemory(needsProcessHandle, (LPVOID)(firstOffsetValue + secondOffset), &valueToModify, sizeof(valueToModify), &dwSize);
}

void modifyNumberOfFertilizer(HANDLE needsProcessHandle, int valueToModify) {
	DWORD baseAddress = 0x006A9EC0;
	DWORD baseAddressValue = 0;
	DWORD firstOffset = 0x82C;
	DWORD firstOffsetValue = 0;
	DWORD secondOffset = 0x1F8;
	SIZE_T dwSize = 0;

	valueToModify = valueToModify + 1000;

	if (!ReadProcessMemory(needsProcessHandle, (LPVOID)baseAddress, &baseAddressValue, sizeof(DWORD), &dwSize)) {
		MessageBox(NULL, TEXT("无法获取一级指针"), TEXT("错误"), MB_ICONERROR | MB_OK);
	}

	if (!ReadProcessMemory(needsProcessHandle, (LPVOID)(baseAddressValue + firstOffset), &firstOffsetValue, sizeof(DWORD), &dwSize)) {
		MessageBox(NULL, TEXT("无法获取二级指针"), TEXT("错误"), MB_ICONERROR | MB_OK);
	}

	WriteProcessMemory(needsProcessHandle, (LPVOID)(firstOffsetValue + secondOffset), &valueToModify, sizeof(valueToModify), &dwSize);
}

void modifyNumberOfBugSpray(HANDLE needsProcessHandle, int valueToModify) {
	DWORD baseAddress = 0x006A9EC0;
	DWORD baseAddressValue = 0;
	DWORD firstOffset = 0x82C;
	DWORD firstOffsetValue = 0;
	DWORD secondOffset = 0x1FC;
	SIZE_T dwSize = 0;

	valueToModify = valueToModify + 1000;

	if (!ReadProcessMemory(needsProcessHandle, (LPVOID)baseAddress, &baseAddressValue, sizeof(DWORD), &dwSize)) {
		MessageBox(NULL, TEXT("无法获取一级指针"), TEXT("错误"), MB_ICONERROR | MB_OK);
	}

	if (!ReadProcessMemory(needsProcessHandle, (LPVOID)(baseAddressValue + firstOffset), &firstOffsetValue, sizeof(DWORD), &dwSize)) {
		MessageBox(NULL, TEXT("无法获取二级指针"), TEXT("错误"), MB_ICONERROR | MB_OK);
	}

	WriteProcessMemory(needsProcessHandle, (LPVOID)(firstOffsetValue + secondOffset), &valueToModify, sizeof(valueToModify), &dwSize);
}

void modifyNumberOfChocolate(HANDLE needsProcessHandle, int valueToModify) {
	DWORD baseAddress = 0x006A9EC0;
	DWORD baseAddressValue = 0;
	DWORD firstOffset = 0x82C;
	DWORD firstOffsetValue = 0;
	DWORD secondOffset = 0x228;
	SIZE_T dwSize = 0;

	valueToModify = valueToModify + 1000;

	if (!ReadProcessMemory(needsProcessHandle, (LPVOID)baseAddress, &baseAddressValue, sizeof(DWORD), &dwSize)) {
		MessageBox(NULL, TEXT("无法获取一级指针"), TEXT("错误"), MB_ICONERROR | MB_OK);
	}

	if (!ReadProcessMemory(needsProcessHandle, (LPVOID)(baseAddressValue + firstOffset), &firstOffsetValue, sizeof(DWORD), &dwSize)) {
		MessageBox(NULL, TEXT("无法获取二级指针"), TEXT("错误"), MB_ICONERROR | MB_OK);
	}

	WriteProcessMemory(needsProcessHandle, (LPVOID)(firstOffsetValue + secondOffset), &valueToModify, sizeof(valueToModify), &dwSize);
}

void modifyNumberOfTreeFood(HANDLE needsProcessHandle, int valueToModify) {
	DWORD baseAddress = 0x006A9EC0;
	DWORD baseAddressValue = 0;
	DWORD firstOffset = 0x82C;
	DWORD firstOffsetValue = 0;
	DWORD secondOffset = 0x230;
	SIZE_T dwSize = 0;

	valueToModify = valueToModify + 1000;

	if (!ReadProcessMemory(needsProcessHandle, (LPVOID)baseAddress, &baseAddressValue, sizeof(DWORD), &dwSize)) {
		MessageBox(NULL, TEXT("无法获取一级指针"), TEXT("错误"), MB_ICONERROR | MB_OK);
	}

	if (!ReadProcessMemory(needsProcessHandle, (LPVOID)(baseAddressValue + firstOffset), &firstOffsetValue, sizeof(DWORD), &dwSize)) {
		MessageBox(NULL, TEXT("无法获取二级指针"), TEXT("错误"), MB_ICONERROR | MB_OK);
	}

	WriteProcessMemory(needsProcessHandle, (LPVOID)(firstOffsetValue + secondOffset), &valueToModify, sizeof(valueToModify), &dwSize);
}

void increaseSun(HANDLE needsProcessHandle, int valueToIncrease) {
	DWORD currentValueOfSun;
	
	DWORD baseAddress = 0x006A9EC0;
	DWORD baseAddressValue = 0;
	DWORD firstOffset = 0x768;
	DWORD firstOffsetValue = 0;
	DWORD secondOffset = 0x5560;
	SIZE_T dwSize = 0;

	if (!ReadProcessMemory(needsProcessHandle, (LPVOID)baseAddress, &baseAddressValue, sizeof(DWORD), &dwSize)) {
		MessageBox(NULL, TEXT("无法获取一级指针"), TEXT("错误"), MB_ICONERROR | MB_OK);
	}

	if (!ReadProcessMemory(needsProcessHandle, (LPVOID)(baseAddressValue + firstOffset), &firstOffsetValue, sizeof(DWORD), &dwSize)) {
		MessageBox(NULL, TEXT("无法获取二级指针"), TEXT("错误"), MB_ICONERROR | MB_OK);
	}
	if (!ReadProcessMemory(needsProcessHandle, (LPVOID)(firstOffsetValue + secondOffset), &currentValueOfSun, sizeof(DWORD), &dwSize)) {
		MessageBox(NULL, TEXT("无法从地址获取数值"), TEXT("错误"), MB_ICONERROR | MB_OK);
	}

	int valueToModify = currentValueOfSun + valueToIncrease;

	WriteProcessMemory(needsProcessHandle, (LPVOID)(firstOffsetValue + secondOffset), &valueToModify, sizeof(valueToModify), &dwSize);
}

void increaseCoin(HANDLE needsProcessHandle, int valueToIncrease) {
	DWORD currentValueOfCoin;

	DWORD baseAddress = 0x006A9EC0;
	DWORD baseAddressValue = 0;
	DWORD firstOffset = 0x82C;
	DWORD firstOffsetValue = 0;
	DWORD secondOffset = 0x28;
	SIZE_T dwSize = 0;

	if (!ReadProcessMemory(needsProcessHandle, (LPVOID)baseAddress, &baseAddressValue, sizeof(DWORD), &dwSize)) {
		MessageBox(NULL, TEXT("无法获取一级指针"), TEXT("错误"), MB_ICONERROR | MB_OK);
	}

	if (!ReadProcessMemory(needsProcessHandle, (LPVOID)(baseAddressValue + firstOffset), &firstOffsetValue, sizeof(DWORD), &dwSize)) {
		MessageBox(NULL, TEXT("无法获取二级指针"), TEXT("错误"), MB_ICONERROR | MB_OK);
	}

	if (!ReadProcessMemory(needsProcessHandle, (LPVOID)(firstOffsetValue + secondOffset), &currentValueOfCoin, sizeof(DWORD), &dwSize)) {
		MessageBox(NULL, TEXT("无法从地址获取数值"), TEXT("错误"), MB_ICONERROR | MB_OK);
	}

	int valueToModify = (valueToIncrease / 10) + currentValueOfCoin;

	WriteProcessMemory(needsProcessHandle, (LPVOID)(firstOffsetValue + secondOffset), &valueToModify, sizeof(valueToModify), &dwSize);
}

void increaseFertilizer(HANDLE needsProcessHandle, int valueToIncrease) {
	DWORD currentValueOfCoin;
	
	DWORD baseAddress = 0x006A9EC0;
	DWORD baseAddressValue = 0;
	DWORD firstOffset = 0x82C;
	DWORD firstOffsetValue = 0;
	DWORD secondOffset = 0x1F8;
	SIZE_T dwSize = 0;

	if (!ReadProcessMemory(needsProcessHandle, (LPVOID)baseAddress, &baseAddressValue, sizeof(DWORD), &dwSize)) {
		MessageBox(NULL, TEXT("无法获取一级指针"), TEXT("错误"), MB_ICONERROR | MB_OK);
	}

	if (!ReadProcessMemory(needsProcessHandle, (LPVOID)(baseAddressValue + firstOffset), &firstOffsetValue, sizeof(DWORD), &dwSize)) {
		MessageBox(NULL, TEXT("无法获取二级指针"), TEXT("错误"), MB_ICONERROR | MB_OK);
	}

	if (!ReadProcessMemory(needsProcessHandle, (LPVOID)(firstOffsetValue + secondOffset), &currentValueOfCoin, sizeof(DWORD), &dwSize)) {
		MessageBox(NULL, TEXT("无法从地址获取数值"), TEXT("错误"), MB_ICONERROR | MB_OK);
	}

	int valueToModify = currentValueOfCoin + valueToIncrease;

	WriteProcessMemory(needsProcessHandle, (LPVOID)(firstOffsetValue + secondOffset), &valueToModify, sizeof(valueToModify), &dwSize);
}

void increaseBugSpray(HANDLE needsProcessHandle, int valueToIncrease) {
	DWORD currentValueOfBugSpray;
	
	DWORD baseAddress = 0x006A9EC0;
	DWORD baseAddressValue = 0;
	DWORD firstOffset = 0x82C;
	DWORD firstOffsetValue = 0;
	DWORD secondOffset = 0x1FC;
	SIZE_T dwSize = 0;

	if (!ReadProcessMemory(needsProcessHandle, (LPVOID)baseAddress, &baseAddressValue, sizeof(DWORD), &dwSize)) {
		MessageBox(NULL, TEXT("无法获取一级指针"), TEXT("错误"), MB_ICONERROR | MB_OK);
	}

	if (!ReadProcessMemory(needsProcessHandle, (LPVOID)(baseAddressValue + firstOffset), &firstOffsetValue, sizeof(DWORD), &dwSize)) {
		MessageBox(NULL, TEXT("无法获取二级指针"), TEXT("错误"), MB_ICONERROR | MB_OK);
	}

	if (!ReadProcessMemory(needsProcessHandle, (LPVOID)(firstOffsetValue + secondOffset), &currentValueOfBugSpray, sizeof(DWORD), &dwSize)) {
		MessageBox(NULL, TEXT("无法从地址获取数值"), TEXT("错误"), MB_ICONERROR | MB_OK);
	}

	int valueToModify = currentValueOfBugSpray + valueToIncrease;

	WriteProcessMemory(needsProcessHandle, (LPVOID)(firstOffsetValue + secondOffset), &valueToModify, sizeof(valueToModify), &dwSize);
}

void increaseChocolate(HANDLE needsProcessHandle, int valueToIncrease) {
	DWORD currentValueOfChocolate;
	
	DWORD baseAddress = 0x006A9EC0;
	DWORD baseAddressValue = 0;
	DWORD firstOffset = 0x82C;
	DWORD firstOffsetValue = 0;
	DWORD secondOffset = 0x228;
	SIZE_T dwSize = 0;

	if (!ReadProcessMemory(needsProcessHandle, (LPVOID)baseAddress, &baseAddressValue, sizeof(DWORD), &dwSize)) {
		MessageBox(NULL, TEXT("无法获取一级指针"), TEXT("错误"), MB_ICONERROR | MB_OK);
	}

	if (!ReadProcessMemory(needsProcessHandle, (LPVOID)(baseAddressValue + firstOffset), &firstOffsetValue, sizeof(DWORD), &dwSize)) {
		MessageBox(NULL, TEXT("无法获取二级指针"), TEXT("错误"), MB_ICONERROR | MB_OK);
	}

	if (!ReadProcessMemory(needsProcessHandle, (LPVOID)(firstOffsetValue + secondOffset), &currentValueOfChocolate, sizeof(DWORD), &dwSize)) {
		MessageBox(NULL, TEXT("无法从地址获取数值"), TEXT("错误"), MB_ICONERROR | MB_OK);
	}

	int valueToModify = currentValueOfChocolate + valueToIncrease;

	WriteProcessMemory(needsProcessHandle, (LPVOID)(firstOffsetValue + secondOffset), &valueToModify, sizeof(valueToModify), &dwSize);
}

void increaseTreeFood(HANDLE needsProcessHandle, int valueToIncrease) {
	DWORD currentValueOfTreeFood;
	
	DWORD baseAddress = 0x006A9EC0;
	DWORD baseAddressValue = 0;
	DWORD firstOffset = 0x82C;
	DWORD firstOffsetValue = 0;
	DWORD secondOffset = 0x230;
	SIZE_T dwSize = 0;

	if (!ReadProcessMemory(needsProcessHandle, (LPVOID)baseAddress, &baseAddressValue, sizeof(DWORD), &dwSize)) {
		MessageBox(NULL, TEXT("无法获取一级指针"), TEXT("错误"), MB_ICONERROR | MB_OK);
	}

	if (!ReadProcessMemory(needsProcessHandle, (LPVOID)(baseAddressValue + firstOffset), &firstOffsetValue, sizeof(DWORD), &dwSize)) {
		MessageBox(NULL, TEXT("无法获取二级指针"), TEXT("错误"), MB_ICONERROR | MB_OK);
	}

	if (!ReadProcessMemory(needsProcessHandle, (LPVOID)(firstOffsetValue + secondOffset), &currentValueOfTreeFood, sizeof(DWORD), &dwSize)) {
		MessageBox(NULL, TEXT("无法从地址获取数值"), TEXT("错误"), MB_ICONERROR | MB_OK);
	}

	int valueToModify = currentValueOfTreeFood + valueToIncrease;

	WriteProcessMemory(needsProcessHandle, (LPVOID)(firstOffsetValue + secondOffset), &valueToModify, sizeof(valueToModify), &dwSize);
}

void decreaseSun(HANDLE needsProcessHandle, int valueToDecrease) {
	DWORD currentValueOfSun;

	DWORD baseAddress = 0x006A9EC0;
	DWORD baseAddressValue = 0;
	DWORD firstOffset = 0x768;
	DWORD firstOffsetValue = 0;
	DWORD secondOffset = 0x5560;
	SIZE_T dwSize = 0;

	if (!ReadProcessMemory(needsProcessHandle, (LPVOID)baseAddress, &baseAddressValue, sizeof(DWORD), &dwSize)) {
		MessageBox(NULL, TEXT("无法获取一级指针"), TEXT("错误"), MB_ICONERROR | MB_OK);
	}

	if (!ReadProcessMemory(needsProcessHandle, (LPVOID)(baseAddressValue + firstOffset), &firstOffsetValue, sizeof(DWORD), &dwSize)) {
		MessageBox(NULL, TEXT("无法获取二级指针"), TEXT("错误"), MB_ICONERROR | MB_OK);
	}
	if (!ReadProcessMemory(needsProcessHandle, (LPVOID)(firstOffsetValue + secondOffset), &currentValueOfSun, sizeof(DWORD), &dwSize)) {
		MessageBox(NULL, TEXT("无法从地址获取数值"), TEXT("错误"), MB_ICONERROR | MB_OK);
	}

	int valueToModify = currentValueOfSun - valueToDecrease;

	WriteProcessMemory(needsProcessHandle, (LPVOID)(firstOffsetValue + secondOffset), &valueToModify, sizeof(valueToModify), &dwSize);
}

void decreaseCoin(HANDLE needsProcessHandle, int valueToDecrease) {
	DWORD currentValueOfCoin;

	DWORD baseAddress = 0x006A9EC0;
	DWORD baseAddressValue = 0;
	DWORD firstOffset = 0x82C;
	DWORD firstOffsetValue = 0;
	DWORD secondOffset = 0x28;
	SIZE_T dwSize = 0;

	if (!ReadProcessMemory(needsProcessHandle, (LPVOID)baseAddress, &baseAddressValue, sizeof(DWORD), &dwSize)) {
		MessageBox(NULL, TEXT("无法获取一级指针"), TEXT("错误"), MB_ICONERROR | MB_OK);
	}

	if (!ReadProcessMemory(needsProcessHandle, (LPVOID)(baseAddressValue + firstOffset), &firstOffsetValue, sizeof(DWORD), &dwSize)) {
		MessageBox(NULL, TEXT("无法获取二级指针"), TEXT("错误"), MB_ICONERROR | MB_OK);
	}

	if (!ReadProcessMemory(needsProcessHandle, (LPVOID)(firstOffsetValue + secondOffset), &currentValueOfCoin, sizeof(DWORD), &dwSize)) {
		MessageBox(NULL, TEXT("无法从地址获取数值"), TEXT("错误"), MB_ICONERROR | MB_OK);
	}

	int valueToModify = currentValueOfCoin - (valueToDecrease / 10);

	WriteProcessMemory(needsProcessHandle, (LPVOID)(firstOffsetValue + secondOffset), &valueToModify, sizeof(valueToModify), &dwSize);
}

void decreaseFertilizer(HANDLE needsProcessHandle, int valueToDecrease) {
	DWORD currentValueOfCoin;

	DWORD baseAddress = 0x006A9EC0;
	DWORD baseAddressValue = 0;
	DWORD firstOffset = 0x82C;
	DWORD firstOffsetValue = 0;
	DWORD secondOffset = 0x1F8;
	SIZE_T dwSize = 0;

	if (!ReadProcessMemory(needsProcessHandle, (LPVOID)baseAddress, &baseAddressValue, sizeof(DWORD), &dwSize)) {
		MessageBox(NULL, TEXT("无法获取一级指针"), TEXT("错误"), MB_ICONERROR | MB_OK);
	}

	if (!ReadProcessMemory(needsProcessHandle, (LPVOID)(baseAddressValue + firstOffset), &firstOffsetValue, sizeof(DWORD), &dwSize)) {
		MessageBox(NULL, TEXT("无法获取二级指针"), TEXT("错误"), MB_ICONERROR | MB_OK);
	}

	if (!ReadProcessMemory(needsProcessHandle, (LPVOID)(firstOffsetValue + secondOffset), &currentValueOfCoin, sizeof(DWORD), &dwSize)) {
		MessageBox(NULL, TEXT("无法从地址获取数值"), TEXT("错误"), MB_ICONERROR | MB_OK);
	}

	int valueToModify = currentValueOfCoin - valueToDecrease;

	WriteProcessMemory(needsProcessHandle, (LPVOID)(firstOffsetValue + secondOffset), &valueToModify, sizeof(valueToModify), &dwSize);
}

void decreaseBugSpray(HANDLE needsProcessHandle, int valueToDecrease) {
	DWORD currentValueOfBugSpray;

	DWORD baseAddress = 0x006A9EC0;
	DWORD baseAddressValue = 0;
	DWORD firstOffset = 0x82C;
	DWORD firstOffsetValue = 0;
	DWORD secondOffset = 0x1FC;
	SIZE_T dwSize = 0;

	if (!ReadProcessMemory(needsProcessHandle, (LPVOID)baseAddress, &baseAddressValue, sizeof(DWORD), &dwSize)) {
		MessageBox(NULL, TEXT("无法获取一级指针"), TEXT("错误"), MB_ICONERROR | MB_OK);
	}

	if (!ReadProcessMemory(needsProcessHandle, (LPVOID)(baseAddressValue + firstOffset), &firstOffsetValue, sizeof(DWORD), &dwSize)) {
		MessageBox(NULL, TEXT("无法获取二级指针"), TEXT("错误"), MB_ICONERROR | MB_OK);
	}

	if (!ReadProcessMemory(needsProcessHandle, (LPVOID)(firstOffsetValue + secondOffset), &currentValueOfBugSpray, sizeof(DWORD), &dwSize)) {
		MessageBox(NULL, TEXT("无法从地址获取数值"), TEXT("错误"), MB_ICONERROR | MB_OK);
	}

	int valueToModify = currentValueOfBugSpray - valueToDecrease;

	WriteProcessMemory(needsProcessHandle, (LPVOID)(firstOffsetValue + secondOffset), &valueToModify, sizeof(valueToModify), &dwSize);
}

void decreaseChocolate(HANDLE needsProcessHandle, int valueToDecrease) {
	DWORD currentValueOfChocolate;

	DWORD baseAddress = 0x006A9EC0;
	DWORD baseAddressValue = 0;
	DWORD firstOffset = 0x82C;
	DWORD firstOffsetValue = 0;
	DWORD secondOffset = 0x228;
	SIZE_T dwSize = 0;

	if (!ReadProcessMemory(needsProcessHandle, (LPVOID)baseAddress, &baseAddressValue, sizeof(DWORD), &dwSize)) {
		MessageBox(NULL, TEXT("无法获取一级指针"), TEXT("错误"), MB_ICONERROR | MB_OK);
	}

	if (!ReadProcessMemory(needsProcessHandle, (LPVOID)(baseAddressValue + firstOffset), &firstOffsetValue, sizeof(DWORD), &dwSize)) {
		MessageBox(NULL, TEXT("无法获取二级指针"), TEXT("错误"), MB_ICONERROR | MB_OK);
	}

	if (!ReadProcessMemory(needsProcessHandle, (LPVOID)(firstOffsetValue + secondOffset), &currentValueOfChocolate, sizeof(DWORD), &dwSize)) {
		MessageBox(NULL, TEXT("无法从地址获取数值"), TEXT("错误"), MB_ICONERROR | MB_OK);
	}

	int valueToModify = currentValueOfChocolate - valueToDecrease;

	WriteProcessMemory(needsProcessHandle, (LPVOID)(firstOffsetValue + secondOffset), &valueToModify, sizeof(valueToModify), &dwSize);
}

void decreaseTreeFood(HANDLE needsProcessHandle, int valueToDecrease) {
	DWORD currentValueOfTreeFood;

	DWORD baseAddress = 0x006A9EC0;
	DWORD baseAddressValue = 0;
	DWORD firstOffset = 0x82C;
	DWORD firstOffsetValue = 0;
	DWORD secondOffset = 0x230;
	SIZE_T dwSize = 0;

	if (!ReadProcessMemory(needsProcessHandle, (LPVOID)baseAddress, &baseAddressValue, sizeof(DWORD), &dwSize)) {
		MessageBox(NULL, TEXT("无法获取一级指针"), TEXT("错误"), MB_ICONERROR | MB_OK);
	}

	if (!ReadProcessMemory(needsProcessHandle, (LPVOID)(baseAddressValue + firstOffset), &firstOffsetValue, sizeof(DWORD), &dwSize)) {
		MessageBox(NULL, TEXT("无法获取二级指针"), TEXT("错误"), MB_ICONERROR | MB_OK);
	}

	if (!ReadProcessMemory(needsProcessHandle, (LPVOID)(firstOffsetValue + secondOffset), &currentValueOfTreeFood, sizeof(DWORD), &dwSize)) {
		MessageBox(NULL, TEXT("无法从地址获取数值"), TEXT("错误"), MB_ICONERROR | MB_OK);
	}

	int valueToModify = currentValueOfTreeFood - valueToDecrease;

	WriteProcessMemory(needsProcessHandle, (LPVOID)(firstOffsetValue + secondOffset), &valueToModify, sizeof(valueToModify), &dwSize);
}

void clearSun(HANDLE needsProcessHandle) {
	DWORD baseAddress = 0x006A9EC0;
	DWORD baseAddressValue = 0;
	DWORD firstOffset = 0x768;
	DWORD firstOffsetValue = 0;
	DWORD secondOffset = 0x5560;
	SIZE_T dwSize = 0;

	int numberOfSun = 0;

	if (!ReadProcessMemory(needsProcessHandle, (LPVOID)baseAddress, &baseAddressValue, sizeof(DWORD), &dwSize)) {
		MessageBox(NULL, TEXT("无法获取一级指针"), TEXT("错误"), MB_ICONERROR | MB_OK);
	}

	if (!ReadProcessMemory(needsProcessHandle, (LPVOID)(baseAddressValue + firstOffset), &firstOffsetValue, sizeof(DWORD), &dwSize)) {
		MessageBox(NULL, TEXT("无法获取二级指针"), TEXT("错误"), MB_ICONERROR | MB_OK);
	}

	WriteProcessMemory(needsProcessHandle, (LPVOID)(firstOffsetValue + secondOffset), &numberOfSun, sizeof(numberOfSun), &dwSize);
}

void clearNumberOfCoin(HANDLE needsProcessHandle) {
	DWORD baseAddress = 0x006A9EC0;
	DWORD baseAddressValue = 0;
	DWORD firstOffset = 0x82C;
	DWORD firstOffsetValue = 0;
	DWORD secondOffset = 0x28;
	SIZE_T dwSize = 0;

	int numberOfCoin = 0;

	if (!ReadProcessMemory(needsProcessHandle, (LPVOID)baseAddress, &baseAddressValue, sizeof(DWORD), &dwSize)) {
		MessageBox(NULL, TEXT("无法获取一级指针"), TEXT("错误"), MB_ICONERROR | MB_OK);
	}

	if (!ReadProcessMemory(needsProcessHandle, (LPVOID)(baseAddressValue + firstOffset), &firstOffsetValue, sizeof(DWORD), &dwSize)) {
		MessageBox(NULL, TEXT("无法获取二级指针"), TEXT("错误"), MB_ICONERROR | MB_OK);
	}

	WriteProcessMemory(needsProcessHandle, (LPVOID)(firstOffsetValue + secondOffset), &numberOfCoin, sizeof(numberOfCoin), &dwSize);
}

void clearFertilizer(HANDLE needsProcessHandle) {
	DWORD baseAddress = 0x006A9EC0;
	DWORD baseAddressValue = 0;
	DWORD firstOffset = 0x82C;
	DWORD firstOffsetValue = 0;
	DWORD secondOffset = 0x1F8;
	SIZE_T dwSize = 0;

	int numberOfFertilizer = 1000;

	if (!ReadProcessMemory(needsProcessHandle, (LPVOID)baseAddress, &baseAddressValue, sizeof(DWORD), &dwSize)) {
		MessageBox(NULL, TEXT("无法获取一级指针"), TEXT("错误"), MB_ICONERROR | MB_OK);
	}

	if (!ReadProcessMemory(needsProcessHandle, (LPVOID)(baseAddressValue + firstOffset), &firstOffsetValue, sizeof(DWORD), &dwSize)) {
		MessageBox(NULL, TEXT("无法获取二级指针"), TEXT("错误"), MB_ICONERROR | MB_OK);
	}

	WriteProcessMemory(needsProcessHandle, (LPVOID)(firstOffsetValue + secondOffset), &numberOfFertilizer, sizeof(numberOfFertilizer), &dwSize);
}

void clearBugSpray(HANDLE needsProcessHandle) {
	DWORD baseAddress = 0x006A9EC0;
	DWORD baseAddressValue = 0;
	DWORD firstOffset = 0x82C;
	DWORD firstOffsetValue = 0;
	DWORD secondOffset = 0x1FC;
	SIZE_T dwSize = 0;

	int numberOfBugSpray = 1000;

	if (!ReadProcessMemory(needsProcessHandle, (LPVOID)baseAddress, &baseAddressValue, sizeof(DWORD), &dwSize)) {
		MessageBox(NULL, TEXT("无法获取一级指针"), TEXT("错误"), MB_ICONERROR | MB_OK);
	}

	if (!ReadProcessMemory(needsProcessHandle, (LPVOID)(baseAddressValue + firstOffset), &firstOffsetValue, sizeof(DWORD), &dwSize)) {
		MessageBox(NULL, TEXT("无法获取二级指针"), TEXT("错误"), MB_ICONERROR | MB_OK);
	}

	WriteProcessMemory(needsProcessHandle, (LPVOID)(firstOffsetValue + secondOffset), &numberOfBugSpray, sizeof(numberOfBugSpray), &dwSize);
}

void clearChocolate(HANDLE needsProcessHandle) {
	DWORD baseAddress = 0x006A9EC0;
	DWORD baseAddressValue = 0;
	DWORD firstOffset = 0x82C;
	DWORD firstOffsetValue = 0;
	DWORD secondOffset = 0x228;
	SIZE_T dwSize = 0;

	int numberOfChocolate = 1000;

	if (!ReadProcessMemory(needsProcessHandle, (LPVOID)baseAddress, &baseAddressValue, sizeof(DWORD), &dwSize)) {
		MessageBox(NULL, TEXT("无法获取一级指针"), TEXT("错误"), MB_ICONERROR | MB_OK);
	}

	if (!ReadProcessMemory(needsProcessHandle, (LPVOID)(baseAddressValue + firstOffset), &firstOffsetValue, sizeof(DWORD), &dwSize)) {
		MessageBox(NULL, TEXT("无法获取二级指针"), TEXT("错误"), MB_ICONERROR | MB_OK);
	}

	WriteProcessMemory(needsProcessHandle, (LPVOID)(firstOffsetValue + secondOffset), &numberOfChocolate, sizeof(numberOfChocolate), &dwSize);
}

void clearTreeFood(HANDLE needsProcessHandle) {
	DWORD baseAddress = 0x006A9EC0;
	DWORD baseAddressValue = 0;
	DWORD firstOffset = 0x82C;
	DWORD firstOffsetValue = 0;
	DWORD secondOffset = 0x230;
	SIZE_T dwSize = 0;

	int numberOfTreeFood = 1000;

	if (!ReadProcessMemory(needsProcessHandle, (LPVOID)baseAddress, &baseAddressValue, sizeof(DWORD), &dwSize)) {
		MessageBox(NULL, TEXT("无法获取一级指针"), TEXT("错误"), MB_ICONERROR | MB_OK);
	}

	if (!ReadProcessMemory(needsProcessHandle, (LPVOID)(baseAddressValue + firstOffset), &firstOffsetValue, sizeof(DWORD), &dwSize)) {
		MessageBox(NULL, TEXT("无法获取二级指针"), TEXT("错误"), MB_ICONERROR | MB_OK);
	}

	WriteProcessMemory(needsProcessHandle, (LPVOID)(firstOffsetValue + secondOffset), &numberOfTreeFood, sizeof(numberOfTreeFood), &dwSize);
}
