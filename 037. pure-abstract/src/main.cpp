/*
 * ���� �̸� : main.cpp
 * ���� ��¥ : 2017-07-25
 * ���� ��� : Ruvendix
 *
 * ���� ���� : ���� ���� �Լ��� �׽�Ʈ�մϴ�.
 */

#define PRESS_ENTER() printf("��� �����Ϸ��� ���͸� ��������.\n"); getchar();

#include <memory>

#include "stage/stage.h"

int main()
{
	std::unique_ptr<stage::StageBase> pStageBase =
		std::make_unique<stage::StageBase>();

	pStageBase->Init();

	for (int i = 0; i < 4; ++i)
	{
		pStageBase->Update();
	}

	// Release()�� StageBase����
	// private�̹Ƿ� �ܺο��� ���� �Ұ�!
	// pStageBase->Release();

	PRESS_ENTER();

	return 0;
}