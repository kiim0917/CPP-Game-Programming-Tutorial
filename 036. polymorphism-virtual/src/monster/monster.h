/*
 * ���� �̸� : monster.h
 * ���� ��¥ : 2017-07-24
 * ���� ��� : Ruvendix
 *
 * ���� ���� : ������ ���� �� ���� �κ��Դϴ�.
 */

#ifndef INHERITANCE_MONSTER_H_
#define INHERITANCE_MONSTER_H_

#include <string>

namespace monster
{
	class Monster
	{
	public:
		Monster() = default;

		explicit Monster(const std::string& strName)
		{
			m_strName = strName;
		}

		~Monster() = default;

		const std::string& GetName() const noexcept
		{
			return m_strName;
		}

		void SetName(const std::string& strName)
		{
			m_strName = strName;
		}

		int Attack()
		{
			printf("%s��(��) �����ߴ�!\n", m_strName.c_str());
			return 0;
		}

		int Move()
		{
			printf("%s��(��) �̵��ߴ�!\n", m_strName.c_str());
			return 0;
		}

		// ���� Ŭ������ �⺻ �޼���
		virtual int UpdateAction()
		{
			Attack();
			Move();
			return 0;
		}


	private:
		// private�� ���� Ŭ������ ���� �Ұ�
		std::string m_strName;
	};
} // namespace monster end

#endif