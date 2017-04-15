/*
 * game-manager.cpp
 *
 *       Copyright (c) Ruvendix. ��� ���۱��� ���ο��� �ֽ��ϴ�.
 *
 * �� ������ C++ ���� ���α׷��� Ʃ�丮���� ���� �����Դϴ�.
 * ��쿡 ���󼭴� C++11 �̻��� ���뵵 ���Ե� �� �ֽ��ϴ�.
 * ����� �� ������ ���� �ڵ� ���̵带 �����ϴ�.
 *
 * game-manager.cpp�� TicTacToeMgr Ŭ������ ���ǵǾ��ִ� �����Դϴ�.
 * TicTacToeMgr Ŭ������ �޼���� �� ���Ͽ� ���ǵǾ��ֽ��ϴ�.
 * ������ �ʱ�ȭ -> ���� ���� -> �¸� ������ �帧�� �� ������.
 */

// �ҽ� ���ϰ� ��� ������ ���� ������ ������
// �׳� ��� ���ϸ� �����ϸ� ��
#include "game-manager.h"

#include <iostream>

// ���� ����
bool TicTacToeMgr::StartGame()
{
	// ������ �������� Ȯ���ϴ� ����
	bool game_over = false;

	InitBoard();
	player1_marker_ = InputMarker("�÷��̾�1");
	player2_marker_ = InputMarker("�÷��̾�2");
	
	// ���ºθ� Ȯ���� ����
	// 3 X 3���ε� �ǿ����� 9�� �ִ���
	turn_ = 0;

	std::cout << "\n<ƽ���� ������ �����մϴ�!>\n\n";
	
	// �÷��̾�1�� ���� ����
	current_player_ = player1_marker_;

	while (game_over == false)
	{
		ShowInfo();

		// ���� �÷��̾�1�� �Է�
		InputMarkerInBoard();

		// �¸� �����ϱ�
		if (CheckWinner() == true)
		{
			system("cls");
			ShowInfo();

			if (current_player_ == player1_marker_)
			{
				std::cout << "�÷��̾�1�� �¸�!\n";
			}
			else
			{
				std::cout << "�÷��̾�2�� �¸�!\n";
			}

			game_over = true;
		}
		else if (turn_ == 9)
		{
			system("cls");
			ShowInfo();

			std::cout << "���º�!\n";
			game_over = true;
		}

		if (game_over == false)
		{
			// �÷��̾� ����
			if (current_player_ == player1_marker_)
			{
				current_player_ = player2_marker_;
			}
			else
			{
				current_player_ = player1_marker_;
			}

			system("pause");
			system("cls");
		}
	}

	// ������ �ٽ� ������ ���� Ȯ����
	// main()�� �ִ� game_end�� false�� �ٽ� ����!
	// game_end�� true�� ������ �����Ѵٴ� ���� �򰥸��� �ȵ�!
	if (RestartGame() == true)
	{
		std::cout << "������ �ٽ� �����մϴ�!\n";
		system("pause");
		system("cls");
		return false;
	}
	else
	{
		std::cout << "������ �����մϴ�!\n";
		return true;
	}
	return false;
}

// ������ �ʱ�ȭ
void TicTacToeMgr::InitBoard()
{
	for (int row = 0; row < 3; ++row)
	{
		for (int col = 0; col < 3; ++col)
		{
			board_[row][col] = ' ';
		}
	}
}

// ������ ���
void TicTacToeMgr::ShowBoard()
{
	std::cout << " |1|2|3|\n";
	for (int row = 0; row < 3; ++row)
	{
		std::cout << " -------\n";
		std::cout << row + 1 << "|";
		for (int col = 0; col < 3; ++col)
		{
			std::cout << board_[row][col] << "|";
		}
		std::cout << std::endl;
	}
	std::cout << " -------\n";
}

// ���� ���� ���
void TicTacToeMgr::ShowInfo()
{
	std::cout << "�÷��̾�1�� ǥ�� : " << player1_marker_ << std::endl;
	std::cout << "�÷��̾�2�� ǥ�� : " << player2_marker_ << std::endl;
	std::cout << "���� �÷��̾�    : " << current_player_ << std::endl << std::endl;

	if (turn_ == 9)
	{
		turn_--;
	}

	std::cout << "<" << turn_ + 1 << "��>" << std::endl;
	ShowBoard();
}

// �÷��̾��� ǥ�� �Է�
char TicTacToeMgr::InputMarker(const std::string &player)
{
	char marker;
	std::cout << player << "��(��) ����� ǥ�ø� �Է��ϼ��� : ";
	std::cin >> marker;
	return marker;
}

// �����ǿ� ǥ�� �Է�
bool TicTacToeMgr::InputMarkerInBoard()
{
	int row, col;

	std::cout << "��� ���� �Է��ϼ��� : ";
	std::cin >> row >> col;

	if (row - 1 < 0 ||
		row - 1 > 2 ||
		col - 1 < 0 ||
		col - 1 > 2)
	{
		std::cout << "��� ���� 1~3������ �����մϴ�!\n";
		std::cout << "���� �÷��̾�� ���ʰ� �Ѿ�ϴ�.\n";
		return false;
	}

	// �Է��� ��ġ�� ������� ��쿡�� ����!
	if (board_[row - 1][col - 1] == ' ')
	{
		board_[row - 1][col - 1] = current_player_;
		turn_++; // �Է��� �� ���� �� ����!
	}
	else
	{
		std::cout << "�� �ڸ��� �Է��� �� �����ϴ�!\n";
		std::cout << "���� �÷��̾�� ���ʰ� �Ѿ�ϴ�.\n";
		return false;
	}

	std::cout << "(" << row << ", " << col << ")�� �Է��߽��ϴ�.\n";
	return true;
}

// �¸� �����ϱ�
// �¸� ������ ���ذ��� ã�� ������ ������ ���ذ��� ������ Ȯ���ϸ� ��
bool TicTacToeMgr::CheckWinner()
{
	// ���� �����ϱ�
	for (int i = 0; i < 3; ++i)
	{
		if (board_[i][0] != ' ' &&
			board_[i][0] == board_[i][1] &&
			board_[i][1] == board_[i][2])
		{
			return true;
		}
	}

	// ���� �����ϱ�
	for (int i = 0; i < 3; ++i)
	{
		if (board_[0][i] != ' ' &&
			board_[0][i] == board_[1][i] &&
			board_[1][i] == board_[2][i])
		{
			return true;
		}
	}

	// ���� ������ ������ �Ʒ� �����ϱ�
	// \ �� ���
	if (board_[0][0] != ' ' &&
		board_[0][0] == board_[1][1] &&
		board_[1][1] == board_[2][2])
	{
		return true;
	}

	// ������ ������ ���� �Ʒ� �����ϱ�
	// / �� ���
	if (board_[0][2] != ' ' &&
		board_[0][2] == board_[1][1] &&
		board_[1][1] == board_[2][0])
	{
		return true;
	}
	return false;
}

// ���� �ٽ� �����ϱ�
bool TicTacToeMgr::RestartGame()
{
	char input;
	std::cout << "�ٽ� ������ �ǰ���? (y/n) : ";
	std::cin >> input;

	if (tolower(input) == 'y')
	{
		return true;
	}
	else
	{
		return false;
	}
	return false;
}
