/*
 * while-for.cpp
 *
 *       Copyright (c) Ruvendix. ��� ���۱��� ���ο��� �ֽ��ϴ�.
 *
 * �� ������ C++ ���� ���α׷��� Ʃ�丮���� ���� �����Դϴ�.
 * ��쿡 ���󼭴� C++11 �̻��� ���뵵 ���Ե� �� �ֽ��ϴ�.
 * ����� �� ������ ���� �ڵ� ���̵带 �����ϴ�.
 *
 * while-for.cpp�� while���� for���� �ٷ�ϴ�.
 * �� �� ���� ���ǹǷ� �� �˾Ƶμ���.
 * 
 */

// std::cout�� ����� �����ִ� ��� ����
#include <iomanip>

// ǥ�� ������� ���� C++�� ��� ����
// using namespace std;�� �̿����� ����!
#include <iostream>

// std::string�� ���� ��� ����
// string.h�� �ƴ϶� string��!
#include <string>

// ���α׷��� ������
// ��, ���α׷��� ���۵Ǵ� �κ�!
int main()
{
	int i = 0; // �ݺ��ڴ� �ַ� i, j, k

	// ���ǽ��� ���� ���� �ݺ�!
	while (i < 10)
	{
		std::cout << std::setw(2) << std::setfill('0') << i + 1 << "��° �ݺ�\n";
		i++; // i = i + 1 �Ǵ� i += 1�� ����
	}
	std::cout << std::endl;

	// for���� �ʱ갪�� �������� ���ÿ� �� �� ����!
	// C++������ �ݺ��ڸ� ���ο��� �����ϴ� ��찡 ����!
	for (int j = 0; j < 10; ++j)
	{
		std::cout << std::setw(2) << std::setfill('0') << j + 1 << "��° �ݺ�\n";
	}
	std::cout << std::endl;

	// do ~ while���� ���ǽĿ� ������� ������ 1�� ����!
	int k = 12;
	do 
	{
		std::cout << std::setw(2) << std::setfill('0') << k - 11 << "��° �ݺ�\n";
	} while (k < 10);
	std::cout << std::endl;

	// ���� �ݺ���!
	// ���ǽ��� ������ ��!
	// while (true)�� ������ true�� ��� ������
	// for (; ;)�� �� ��ü�� ���� �ݺ����� ����
	// �׷��� for(; ;)�� ���� ��찡 ����!
	// �Ʒ��� �ִ� �ڵ带 ������ ���� ����!
	//while (true) std::cout << "��";
	//for (; ; ) std::cout << "��";
	
	// �ڵ� ���� ����!
	system("pause");

	// ���α׷��� ���������� ����ȴٴ� ���� �ǹ�
	// exit(EXIT_SUCCESS); �̰Ͱ� �����!
	return 0;
}