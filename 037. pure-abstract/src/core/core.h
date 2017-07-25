/*
 * ���� �̸� : core.h
 * ���� ��¥ : 2017-07-25
 * ���� ��� : Ruvendix
 *
 * ���� ���� : ���� Ŭ�������� ����ϴ� ���� �޼��尡 ����Ǿ��ֽ��ϴ�.
 */

#ifndef PUREABSTRACT_CORE_H_	
#define PUREABSTRACT_CORE_H_

namespace core
{
	// �߻� Ŭ������ ����
	// �߻� Ŭ������ ��üȭ�� �� ���� Ŭ������ ����
	// ���� ���� �Լ��� �ϳ��� ������ �߻� Ŭ������ ����������
	// abstract ���� ����ϸ� ������ �߻� Ŭ������ ����
	// �߻� Ŭ�������� �����ڿ� �Ҹ��ڰ� ����������
	// new �Ǵ� �ܺο��� ��üȭ�ϴ� ���� �Ұ���
	class CoreInterface abstract
	{
	public:
		CoreInterface()          = default;
		virtual ~CoreInterface() = default;

		// ���� ���� �Լ�
		// ���� �� ���Ǵ� ����������
		// ���� Ŭ���������� ������ �������ؾ� ��!
		virtual int Init()    = 0;
		virtual int Release() = 0;

		// Update()�� �� �����Ӹ��� ȣ��Ǵ� �Լ��� ����
		// Unity���� �ƿ� Update() �Լ� ��ü�� ������
		virtual int Update() { return 0; }

		// �߻� Ŭ�������� ������ ���� ���� �Լ���
		// �����϶�� ���� ����. ���� ���� ���� �Լ���
		// �����ϵ��� �����ϸ� �������� ������
	};
} // namespace core end

#endif