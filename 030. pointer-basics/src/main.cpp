/*
* ���� �̸� : main.cpp
* ���� ��¥ : 2017-07-19
* ���� ��� : Ruvendix
*
* ���� ���� : ������ ���� ������ �׽�Ʈ�մϴ�.
*/

#include <cassert>
#include <iostream>

int AddOne(int* pNum);

int main()
{
	//// ������ �ּ�
	//int intNum;
	//std::cout << "intNum�� �ּ�   : " << &intNum << std::endl; // 16����
	//std::cout << "intNum�� �ּ�   : " << reinterpret_cast<int>(&intNum)
	//	<< std::endl << std::endl; // 10����

	//float floatNum;
	//std::cout << "floatNum�� �ּ� : " << &intNum << std::endl; // 16����
	//std::cout << "floatNum�� �ּ� : " << reinterpret_cast<int>(&floatNum)
	//	<< std::endl << std::endl; // 10����

	////////////////////////////////////////////////////////////////////////////

	//// nullptr => �ּҰ� 0x00000000�� ������
	//char* pChar = nullptr;
	////std::cout << pChar << std::endl; // 16���� => ��� �Ұ�
	//std::cout << reinterpret_cast<int*>(pChar) << std::endl << std::endl; // 10����	

	////////////////////////////////////////////////////////////////////////////

	//// �����Ϳ� ���� �ּ� �ֱ�
	//int  num = 10;
	//int* pNum = &num;

	//std::cout << "num�� ��   : " <<  num << " " << *pNum << std::endl;
	//std::cout << "num�� �ּ� : " << &num << " " <<  pNum << std::endl << std::endl;

	////////////////////////////////////////////////////////////////////////////

	//// ������ �����ڿ� nullptr
	//char* pData = nullptr;
	//int result;

	////result = *pData; // ���� �߻�!

	////assert(pData != nullptr); // nullptr�� �Ǻ��� �� ���� Debug ��� ���� ��ũ�� �Լ�

	//if (pData != nullptr)
	//{
	//	result = *pData;
	//}

	////////////////////////////////////////////////////////////////////////////

	//int upNum = 5;

	//for (int i = 0; i < 10; ++i)
	//{
	//	AddOne(&upNum); // upNum�� �ּҰ� pNum�� ����! �̰� ���� �߿�!
	//	std::cout << upNum << " ";
	//}
	//std::cout << std::endl;

	return 0;
}

int AddOne(int* pNum)
{
	(*pNum)++; // *pNum���� �ϰ� ++ ����
	return 0;
}