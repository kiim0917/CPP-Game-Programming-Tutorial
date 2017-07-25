/*
 * ���� �̸� : stage.h
 * ���� ��¥ : 2017-07-25
 * ���� ��� : Ruvendix
 *
 * ���� ���� : ���������� ���� ������ ����Ǿ��ֽ��ϴ�.
 */

#ifndef PUREABSTRACT_STAGE_H_	
#define PUREABSTRACT_STAGE_H_

#include "../core/core.h"

namespace stage
{
	class StageBase : public core::CoreInterface
	{
	public:
		StageBase() = default;
		virtual ~StageBase()
		{
			Release();
		}		

		// ���� ���� �Լ���
		// ������ �������̵��ؾ� ��!
		// �� �׷��� ������ ������ �߻�!
		virtual int Init() override;

		// �Ϲ� ���� �Լ���
		// ������ �������̵��� �ʿ�� ����
		// �ʿ信 ���� �������̵��ϸ� ��
		virtual int Update() override;


	private:
		// �������̽��� public������
		// ��ü Ŭ���������� private���ε� ��� ����!
		virtual int Release() override;
	};
}

#endif