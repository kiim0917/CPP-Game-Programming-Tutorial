/*
 * ���� �̸� : dialouge.h
 * ���� ��¥ : 2017-07-23
 * ���� ��� : Ruvendix
 *
 * ���� ���� : ��ȭ �ý����� ��� �����Դϴ�.
 */

#ifndef DIALOGUETREE_DIALOGUE_H_
#define DIALOGUETREE_DIALOGUE_H_

#include <string>
#include <vector>

#include "../common/macro.h"

namespace dialogue
{
	enum class DialougeFlag : int
	{
		SURVIVE,
		DIE,
		NEXT,
		END,
		NONE,
	};
} // namespace dialogue end

namespace dialogue
{
	class DialougeNode;
} // namespace dialogue end

namespace dialogue
{
	class DialogueOption
	{
	public:
		// �ٷ� �����ڿ��� ó���ص� ������
		// const_cast�� �����ϱ� ���� �Ϻη� �ٸ� �޼��带 �̿���!
		DialogueOption()  = default;
		~DialogueOption() = default;

		// �Ϲ������� �����ʹ� ���� ������ �� ���������
		// ���������� ����Ǹ� �ȵǴ� �����͸� �ѱ� ����
		// const �����͸� ����ؾ� ��!
		int Adjust(const std::string& strSubLine,
			DialougeFlag flag, const DialougeNode* pNextNode);

		const std::string& GetSubLine() const noexcept
		{
			return m_strSubLine;
		}

		DialougeFlag GetFlag() const noexcept
		{
			return m_flag;
		}

		const DialougeNode* GetNextNode() const noexcept
		{
			return m_pNextNode;
		}


	private:
		std::string  m_strSubLine;
		DialougeFlag m_flag;

		// ���� ��ȭ ��尡 �ʿ��ѵ�...
		// ��ȭ ���� �ؿ��� ���������Ƿ�
		// ���� ������ �ʿ���!
		// ���� ������ ������, �Ű��������� ��� ����
		DialougeNode* m_pNextNode;
	};

	class DialougeNode
	{
	public:
		DialougeNode() = default;
		~DialougeNode();

		int SetMainLine(const std::string& strMainLine)
		{
			m_strMainLine = strMainLine;
			return 0;
		}

		const std::string& GetMainLine() const noexcept
		{
			return m_strMainLine;
		}

		const std::vector<DialogueOption*>& GetVecDialogueOption() const noexcept
		{
			return m_vecOption;
		}

		int Insert(const std::string& strSubLine,
			DialougeFlag flag, const DialougeNode* pNextNode);


	private:
		std::string m_strMainLine;
		std::vector<DialogueOption*> m_vecOption;
	};

	class DialogueTree
	{
	public:
		DialogueTree() = default;
		~DialogueTree()
		{
			Release();
		}

		// �̷��� ���� ���� �� ���� �޼����
		// �������̽��� ���� ����� �װ� �̿��ϴ� �� �� ����!
		// ������ ����� �˾ƾ� �ϹǷ� ���⼭�� ����!
		int Init();
		int Excute();


	private:
		int Release();

		std::vector<DialougeNode*> m_vecNode;
	};
} // namespace dialogue end

#endif