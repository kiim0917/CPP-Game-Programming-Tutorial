/*
 * unit.cpp
 *
 *       Copyright (c) Ruvendix. ��� ���۱��� ���ο��� �ֽ��ϴ�.
 *
 * �� ������ C++ ���� ���α׷��� Ʃ�丮���� ���� �����Դϴ�.
 * ��쿡 ���󼭴� C++11 �̻��� ���뵵 ���Ե� �� �ֽ��ϴ�.
 * ����� �� ������ ���� �ڵ� ���̵带 �����ϴ�.
 *
 * unit.cpp�� Unit Ŭ������ ���ǵǾ��ֽ��ϴ�.
 * ���̸ӿ� ���� ���� �κ��� � �͵����� �� ������.
 */

// ���� ���� ��� ������ include ������ ����
#include "../../include/unit.h"

#include <iostream>

void Unit::ShowUnitInfo()
{
	printf("��ü ��� : %c\n", shape_);
	printf("��ü ��ġ : (%d, %d)\n", pos_.get_x(), pos_.get_y());
	printf("�����    : %-4d\n", life_);
	printf("���ݷ�    : %-4d\n", atk_);
	printf("����    : %-4d\n", def_);
	printf("����ġ    : %-4d\n", exp_);
}