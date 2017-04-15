/*
 * array-const.cpp
 *
 *       Copyright (c) Ruvendix. ��� ���۱��� ���ο��� �ֽ��ϴ�.
 *
 * �� ������ C++ ���� ���α׷��� Ʃ�丮���� ���� �����Դϴ�.
 * ��쿡 ���󼭴� C++11 �̻��� ���뵵 ���Ե� �� �ֽ��ϴ�.
 * ����� �� ������ ���� �ڵ� ���̵带 �����ϴ�.
 *
 * array-const.cpp�� �迭�� ����� ���� �˾ƺ��ϴ�.
 * �迭�� ���ӵ� �޸� �������μ�, ������ ���� �� ����ٰ� �����Ͻø� �˴ϴ�.
 * �迭�� ������ 5���� ���ϸ� �迭�� ÷�ڴ� 0, 1, 2, 3, 4�� �˴ϴ�.
 * �迭�� ������ ������ �����Ϸ��� const�� �̿��ؾ� �մϴ�.
 */

// ǥ�� ������� ���� C++�� ��� ����
// using namespace std;�� �̿����� ����!
#include <iostream>

// std::string�� ���� ��� ����
// string.h�� �ƴ϶� string��!
#include <string>

// �Լ��� ���� ���� ����
void TestNumList();
void UseConst();
void IntoShop();
void ShowItemList(std::string item_list[], int count);

// ���α׷��� ������
// ��, ���α׷��� ���۵Ǵ� �κ�!
int main()
{
	system("title ���� �����");

	//TestNumList();
	//UseConst();

	IntoShop();

	// �ڵ� ���� ����!
	system("pause");

	// ���α׷��� ���������� ����ȴٴ� ���� �ǹ�
	// exit(EXIT_SUCCESS); �̰Ͱ� �����!
	return 0;
}

void IntoShop()
{
	const int item_count = 5;
	static std::string item_list[item_count] = {"��", "����", "��ź", "ȸ����", "�ָԹ�"};

	std::cout << "����~ �츮 ���Կ� �� �Դ�~\n";
	std::cout << "�ʿ��� �� ������ �ѹ� ��󺸶��!\n\n";
	ShowItemList(item_list, item_count);
}

void ShowItemList(std::string item_list[], int count)
{
	std::cout << "----------- ��ǰ ��� -----------\n";
	for (int i = 0; i < count; ++i)
	{
		std::cout << "" <<item_list[i] << std::endl;
	}
	std::cout << "---------------------------------\n";
}

void TestNumList()
{
	// �迭�� ũ��� 5! ÷���� ������ �ǹ�!
	// �迭�� ÷�ڴ� 0���� ����!
	// ������ 0�� �ƴϰ� 1���� �����ϴ� �� ����!
	int num_list[5] = {0, 1, 2, 3, 4};

	for (int i = 0; i < 5; ++i)
	{
		std::cout << "num_list[" << i << "] : " << num_list[i] << std::endl;
	}
}

void UseConst()
{
	// �迭�� ũ��� ������ ������ �� ����!
	// ������ ����� �����ϹǷ� const�� �̿��ؾ� ��!
	// C������ C11 �̻���� ����!
	const int count = 5;
	int num_list[count] = {0, 1, 2, 3, 4};

	for (int i = 0; i < count; ++i)
	{
		std::cout << "num_list[" << i << "] : " << num_list[i] << std::endl;
	}
}