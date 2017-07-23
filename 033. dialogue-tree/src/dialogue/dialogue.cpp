/*
 * ���� �̸� : dialouge.cpp
 * ���� ��¥ : 2017-07-23
 * ���� ��� : Ruvendix
 *
 * ���� ���� : ��ȭ �ý����� ���� �����Դϴ�.
 */

#include "dialogue.h"

#include <cassert>
#include <iostream>

const int MAX_NODE = 6;

namespace dialogue
{
	int DialogueOption::Adjust(const std::string& strSubLine,
		DialougeFlag flag, const DialougeNode* pNextNode)
	{
		m_strSubLine = strSubLine;
		m_flag = flag;

		// const �����ͷ� ���� �����ڸ� ����ϰ� ������
		// const_cast�� �̿��ؼ� const ����� ���� ��!
		// ���ڴ� const �����ͷ� �Ѿ�����Ƿ� �Լ� ���ο�����
		// �������� �̿��ؼ� ���� ������ �� ����!
		m_pNextNode = const_cast<DialougeNode*>(pNextNode);

		return 0;
	}

	DialougeNode::~DialougeNode()
	{
		for (size_t i = 0; i < m_vecOption.size(); ++i)
		{
			SAFE_DELETE(m_vecOption[i]);
		}
	}

	int DialougeNode::Insert(const std::string& strSubLine,
		DialougeFlag flag, const DialougeNode* pNextNode)
	{
		// pNextNode�� nullptr�� ��쵵 ����ϹǷ�
		// �� ��쿡�� assert()�� ����ϸ� �ȵ�!
		//assert(pNextNode != nullptr);

		DialogueOption* pDialogueOption = nullptr;

		pDialogueOption = new DialogueOption;
		assert(pDialogueOption != nullptr);

		pDialogueOption->Adjust(strSubLine, flag, pNextNode);
		m_vecOption.push_back(pDialogueOption);

		return 0;
	}

	int DialogueTree::Init()
	{
		DialougeNode* pNodeTable[MAX_NODE];

		for (int i = 0; i < MAX_NODE; ++i)
		{
			pNodeTable[i] = new DialougeNode;
			assert(pNodeTable[i] != nullptr);
		}

		// ù ��° ��ȭ
		pNodeTable[0]->SetMainLine("�ȳ�~ ���� ��ħ~");

		pNodeTable[0]->Insert("�ȳ� ����", DialougeFlag::NEXT, pNodeTable[1]);
		pNodeTable[0]->Insert("��~ �ʵ�~", DialougeFlag::NEXT, pNodeTable[2]);
					 
		m_vecNode.push_back(pNodeTable[0]);

		//////////////////////////////////////////////////////////////////////////

		// �� ��° ��ȭ
		pNodeTable[1]->SetMainLine("���� �̸� ������!");

		pNodeTable[1]->Insert("��¼���!", DialougeFlag::END, nullptr);
		
		m_vecNode.push_back(pNodeTable[1]);
		
		//////////////////////////////////////////////////////////////////////////

		// �� ��° ��ȭ
		pNodeTable[2]->SetMainLine("��... ������ ��Ź�� �� �ִµ�...");
					 
		pNodeTable[2]->Insert("�� ���غ�~", DialougeFlag::NEXT, pNodeTable[4]);
		pNodeTable[2]->Insert("�� �ָ� ��Ź �����", DialougeFlag::NEXT, pNodeTable[3]);
		
		m_vecNode.push_back(pNodeTable[2]);
		
		//////////////////////////////////////////////////////////////////////////

		// �� ��° ��ȭ
		pNodeTable[3]->SetMainLine("�̰� ���� ���Ƴ�! �׳� �׾�!");
					 
		pNodeTable[3]->Insert("���ƾƾƾ�~!", DialougeFlag::DIE, nullptr);

		m_vecNode.push_back(pNodeTable[3]);

		//////////////////////////////////////////////////////////////////////////

		// �ټ� ��° ��ȭ
		pNodeTable[4]->SetMainLine("�̵���~ ���� ���� ���� ����~!");
					 
		pNodeTable[4]->Insert("�� ���� ���� �ǵ�?", DialougeFlag::END, nullptr);
		pNodeTable[4]->Insert("�� ����~", DialougeFlag::NEXT, pNodeTable[5]);
		pNodeTable[4]->Insert("���� ���Ƴ�! �� �ʶ� ���� �Ծ�� �ϴµ�?!", DialougeFlag::END, nullptr);

		m_vecNode.push_back(pNodeTable[4]);

		//////////////////////////////////////////////////////////////////////////

		// ���� ��° ��ȭ
		pNodeTable[5]->SetMainLine("���� �׷��� �̵� ��~");

		pNodeTable[5]->Insert("�� �׷�~", DialougeFlag::SURVIVE, nullptr);

		m_vecNode.push_back(pNodeTable[5]);

		return 0;
	}

	int DialogueTree::Excute()
	{
		DialougeNode* pNode = m_vecNode[0];

		// ������ �Է°��� �̿��ϱ� ����
		// while�� �ۿ��� ����
		size_t select = 0;

		while (true)
		{
			printf("�̿� : %s\n", pNode->GetMainLine().c_str());

			std::vector<DialogueOption*> vecOption = pNode->GetVecDialogueOption();

			int size = vecOption.size();

			if (size != 1)
			{
				for (size_t i = 0; i < size; ++i)
				{
					printf("%d. %s\n", i + 1, vecOption[i]->GetSubLine().c_str());
				}
			}
			else
			{
				printf("%s\n", vecOption[0]->GetSubLine().c_str());
			}
			printf("\n");

			// select���� �̹� ���� ��ȭ�� �����߱� ������
			// ���� ��ȭ�� �Ǵ��� ���� vecOption[0]�� �� 
			// ���� ��ȭ�� �������� �����Ƿ� �������� �ϳ����� Ȯ���ؾ� ��
			if ((vecOption.size() == 1) && (vecOption[0]->GetNextNode() == nullptr))
			{
				// enum class�� static_cast<int>�� ��ȯ�ؼ� ���!
				return static_cast<int>(vecOption[0]->GetFlag());
			}

			// �б� ���� �κ�
			// �Է��ϸ� �׶��� �÷��׸� �˻�
			printf(">> ");
			scanf("%d", &select);
			getchar(); // ���� ���� ����

			bool bVaild = true;
			if (select <= 0 || select > vecOption.size()) bVaild = false;
			assert(bVaild != false); // assert�� ���� �κ��� ���ؾ� ��!
			if (bVaild == false)
			{
				printf("�Է� ������ ������ϴ�!\n\n");
				select = 0;
				continue;
			}

			// if�� ��ġ�� ������ return�ǹǷ� �� ��쿡�� else�� �� �ᵵ ��
			pNode = const_cast<DialougeNode*>(vecOption[select - 1]->GetNextNode());

			// ���� ��ȭ ��ü�� nullptr�̸� �ش�Ǵ� �÷��׸� ��ȯ
			if (pNode == nullptr)
			{
				// enum class�� static_cast<int>�� ��ȯ�ؼ� ���!
				return static_cast<int>(vecOption[select - 1]->GetFlag());
			}
		}

		return 0;
	}

	int DialogueTree::Release()
	{
		for (size_t i = 0; i < m_vecNode.size(); ++i)
		{
			SAFE_DELETE(m_vecNode[i]);
		}

		return 0;
	}

} // namespace dialogue end