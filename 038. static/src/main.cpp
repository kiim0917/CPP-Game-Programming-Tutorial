/*
 * ���� �̸� : main.cpp
 * ���� ��¥ : 2017-07-25
 * ���� ��� : Ruvendix
 *
 * ���� ���� : static �ʵ�� static �޼��带 �׽�Ʈ�մϴ�.
 */

#include <iostream>

#define PRESS_ENTER() printf("��� �����Ϸ��� ���͸� ��������.\n"); getchar();

#include "manger/IOManager.h"

int main()
{
	mgr::IOManager::AppendStringToFile("Game.log", "���� �ʱ�ȭ!");
	printf("�ֱ� �۾��� ���� �̸� : %s\n", mgr::IOManager::GetLastFileName().c_str());

	mgr::IOManager::AppendStringToFile("Error.log", "���� �ʱ�ȭ ����!");
	printf("�ֱ� �۾��� ���� �̸� : %s\n", mgr::IOManager::GetLastFileName().c_str());

	mgr::IOManager::AppendStringToFile("Game.log", "���� ����!");
	printf("�ֱ� �۾��� ���� �̸� : %s\n", mgr::IOManager::GetLastFileName().c_str());

	PRESS_ENTER();

	return 0;
}