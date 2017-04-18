/*
 * player.h
 *
 *       Copyright (c) Ruvendix. ��� ���۱��� ���ο��� �ֽ��ϴ�.
 *
 * �� ������ C++ ���� ���α׷��� Ʃ�丮���� ���� �����Դϴ�.
 * ��쿡 ���󼭴� C++11 �̻��� ���뵵 ���Ե� �� �ֽ��ϴ�.
 * ����� �� ������ ���� �ڵ� ���̵带 �����ϴ�.
 *
 * player.h�� Player Ŭ������ ����Ǿ��ֽ��ϴ�.
 * �ζ��� ���ĵ� �����Ƿ� �����Ͻñ� �ٶ��ϴ�.
 * Player Ŭ������ ���̸��� �Է�, �̵� ó�� ���� ���ԵǾ��ֽ��ϴ�.
 * Player Ŭ������ Unit Ŭ������ ���� �ֽ��ϴ�.
 */

#ifndef ASCIIROGUELIKE_PLAYER_H_
#define ASCIIROGUELIKE_PLAYER_H_

 // ���� ���� ��� ������ include ������ ����
#include "unit.h"

class Player
{
public:
	Player() : info_(0, 0, 0, 0, 0, 0, '0') { }
	Player(int x, int y, int life, int atk, int def, int exp, char shape)
		: info_(x, y, life, atk, def, exp, shape) { }

	// get �޼���
	Unit get_info() const { return info_; }

protected:
private:
	Unit info_;
};

#endif