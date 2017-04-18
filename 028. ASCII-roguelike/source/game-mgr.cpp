/*
 * game-mgr.cpp
 *
 *       Copyright (c) Ruvendix. ��� ���۱��� ���ο��� �ֽ��ϴ�.
 *
 * �� ������ C++ ���� ���α׷��� Ʃ�丮���� ���� �����Դϴ�.
 * ��쿡 ���󼭴� C++11 �̻��� ���뵵 ���Ե� �� �ֽ��ϴ�.
 * ����� �� ������ ���� �ڵ� ���̵带 �����ϴ�.
 *
 * game-mgr.cpp�� GameMGR Ŭ������ ���ǵǾ��ֽ��ϴ�.
 * ������ 4�� ������ ���� �ʱ�ȭ, ���� ����, ���� ���, ���� ������ �� ������.
 */

// ���� ���� ��� ������ include ������ ����
#include "../include/game-mgr.h"

// ǥ�� ������� ���� C++�� ��� ����
// using namespace std;�� �̿����� ����!
// cstdio�� ���ԵǾ������Ƿ� C ��Ÿ���� ǥ�� ����µ� ��� ����!
#include <iostream>

// std::string�� ���� ��� ����
// string.h�� �ƴ϶� string��!
#include <string>

// ���� ���� �ʱ�ȭ
bool GameMGR::Init()
{
	// ���̸� �ʱ�ȭ
	Player player(0, 0, 100, 10, 5, 0, '@');
	player_ = player;

	printf("������ �ʱ�ȭ�߽��ϴ�!\n\n");
	return true;
}

// ���� ���� ����
int GameMGR::Update()
{
	char input;
	printf("q�� �Է��ϸ� ������ ����˴ϴ� : ");
	scanf("%c", &input);
	std::cin.ignore(); // �Է� ���ۿ� �����ִ� ���� ����

	// q�� �Է��ϸ� ���� ����
	if (input == tolower('q'))
	{
		printf("\n");
		return 1;
	}

	printf("���� ������ �����߽��ϴ�!\n");
	return 0;
}

// ���� ���� ���
void GameMGR::Show()
{
	printf("----------------------------\n");
	player_.get_info().ShowUnitInfo();
	printf("----------------------------\n");
	printf("���� ������ ����߽��ϴ�!\n\n");
}

// ���� ���� ����
void GameMGR::Release()
{
	printf("���� ������ �����߽��ϴ�!\n");
}