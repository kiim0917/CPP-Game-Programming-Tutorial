/*
 * ���� �̸� : stage.cpp
 * ���� ��¥ : 2017-07-25
 * ���� ��� : Ruvendix
 *
 * ���� ���� : ���������� ���� ������ ���ǵǾ��ֽ��ϴ�.
 */

#include "stage.h"

#include <iostream>

namespace stage
{
	int StageBase::Init()
	{
		printf("�������� �ʱ�ȭ!\n");
		return 0;
	}

	int StageBase::Update()
	{
		printf("�������� ���� ����!\n");
		return 0;
	}

	int StageBase::Release()
	{
		printf("�������� �Ҹ�!\n");
		return 0;
	}
}