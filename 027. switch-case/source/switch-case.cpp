/*
 * switch-case.cpp
 *
 *       Copyright (c) Ruvendix. ��� ���۱��� ���ο��� �ֽ��ϴ�.
 *
 * �� ������ C++ ���� ���α׷��� Ʃ�丮���� ���� �����Դϴ�.
 * ��쿡 ���󼭴� C++11 �̻��� ���뵵 ���Ե� �� �ֽ��ϴ�.
 * ����� �� ������ ���� �ڵ� ���̵带 �����ϴ�.
 *
 * switch-case.cpp�� switch ~ case���� �˾ƺ��ϴ�.
 * if ~ else if�� ���� ����ؾ� �Ѵٸ� switch ~ case�� ����ϼ���.
 * switch ~ case�� ��� ���̺��̶�� ������� ��ü�� �� ������
 * ��� ���̺��� �� �����Ƿ� ���� switch ~ case�� �ͼ���������.
 * �������� �׳� if ~ else if�� ���� ����ϼŵ� �˴ϴ�.
 *
 * �� ��° ������ ���� ������ ��ü �浹 ��Ȳ�� �����غ� �̴ϴ�.
 * if ~ else if, switch ~ case, ��� ���̺� �̷��� 3���� �����帱�Կ�.
 */

 // ǥ�� ������� ���� C++�� ��� ����
 // using namespace std;�� �̿����� ����!
 // cstdio�� ���ԵǾ������Ƿ� C ��Ÿ���� ǥ�� ����µ� ��� ����!
#include <iostream>

// std::string�� ���� ��� ����
// string.h�� �ƴ϶� string��!
#include <string>

// std::vector�� ���� ��� ����
// �ݵ�� �� ��� ������ �����ؾ� ��!
#include <vector>

void TestIfStatement(const char player)
{
	// if���� ���������� ���ʴ�� �˻�
	if (player == '#')
	{
		printf("���� �ε������ϴ�!\n");
	}
	else if (player == 'S')
	{
		printf("���� �������ϴ�!\n");
	}
	else if (player == 'O')
	{
		printf("���ۿ� �������ϴ�!\n");
	}
	else if (player == 'T')
	{
		printf("������ �ε������ϴ�!\n");
	}
	else if (player == 'C' ||
		player == 'D')
	{
		printf("�����ڿ� �ε������ϴ�!\n");
	}
	else
	{
		printf("�ƹ��� �̻��� �����ϴ�!\n");
	}
}

void TestSwitchCaseStatement(const char player)
{
	const char kWall = '#';

	// switch ~ case�� break�� Ż��
	// case�� if���� �ٸ��� �߰� ������
	// �˻����� �ʰ� �ѹ��� �ǳʶ�
	// ���� break�� ������ ������
	// ���ǵ鵵 �˻��ϰ� ��
	// case�� label�̶� �ǳʶٴ� �� ����!
	// label�� ��ǥ���� ���� goto��
	switch (player)
	{
		// case���� ����� ����!
		// const�� ���̸� case���� ��� ����!
		// ��! ������� ������ �־�� ��!
	case kWall:
		printf("���� �ε������ϴ�!");
		break;
	case 'S':
		printf("���� �������ϴ�!");
		break;
	case 'O':
		printf("���ۿ� �������ϴ�!");
		break;
	case 'T':
		printf("������ �ε������ϴ�!");
		break;

		// case�� ��ġ��
		// �� �� ó����
	case 'C':
	case 'D':
		printf("�����ڿ� �ε������ϴ�!");
		break;

		// �⺻ ���
		// case�� �ϳ��� �ش���� ���� ���
	default:
		printf("�ƹ��� �̻��� �����ϴ�.");
		break;
	}
	printf("\n");
}

void TestLookupTable(const char player)
{
	std::vector<char> object_vec = { '#', 'S', 'O', 'T', 'C', 'D' };
	std::vector<std::string> guide_vec =
	{ "���� �ε������ϴ�!", "���� �������ϴ�!", "���ۿ� �������ϴ�!",
	 "������ �ε������ϴ�!", "�����ڿ� �ε������ϴ�!", "�����ڿ� �ε������ϴ�!" };

	// ��ü �迭�� ó������ �˻�
	// ���� ��� ���̺��� ����� �̿��ϱ� ������
	// �˻� �ܰ踦 ��ġ���� ������,
	// �� ���� char�� �Ǵ��ؾ� �ϹǷ� �˻簡 �ʿ���!
	for (int i = 0; i < static_cast<int>(object_vec.size()); ++i)
	{
		// ��ü �迭�� ��ҿ� ĳ���Ͱ� ��ġ�Ѵٸ�
		if (object_vec[i] == player)
		{
			// string�� %s�� �̿��Ϸ���
			// c_str() �Ǵ� data()�� ����ؾ� ��!
			printf("%s\n", guide_vec[i].c_str());
			return;
		}
	}

	// ��ü �迭�� ��ҿ� ĳ���Ͱ� ��ġ���� �ʴ´ٸ�
	printf("�ƹ��� �̻��� �����ϴ�.\n");

	object_vec.clear();
	guide_vec.clear();
}

// ���α׷��� ������
// ��, ���α׷��� ���۵Ǵ� �κ�!
int main()
{
	system("title switch ~ case�� �����ϱ�");

	// �ҽ� �ڵ带 ���̱� ���� ��� ���̺� �̿�
	std::vector<char> test_vec = { '#', 'S', 'O', 'T', 'C', 'D', '&', '*' };

	//if ~else if�� ó��
	for (int i = 0; i < static_cast<int>(test_vec.size()); ++i)
	{
		TestIfStatement(test_vec[i]);
	}

	//// switch ~ case�� ó��
	//for (int i = 0; i < static_cast<int>(test_vec.size()); ++i)
	//{
	//	TestSwitchCaseStatement(test_vec[i]);
	//}

	//// ��� ���̺�� ó��
	//for (int i = 0; i < static_cast<int>(test_vec.size()); ++i)
	//{
	//	TestLookupTable(test_vec[i]);
	//}

	test_vec.clear();

	// �ڵ� ���� ����!
	system("pause");

	// ���α׷��� ���������� ����ȴٴ� ���� �ǹ�
	// exit(EXIT_SUCCESS); �̰Ͱ� �����!
	return 0;
}