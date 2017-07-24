/*
 * ���� �̸� : main.cpp
 * ���� ��¥ : 2017-07-24
 * ���� ��� : Ruvendix
 *
 * ���� ���� : ����� �׽�Ʈ�մϴ�.
 */

#include <iostream>
#include <memory>

#include "monster/spider/spider.h"

#define PRESS_ENTER() printf("��� �����Ϸ��� ���͸� ��������.\n"); getchar();

int main()
{
	std::unique_ptr<monster::Spider> pSpider = std::make_unique<monster::Spider>("�Ź�");

	pSpider->Attack();
	pSpider->Move();
	pSpider->Climb();

	PRESS_ENTER();

	return 0;
}