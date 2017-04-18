/*
 * vector2.h
 *
 *       Copyright (c) Ruvendix. ��� ���۱��� ���ο��� �ֽ��ϴ�.
 *
 * �� ������ C++ ���� ���α׷��� Ʃ�丮���� ���� �����Դϴ�.
 * ��쿡 ���󼭴� C++11 �̻��� ���뵵 ���Ե� �� �ֽ��ϴ�.
 * ����� �� ������ ���� �ڵ� ���̵带 �����ϴ�.
 *
 * vector2.h�� Vector2 Ŭ������ ���� �� ���ǵǾ��ֽ��ϴ�.
 * �ζ��� �������� �Ǿ������Ƿ� �����Ͻñ� �ٶ��ϴ�.
 */

#ifndef ASCIIROGUELIKE_VECTOR2_H_
#define ASCIIROGUELIKE_VECTOR2_H_

// ��ǥ ������ 2�� ���� Ŭ����
class Vector2
{
public:
	Vector2() : x_(0), y_(0) { }
	Vector2(int x, int y) : x_(x), y_(y) { }

	// get �޼���
	int get_x() const { return x_; }
	int get_y() const { return y_; }

	// set �޼���
	void set_x(int x) { x_ = x; }
	void set_y(int y) { y_ = y; }

protected:
private:
	int x_; // x��ǥ(�� ����)
	int y_; // y��ǥ(�� ����)
};

#endif