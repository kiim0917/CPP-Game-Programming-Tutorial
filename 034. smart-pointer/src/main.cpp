/*
 * ���� �̸� : main.cpp
 * ���� ��¥ : 2017-07-24
 * ���� ��� : Ruvendix
 *
 * ���� ���� : ����Ʈ �����͸� �׽�Ʈ�մϴ�.
 */

#include <cassert>
#include <iostream>
#include <memory>

#define PRESS_ENTER() printf("��� �����Ϸ��� ���͸� ��������.\n"); getchar();

class Data
{
public:
	Data() = default;
	explicit Data(int num)
	{
		m_num = num;
	}
	~Data() = default;

	int GetNum() const noexcept
	{
		return m_num;
	}


private:
	int m_num;
};

int main()
{
	//// share_ptr
	//// �������� �����ϴ� ����Ʈ ������
	//// �������� �����Ҽ��� ���۷��� ī��Ʈ�� ������
	//std::shared_ptr<Data> pOldData = std::make_shared<Data>(100);
	//assert(pOldData);

	//// �Ϲ� �����Ϳ� �����ϴ� ��쿡�� get() �޼��� �̿�
	//Data* pOriginal = pOldData.get();
	//assert(pOriginal);

	//// ����Ʈ �����Ϳ��� �׳� ���� ����
	//// ���簡 �߻��ϸ� ���۷��� ī��Ʈ ����
	//std::shared_ptr<Data> pNewData = pOldData;
	//assert(pNewData);

	//printf(" pOldData�� �������� : %d\n", pOldData->GetNum());
	//printf("pOriginal�� �������� : %d\n", pOriginal->GetNum());
	//printf(" pNewData�� �������� : %d\n\n", pNewData->GetNum());

	//////////////////////////////////////////////////////////////////////////

	//// unique_ptr
	//// �������� �������� �ʴ� ����Ʈ ������
	//// ������ �絵�� ����
	//std::unique_ptr<Data> pUniqueData = std::make_unique<Data>(200);
	//assert(pUniqueData);

	//// �Ϲ� �����Ϳ� �����ϴ� ��쿡�� get() �޼��� �̿�
	//// ������ ������ �ƴ϶� ���� �����͸� �������� ���
	//Data* pOriginal = pUniqueData.get();
	//assert(pOriginal);

	//// ������ ������ �Ұ���
	////std::unique_ptr<Data> pNewUniqueData = pUniqueData;

	//// ������ �絵�� ����
	//std::unique_ptr<Data> pNewUniqueData = std::move(pUniqueData);
	//assert(pNewUniqueData);

	//// �������� �絵�ϸ� pUniqueData�� �� �̻� ���� ����
	////printf(" pOldData�� �������� : %d\n", pUniqueData->GetNum());
	//
	//printf("     pOriginal�� �������� : %d\n", pOriginal->GetNum());
	//printf("pNewUniqueData�� �������� : %d\n\n", pNewUniqueData->GetNum());

	// std::unique_ptr�� ����ϴ� ����
	// ������ �˻� ������ �����ڿ� �Ҹ��ڿ��� ������
	// ���� ���� ����... �׶��� �����ڿ� �Ҹ�����
	// ���� �κа� ���� �κ��� �и��ؼ� �����ؾ� ��!
	
	PRESS_ENTER();

	return 0;
}