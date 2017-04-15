/* 
 * tic-tac-toe.cpp
 *
 *       Copyright (c) Ruvendix. ��� ���۱��� ���ο��� �ֽ��ϴ�.
 *
 * �� ������ C++ ���� ���α׷��� Ʃ�丮���� ���� �����Դϴ�.
 * ��쿡 ���󼭴� C++11 �̻��� ���뵵 ���Ե� �� �ֽ��ϴ�.
 * ����� �� ������ ���� �ڵ� ���̵带 �����ϴ�.
 *
 * tic-tac-toe.cpp�� ƽ���� ������ �����ϴ�.
 * 3 X 3 üĿ�ǿ��� ����Ǵ� ����������
 * üĿ���� ǥ���� �� �����Ƿ� �׳� 3 X 3 ���� �̿��մϴ�.
 * ƽ����� ���� �����ϸ� 3���Դϴ�. ���� 3���� ����� ���� �¸��մϴ�.
 */

// std::cout�� ����� �����ִ� ��� ����
#include <iomanip>

// ǥ�� ������� ���� C++�� ��� ����
// using namespace std;�� �̿����� ����!
#include <iostream>

// std::string�� ���� ��� ����
// string.h�� �ƴ϶� string��!
#include <string>

// �⺻ ��ο��� ������ ã�ƾ� ��!
#include "game-manager/game-manager.h"

// ���α׷��� ������
// ��, ���α׷��� ���۵Ǵ� �κ�!
int main()
{
	system("title ƽ���� ����");
	
	// �ܼ� â ũ�� ���� ����
	system("mode con: lines=25 cols=80");

	TicTacToeMgr game_mgr;

	// ������ ������ ���� Ȯ���ϴ� ����
	bool game_end = false;

	while (game_end == false)
	{
		game_end = game_mgr.StartGame();
	}

	// �ڵ� ���� ����!
	system("pause");

	// ���α׷��� ���������� ����ȴٴ� ���� �ǹ�
	// exit(EXIT_SUCCESS); �̰Ͱ� �����!
	return 0;
}