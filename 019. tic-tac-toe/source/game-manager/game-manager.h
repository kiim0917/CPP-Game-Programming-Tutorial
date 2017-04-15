/*
 * game-manager.h
 *
 *       Copyright (c) Ruvendix. ��� ���۱��� ���ο��� �ֽ��ϴ�.
 *
 * �� ������ C++ ���� ���α׷��� Ʃ�丮���� ���� �����Դϴ�.
 * ��쿡 ���󼭴� C++11 �̻��� ���뵵 ���Ե� �� �ֽ��ϴ�.
 * ����� �� ������ ���� �ڵ� ���̵带 �����ϴ�.
 *
 * game-manager.h�� TicTacToeMgr Ŭ������ ����Ǿ��ִ� �����Դϴ�.
 * �ζ��� ���ĵ� ������ �ܺο��� �����ϴ� ���ĵ� �ֽ��ϴ�.
 * ƽ���� ������ �����ų �ʵ�� �޼��尡 �ֽ��ϴ�.
 */

// <������Ʈ �̸�>_<�ҽ� ������ ���>_<�ҽ� ������ �̸�>
#ifndef TICTACTOE_GAMEMANAGER_GAMEMANAGER_H_
#define TICTACTOE_GAMEMANAGER_GAMEMANAGER_H_

#include <string>

class TicTacToeMgr
{
public:
	void InitBoard();
	void ShowBoard();
	void ShowInfo();
	char InputMarker(const std::string &player);
	bool StartGame();
	bool InputMarkerInBoard();
	bool CheckWinner();
	bool RestartGame();
protected:

private:
	char board_[3][3];    // ���������� ����� 2���� �迭
	char player1_marker_; // �÷��̾�1�� ǥ��
	char player2_marker_; // �÷��̾�2�� ǥ��
	char current_player_; // ���� �÷��̾��� ǥ��
	int  turn_;           // ������ �� ��
};

#endif