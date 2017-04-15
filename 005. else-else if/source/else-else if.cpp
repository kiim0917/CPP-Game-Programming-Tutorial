/*
 * else-else if.cpp
 *
 *       Copyright (c) Ruvendix. ��� ���۱��� ���ο��� �ֽ��ϴ�.
 *
 * �� ������ C++ ���� ���α׷��� Ʃ�丮���� ���� �����Դϴ�.
 * ��쿡 ���󼭴� C++11 �̻��� ���뵵 ���Ե� �� �ֽ��ϴ�.
 * ����� �� ������ ���� �ڵ� ���̵带 �����ϴ�.
 *
 * else-else if.cpp�� else�� else if���� �ٷ�ϴ�.
 * if�� ������ ���弱�̹Ƿ� ������ �˾ƺ��ڽ��ϴ�.
 * 
 */

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
	std::string player_name;
	int player_age;

	std::cout << "��� ���� �̸��� ��� �ǽó���? ";
	std::cin >> player_name;

	std::cout << "�ȳ��ϼ���, \"" << player_name << "\" ��� ��\n\n";
	std::cout << "��� ���� ���̴� ��� �ǽó���? ";
	std::cin >> player_age;

	if (player_age <= 0)
	{
		std::cout << "���̰� 0�� ���϶���...?\n";
	}
	else if (player_age <= 7)
	{
		std::cout << "���̰� ��ñ���...\n";
	}
	else if (player_age >= 100)
	{
		std::cout << "���̰� �����ñ���...\n";
	}
	else
	{
		std::cout << "\"" << player_name << "\" ��� ���� ���̴� \""
			<< player_age << "\"���̽ñ���!\n";
		std::cout << "�� ������ �÷����ϱ⿡ ������ �����Դϴ�.\n";
	}

	// �ڵ� ���� ����!
	system("pause");

	// ���α׷��� ���������� ����ȴٴ� ���� �ǹ�
	// exit(EXIT_SUCCESS); �̰Ͱ� �����!
	return 0;
}