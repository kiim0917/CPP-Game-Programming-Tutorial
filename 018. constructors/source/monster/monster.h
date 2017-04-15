/*
 * monster.h
 *
 *       Copyright (c) Ruvendix. ��� ���۱��� ���ο��� �ֽ��ϴ�.
 *
 * �� ������ C++ ���� ���α׷��� Ʃ�丮���� ���� �����Դϴ�.
 * ��쿡 ���󼭴� C++11 �̻��� ���뵵 ���Ե� �� �ֽ��ϴ�.
 * ����� �� ������ ���� �ڵ� ���̵带 �����ϴ�.
 *
 * monster.h�� Monster Ŭ������ ����Ǿ��ִ� �����Դϴ�.
 * �ζ��� ���ĵ� ������ �ܺο��� �����ϴ� ���ĵ� �ֽ��ϴ�.
 */

// <������Ʈ �̸�>_<�ҽ� ������ ���>_<�ҽ� ������ �̸�>
#ifndef CONSTRUCTORS_MONSTER_MONSTER_H_
#define CONSTRUCTORS_MONSTER_MONSTER_H_

#include <string>

class Monster
{
public:
	// �⺻ ������ => ����Ʈ �����ڶ�� ��
	// �����ڴ� ��ü�� ������ �� �ڵ� ȣ��Ǵ� �Լ�
	Monster();
	
	// �����ڴ� �����ε��� ������!
	// �����ε��� �Լ��� �ĺ��ڰ� ���� ��
	// �Լ��� �Ű������� �Լ��� �����ϴ� ����� ����
	Monster(const std::string &name);

	void ShowName();
protected:

private:
	std::string name_;
};

#endif