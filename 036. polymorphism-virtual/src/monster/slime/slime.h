/*
 * ���� �̸� : monster.h
 * ���� ��¥ : 2017-07-24
 * ���� ��� : Ruvendix
 *
 * ���� ���� : ������ ������ ���� �� ���� �κ��Դϴ�.
 */

#ifndef INHERITANCE_MONSTER_SLIME_H_
#define INHERITANCE_MONSTER_SLIME_H_

#include "../monster.h"

namespace monster
{
	class Slime : public Monster
	{
	public:
		Slime() = default;
		using Monster::Monster;
		~Slime() = default;

		// Slime���� �޼���
		int Crawl()
		{
			printf("%s��(��) ���� �ִ�!\n", GetName().c_str());
			return 0;
		}

		// Slime�� �������̵�
		virtual int UpdateAction()
		{
			Attack();
			Crawl();
			return 0;
		}
	};
} // namespace monster end

#endif