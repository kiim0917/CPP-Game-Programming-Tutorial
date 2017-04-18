/*
 * game-mgr.h
 *
 *       Copyright (c) Ruvendix. ��� ���۱��� ���ο��� �ֽ��ϴ�.
 *
 * �� ������ C++ ���� ���α׷��� Ʃ�丮���� ���� �����Դϴ�.
 * ��쿡 ���󼭴� C++11 �̻��� ���뵵 ���Ե� �� �ֽ��ϴ�.
 * ����� �� ������ ���� �ڵ� ���̵带 �����ϴ�.
 *
 * game-mgr.h�� GameMGR Ŭ������ ����Ǿ��ֽ��ϴ�.
 * �ζ��� ���ĵ� �����Ƿ� �����Ͻñ� �ٶ��ϴ�.
 */

#ifndef ASCIIROGUELIKE_GAMEMGR_H_
#define ASCIIROGUELIKE_GAMEMGR_H_

#include "player.h"

class GameMGR
{
public:
	// ������ 4�� ����
	bool Init();    // ���� �ʱ�ȭ
	int  Update();  // ���� ����
	void Show();    // ���� ���
	void Release(); // ���� ����
protected:
private:
	Player player_; // ���̸�
};

#endif