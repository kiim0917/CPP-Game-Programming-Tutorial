/* 
 * enhanced-shop.cpp
 *
 *       Copyright (c) Ruvendix. ��� ���۱��� ���ο��� �ֽ��ϴ�.
 *
 * �� ������ C++ ���� ���α׷��� Ʃ�丮���� ���� �����Դϴ�.
 * ��쿡 ���󼭴� C++11 �̻��� ���뵵 ���Ե� �� �ֽ��ϴ�.
 * ����� �� ������ ���� �ڵ� ���̵带 �����ϴ�.
 *
 * enhanced-shop.cpp�� STL �� list�� ����ؼ� ������ ����ϴ�.
 * ������ ������ ��������� �߰��Ǵ� �κ��� �����Ƿ� �� ���ž� �մϴ�.
 * �ϴ� ������ �ϳ��� �ƴ϶� ���� ���� ��˴ϴ�.
 * �׸��� �� ������ ���ſ� �ǸŰ� �����մϴ�.
 * ���̸ӿ��� ������ ���� ���� ������ 80%�� �ް�
 * �� ��ǰ�� �Ǹ��� ���� ���� ���ݿ� �Ǹ��մϴ�.
 */

// std::cout�� ����� �����ִ� ��� ����
#include <iomanip>

// ǥ�� ������� ���� C++�� ��� ����
// using namespace std;�� �̿����� ����!
#include <iostream>

// std::list�� ���� ��� ����
// �ݵ�� �� ��� ������ �����ؾ� ��!
#include <list>

// std::string�� ���� ��� ����
// string.h�� �ƴ϶� string��!
#include <string>

#include "item/item.h"
#include "shop/shop.h"
#include "player/player.h"

void InitShops(std::list<Shop> &shops);
void ShowShops(const std::list<Shop> &shops);
bool VaildShop(std::list<Shop> &shops, const std::string &shop_name, Player &player);

// ���α׷��� ������
// ��, ���α׷��� ���۵Ǵ� �κ�!
int main()
{
	system("title �� �� ������ ���� �����");

	// ó���� ���̸��� �̸��� �Է�
	std::string input_name;
	std::cout << "ĳ������ �̸��� �Է��ϼ��� : ";
	getline(std::cin, input_name);

	std::cout << "\nȯ���մϴ�! \"" << input_name << "\" ��!\n";
	std::cout << "���� ������ �� ���� �̿���Դϴ�.\n";
	std::cout << "�� ���뿡 �����Ͻø� �ƹ� Ű�� �����ּ���.\n";
	system("pause");
	system("cls");

	// ���� �ʱ�ȭ
	Player player(input_name, 10000);
	player.AddItem(Item("���� �����", 10, 1, 1), true);
	player.AddItem(Item("ȸ����", 50, 2, 3), true);

	// ������ ���� �� ��ϱ� ���� list
	std::list<Shop> shops;
	InitShops(shops);

	bool is_done = false;
	while (is_done == false)
	{
		std::cout << "���� �̿� ������ �������Դϴ�.\n";
		ShowShops(shops);

		std::cout << "���ϴ� ������ �Է����ּ��� (quit�� �Է��ϸ� ����) : ";
		getline(std::cin, input_name);

		if (input_name == "quit")
		{
			is_done = true;
		}
		else
		{
			// ��ȿ�� �������� Ȯ��
			if (VaildShop(shops, input_name, player) == false)
			{
				std::cout << "�߸� �Է��߽��ϴ�!\n";
			}
			system("pause");
			system("cls");
		}
	}

	shops.clear();

	// �ڵ� ���� ����!
	system("pause");

	// ���α׷��� ���������� ����ȴٴ� ���� �ǹ�
	// exit(EXIT_SUCCESS); �̰Ͱ� �����!
	return 0;
}

// ���� �� ��ǰ �ʱ�ȭ
void InitShops(std::list<Shop> &shops)
{
	shops.push_back(Shop("��ȭ��", 2000));
	shops.back().AddItem(Item("��ȭå", 500, 3, 1), true);
	shops.back().AddItem(Item("���� ȸ����", 200, 4, 10), true);
	shops.back().AddItem(Item("ǳ��", 800, 5, 2), true);

	shops.push_back(Shop("������", 1500));
	shops.back().AddItem(Item("ö��", 1000, 6, 1), true);
	shops.back().AddItem(Item("����", 1500, 7, 1), true);
	shops.back().AddItem(Item("ũ����Ż��", 2500, 8, 1), true);
	shops.back().AddItem(Item("���̾Ƹ���", 200000000, 9, 1), true);

	shops.push_back(Shop("������", 1000));
	shops.back().AddItem(Item("���γ��� �Ľ�Ÿ", 500, 10, 10), true);
	shops.back().AddItem(Item("������", 2000, 11, 10), true);
	shops.back().AddItem(Item("���", 50, 12, 10), true);
	shops.back().AddItem(Item("���", 80, 13, 10), true);
	shops.back().AddItem(Item("������", 70, 14, 10), true);
}

// ��� ���� ���
void ShowShops(const std::list<Shop> &shops)
{
	int num = 1;
	for (std::list<Shop>::const_iterator i = shops.begin(); i != shops.end(); ++i, ++num)
	{
		std::cout << num << ". " << (*i).get_name() << std::endl;
	}
	std::cout << std::endl;
}

// ��ȿ�� �������� Ȯ��
bool VaildShop(std::list<Shop> &shops, const std::string &shop_name, Player &player)
{
	for (std::list<Shop>::iterator i = shops.begin(); i != shops.end(); ++i)
	{
		if ((*i).get_name() == shop_name)
		{
			// ��ȿ�� �����̸� ������ ��
			(*i).IntoShop(player);
			return true;
		}
	}
	return false;
}