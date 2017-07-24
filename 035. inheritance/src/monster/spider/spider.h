/*
 * ���� �̸� : monster.h
 * ���� ��¥ : 2017-07-24
 * ���� ��� : Ruvendix
 *
 * ���� ���� : �Ź� ������ ���� �� ���� �κ��Դϴ�.
 */

#ifndef INHERITANCE_MONSTER_SPIDER_H_
#define INHERITANCE_MONSTER_SPIDER_H_

#include "../monster.h"

namespace monster
{
	class Spider : public Monster
	{
	public:
		Spider() = default;

		// ������ ���
		// �θ� �����ڰ� �ڽ� �����ڸ� ��� ó������!
		using Monster::Monster;

		~Spider() = default;

		// Spider���� �޼���
		int Climb()
		{
			printf("%s�� �������� �ִ�!\n", GetName().c_str());
			return 0;
		}
	};
} // namespace monster end

#endif