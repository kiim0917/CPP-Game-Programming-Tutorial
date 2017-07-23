/*
 * ���� �̸� : main.cpp
 * ���� ��¥ : 2017-07-23
 * ���� ��� : Ruvendix
 *
 * ���� ���� : ��ȭ �ý����� �׽�Ʈ�մϴ�.
 */

#include <iostream>

#include "common/macro.h"
#include "dialogue/dialogue.h"

int main()
{
	dialogue::DialogueTree* tree = new dialogue::DialogueTree;

	tree->Init();

	int resultFlagAdapter = tree->Excute();
	dialogue::DialougeFlag resultFlag = static_cast<dialogue::DialougeFlag>(resultFlagAdapter);

	// �÷����� ���¿� ���� ���
	switch (resultFlag)
	{
	case dialogue::DialougeFlag::END:
		printf("������ �������ϴ�.\n");
		break;
	case dialogue::DialougeFlag::DIE:
		printf("����� �׾����ϴ�...\n");
		break;
	case dialogue::DialougeFlag::SURVIVE:
		printf("����� ��ҽ��ϴ�!\n");
		break;
	}

	SAFE_DELETE(tree);

	PRESS_ENTER();

	return 0;
}