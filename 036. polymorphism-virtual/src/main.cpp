/*
 * ���� �̸� : main.cpp
 * ���� ��¥ : 2017-07-24
 * ���� ��� : Ruvendix
 *
 * ���� ���� : ����� �׽�Ʈ�մϴ�.
 */

#include <cassert>
#include <iostream>
#include <memory>
#include <vector>

#include "monster/spider/spider.h"
#include "monster/slime/slime.h"

#define PRESS_ENTER() printf("��� �����Ϸ��� ���͸� ��������.\n"); getchar();

int main()
{
	// ���� Ŭ������ �����͸� �����Ѵٰ� ����
	// STL�� ����Ʈ �����͸� ����� ���� shard_ptr�� ����!
	// unique_ptr�� ����ϸ� ������ ���� ������ ���� ���� ����...
	std::vector<std::shared_ptr<monster::Monster>> vecMonster;

	vecMonster.push_back(std::make_shared<monster::Spider>("�Ź�"));
	vecMonster.push_back(std::make_shared<monster::Spider>("������"));

	while (true)
	{
		// Range Based For��
		for (std::shared_ptr<monster::Monster> i : vecMonster)
		{
			assert(i != nullptr);
			i->UpdateAction();
		}

		PRESS_ENTER();
	}

	return 0;
}