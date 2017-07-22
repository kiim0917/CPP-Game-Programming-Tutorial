/*
 * ���� �̸� : main.cpp
 * ���� ��¥ : 2017-07-22
 * ���� ��� : Ruvendix
 *
 * ���� ���� : �� �޸𸮸� �ٷ�� new�� delete�� �׽�Ʈ�մϴ�.
 */

#include <cassert>
#include <iostream>

int PressEnter();

// rhs�� Right Hand Side�� ���ڷ� ������, �캯�� �ǹ�
int ReferValue(int& rhs);

int IndirectValue(int* pValue);

int main()
{
	//// �����ʹ� Pointer�� ���ڷ� p�� ǥ��
	//// ������ ���� ���� �����Ͷ�� �˷��ִ� ��
	//// �������� ���鿡�� ������ ����
	//int *pNum = new int;

	//// �����ʹ� �̷��� nullptr���� �˻� �ʼ�!
	//assert(pNum != nullptr);
	//if (pNum == nullptr) printf("���� �Ҵ翡 �����߽��ϴ�. ��� : pNum\n");

	//*pNum = 10;
	//printf("pNum�� �������� : %d\n", *pNum);

	//// �̷��Ը� ������ �޸� ����(Memory Leak)�� �߻���!
	//// �׻� new�� �ϸ� delete�� ���� ���ִ� �� ����!
	//
	//// delete pNum;

	////////////////////////////////////////////////////////////////////////////

	//// int�� 10���� �����ϴ� �迭
	//// ���ӵ� �޸𸮸� �Ҵ��Ϸ��� �ݵ��
	//// new[]���� �Ҵ��ؾ� ��!
	//int *pNumArray = new int[10];

	//assert(pNumArray != nullptr);
	//if (pNumArray == nullptr) printf("���� �Ҵ翡 �����߽��ϴ�. ��� : pNum\n");

	//for (int i = 0; i < 10; ++i)
	//{
	//	pNumArray[i] = i;
	//}

	//for (int i = 0; i < 10; ++i)
	//{
	//	printf("%d ", pNumArray[i]);
	//}
	//printf("\n");

	//// ���ӵ� �޸𸮸� �Ҵ��ϸ� �ݵ��
	//// delete[]���� �����ؾ� ��!
	//delete[] pNumArray;

	//////////////////////////////////////////////////////////////////////////

	//int* pNum = new int;

	//assert(pNum != nullptr);
	//if (pNum == nullptr) printf("���� �Ҵ翡 �����߽��ϴ�. ��� : pNum\n");

	//*pNum = 100;

	//// �����ڸ� �̿��� �� ����
	//printf("�����Ǳ� �� pNum�� �������� : %d\n", *pNum);
	//ReferValue(*pNum);
	//printf("������ �� pNum�� ��������   : %d\n\n", *pNum);

	//// �����͸� �̿��� �� ����
	//printf("�����Ǳ� �� pNum�� �������� : %d\n", *pNum);
	//IndirectValue(pNum);
	//printf("������ �� pNum�� ��������   : %d\n\n", *pNum);

	//delete pNum;

	//////////////////////////////////////////////////////////////////////////

	PressEnter();
		
	return 0;
}

int PressEnter()
{
	printf("��� �����Ϸ��� ���͸� ��������.\n");
	getchar();

	return 0;
}

int ReferValue(int& rhs)
{
	return rhs++;
}

int IndirectValue(int* pValue)
{
	(*pValue)++;
	return 0;
}