#pragma once

void sunNotDecrease(HANDLE needsProcessHandle, BOOL onOrOff); // ���ⲻ����
void noCoolingDownTime(HANDLE needsProcessHandle, BOOL onOrOff); // ֲ�￨Ƭ����ȴʱ��
void killZombiesImmediately(HANDLE needsProcessHandle, BOOL onOrOff); // ��ʬ��ɱ
void feelfreePlantPlants(HANDLE needsProcessHandle, BOOL onOrOff); // ֲ��ѵ�

void infiniteSun(HANDLE needsProcessHandle); // ��������
void infiniteCoin(HANDLE needsProcessHandle); // ���޽��
void infiniteFertilizer(HANDLE needsProcessHandle); // ���޷���
void infiniteBugSpray(HANDLE needsProcessHandle); // ����ɱ���
void infiniteChocolate(HANDLE needsProcessHandle); // �����ɿ���
void infiniteTreeFood(HANDLE needsProcessHandle); // ��������

void modifyNumberOfSun(HANDLE needsProcessHandle, int valueToModify); // �޸�������
void modifyNumberOfCoin(HANDLE needsProcessHandle, int valueToModify); // �޸Ľ������
void modifyNumberOfFertilizer(HANDLE needsProcessHandle, int valueToModify); // �޸ķ�������
void modifyNumberOfBugSpray(HANDLE needsProcessHandle, int valueToModify); // �޸�ɱ�������
void modifyNumberOfChocolate(HANDLE needsProcessHandle, int valueToModify); // �޸��ɿ�������
void modifyNumberOfTreeFood(HANDLE needsProcessHandle, int valueToModify); // �޸���������

void increaseSun(HANDLE needsProcessHandle, int valueToIncrease); // ����������ֵ
void increaseCoin(HANDLE needsProcessHandle, int valueToIncrease); // ���ӽ������
void increaseFertilizer(HANDLE needsProcessHandle, int valueToIncrease); // ���ӷ�������
void increaseBugSpray(HANDLE needsProcessHandle, int valueToIncrease); // ����ɱ�������
void increaseChocolate(HANDLE needsProcessHandle, int valueToIncrease); // �����ɿ�������
void increaseTreeFood(HANDLE needsProcessHandle, int valueToIncrease); // ������������

void decreaseSun(HANDLE needsProcessHandle, int valueToDecrease); // ����������ֵ
void decreaseCoin(HANDLE needsProcessHandle, int valueToDecrease); // ���ٽ������
void decreaseFertilizer(HANDLE needsProcessHandle, int valueToDecrease); // ���ٷ�������
void decreaseBugSpray(HANDLE needsProcessHandle, int valueToDecrease); // ����ɱ�������
void decreaseChocolate(HANDLE needsProcessHandle, int valueToDecrease); // �����ɿ�������
void decreaseTreeFood(HANDLE needsProcessHandle, int valueToDecrease); // ������������

void clearSun(HANDLE needsProcessHandle); // �����������㣨�������㣿�б�Ҫ�𣿣�
void clearNumberOfCoin(HANDLE needsProcessHandle); // �����������
void clearFertilizer(HANDLE needsProcessHandle); // ������������
void clearBugSpray(HANDLE needsProcessHandle); // ɱ�����������
void clearChocolate(HANDLE needsProcessHandle); // �ɿ�����������
void clearTreeFood(HANDLE needsProcessHandle); // ������������
