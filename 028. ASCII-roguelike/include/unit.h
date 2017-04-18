/*
 * unit.h
 *
 *       Copyright (c) Ruvendix. ��� ���۱��� ���ο��� �ֽ��ϴ�.
 *
 * �� ������ C++ ���� ���α׷��� Ʃ�丮���� ���� �����Դϴ�.
 * ��쿡 ���󼭴� C++11 �̻��� ���뵵 ���Ե� �� �ֽ��ϴ�.
 * ����� �� ������ ���� �ڵ� ���̵带 �����ϴ�.
 *
 * unit.h�� Unit Ŭ������ ����Ǿ��ֽ��ϴ�.
 * �ζ��� ���ĵ� �����Ƿ� �����Ͻñ� �ٶ��ϴ�.
 * Unit Ŭ������ ���̸ӿ� ������ ���� �κ��� ���ԵǾ��ֽ��ϴ�.
 * ������ ����� �̿��ؾ� ������ ���⼭�� ���Ե� ������� �����մϴ�.
 */

#ifndef ASCIIROGUELIKE_UNIT_H_
#define ASCIIROGUELIKE_UNIT_H_

 // ���� ���� ��� ���ϳ����� ��ġ ����
#include "vector2.h"

// ���̸ӿ� ������ ���� �κ��� ������ Ŭ����
class Unit
{
public:
	Unit() : pos_(0, 0), life_(0), atk_(0), def_(0), exp_(0), shape_('0') { }
	Unit(int x, int y, int life, int atk, int def, int exp, char shape)
		: pos_(x, y), life_(life), atk_(atk), def_(def),
		  exp_(exp), shape_(shape) { }

	// ���� ���� ���
	void ShowUnitInfo();

	// get �޼���
	Vector2 get_pos() const { return pos_; }
	int get_life() const { return life_; }
	int get_atk() const { return atk_; }
	int get_def() const { return def_; }
	int get_exp() const { return exp_; }
	char get_shape() const { return shape_; }

	// set �޼���
	void set_pos(int x, int y) { pos_.set_x(x); pos_.set_y(y); }
	void set_pos(Vector2 &pos) { pos_ = pos; }
	void set_life(int life) { life_ = life; }
	void set_atk(int atk)  { atk_ = atk; }
	void set_def(int def) { def_ = def; }
	void set_exp(int exp) { exp_ = exp; }
	void set_shape(char shape) { shape_ = shape; }
protected:
private:
	Vector2 pos_; // ��ǥ
	int life_;    // �����
	int atk_;     // ���ݷ�(attack)
	int def_;     // ����(defense)
	int exp_;     // ����ġ(experience)
	char shape_;  // ���
};

#endif