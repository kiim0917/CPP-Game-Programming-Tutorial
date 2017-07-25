/*
 * ���� �̸� : main.cpp
 * ���� ��¥ : 2017-07-25
 * ���� ��� : Ruvendix
 *
 * ���� ���� : IOManger�� ���� �κ��Դϴ�.
 */

#ifndef STATIC_IOMANGER_H_
#define STATIC_IOMANGER_H_

#include <cassert>
#include <iostream>
#include <string>

namespace mgr
{
	class IOManager
	{
	public:
		IOManager()  = default;
		~IOManager() = default;

		// ���� ��ü�� �����ϴ� �޼��尡 �ʿ��ϴٸ�
		// static���� �����ϸ� ��!
		static int AppendStringToFile(const std::string& strFileName,
			const std::string& strText);

		// static �ʵ带 ������ ���� static �޼��带 ���ؼ� �������� �� ����!
		// �Ϲ� �޼���ε� �����ϱ� ������ static�� �ǹ̰� ����
		static const std::string& GetLastFileName() noexcept
		{
			return m_strLastFileName;
		}

		// ���� ��ü�� �����ϴ� �ʵ尡 �ʿ��ϴٸ�
		// static���� �����ϸ� ��!
		// �ٸ� static �ʵ�� �ʱ�ȭ�� �����ؾ� ��!
		static std::string m_strLastFileName;
	};
} // namespace mgr end

#endif