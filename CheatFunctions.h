#pragma once

void sunNotDecrease(HANDLE needsProcessHandle, BOOL onOrOff); // 阳光不减少
void noCoolingDownTime(HANDLE needsProcessHandle, BOOL onOrOff); // 植物卡片无冷却时间
void killZombiesImmediately(HANDLE needsProcessHandle, BOOL onOrOff); // 僵尸秒杀
void feelfreePlantPlants(HANDLE needsProcessHandle, BOOL onOrOff); // 植物堆叠

void infiniteSun(HANDLE needsProcessHandle); // 无限阳光
void infiniteCoin(HANDLE needsProcessHandle); // 无限金币
void infiniteFertilizer(HANDLE needsProcessHandle); // 无限肥料
void infiniteBugSpray(HANDLE needsProcessHandle); // 无限杀虫剂
void infiniteChocolate(HANDLE needsProcessHandle); // 无限巧克力
void infiniteTreeFood(HANDLE needsProcessHandle); // 无限树肥

void modifyNumberOfSun(HANDLE needsProcessHandle, int valueToModify); // 修改阳光数
void modifyNumberOfCoin(HANDLE needsProcessHandle, int valueToModify); // 修改金币数量
void modifyNumberOfFertilizer(HANDLE needsProcessHandle, int valueToModify); // 修改肥料数量
void modifyNumberOfBugSpray(HANDLE needsProcessHandle, int valueToModify); // 修改杀虫剂数量
void modifyNumberOfChocolate(HANDLE needsProcessHandle, int valueToModify); // 修改巧克力数量
void modifyNumberOfTreeFood(HANDLE needsProcessHandle, int valueToModify); // 修改树肥数量

void increaseSun(HANDLE needsProcessHandle, int valueToIncrease); // 增加阳光数值
void increaseCoin(HANDLE needsProcessHandle, int valueToIncrease); // 增加金币数量
void increaseFertilizer(HANDLE needsProcessHandle, int valueToIncrease); // 增加肥料数量
void increaseBugSpray(HANDLE needsProcessHandle, int valueToIncrease); // 增加杀虫剂数量
void increaseChocolate(HANDLE needsProcessHandle, int valueToIncrease); // 增加巧克力数量
void increaseTreeFood(HANDLE needsProcessHandle, int valueToIncrease); // 增加树肥数量

void decreaseSun(HANDLE needsProcessHandle, int valueToDecrease); // 减少阳光数值
void decreaseCoin(HANDLE needsProcessHandle, int valueToDecrease); // 减少金币数量
void decreaseFertilizer(HANDLE needsProcessHandle, int valueToDecrease); // 减少肥料数量
void decreaseBugSpray(HANDLE needsProcessHandle, int valueToDecrease); // 减少杀虫剂数量
void decreaseChocolate(HANDLE needsProcessHandle, int valueToDecrease); // 减少巧克力数量
void decreaseTreeFood(HANDLE needsProcessHandle, int valueToDecrease); // 减少树肥数量

void clearSun(HANDLE needsProcessHandle); // 阳光数量清零（阳光清零？有必要吗？）
void clearNumberOfCoin(HANDLE needsProcessHandle); // 金币数量清零
void clearFertilizer(HANDLE needsProcessHandle); // 肥料数量清零
void clearBugSpray(HANDLE needsProcessHandle); // 杀虫剂数量清零
void clearChocolate(HANDLE needsProcessHandle); // 巧克力数量清零
void clearTreeFood(HANDLE needsProcessHandle); // 树肥数量清零
