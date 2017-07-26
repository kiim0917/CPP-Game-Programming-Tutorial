/*
 * ���� �̸� : main.cpp
 * ���� ��¥ : 2017-07-26
 * ���� ��� : Ruvendix
 *
 * ���� ���� : ���� ���¸� �׽�Ʈ�մϴ�.
 */

#include <ctime>
#include <iostream>
#include <random>

#define PRESS_ENTER() printf("��� �����Ϸ��� ���͸� ��������.\n"); getchar();

// ���� ���¸� ���������� ����!
// C++11 ���Ŀ��� enum class�� Ȱ��!
enum class GameState : int
{
	INIT,  // �⺻���� 0
	TITLE, // ������ ���� 1�� ����
	OPTION,
	SCENE,
	PAUSE,
	RELEASE,
	NONE,
};

// ���� ����ó�� ���� ������ ���̴� ����
// ���� ������ �����ϴ� �� ����!
// �Ŵ��� Ŭ������ �̿��ؼ� ȣ���ϴ� ����� ����!
GameState g_gameState = GameState::NONE;

int GameStateCheck();

int main()
{
	std::uniform_int_distribution<int> randomIndex(0, 6);
	std::default_random_engine randomEngine;

	time_t oldTime = clock();
	time_t newTime = clock();

	// ���� ������ �̷� �����ε� �����!
	for ( ; ; )
	{
		newTime = clock();

		// 2�� �������� ����
		if (newTime - oldTime > 2000)
		{
			oldTime = newTime;

			g_gameState = static_cast<GameState>(randomIndex(randomEngine));
			GameStateCheck();
		}		
	}

	PRESS_ENTER();

	return 0;
}

int GameStateCheck()
{
	switch (g_gameState)
	{
	case GameState::INIT    : printf("���� �ʱ�ȭ ���Դϴ�.\n");   break;
	case GameState::TITLE   : printf("���� Ÿ��Ʋ ȭ���Դϴ�.\n"); break;
	case GameState::OPTION  : printf("���� �ɼ� ȭ���Դϴ�.\n");   break;
	case GameState::SCENE   : printf("���� ����Դϴ�.\n");        break;
	case GameState::PAUSE   : printf("���� ���� ȭ���Դϴ�.\n");   break;
	case GameState::RELEASE : printf("���� ���� ���Դϴ�.\n");     break;
	}

	return 0;
}