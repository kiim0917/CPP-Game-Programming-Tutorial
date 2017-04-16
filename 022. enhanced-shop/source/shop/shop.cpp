/*
 * shop.cpp
 *
 *       Copyright (c) Ruvendix. ��� ���۱��� ���ο��� �ֽ��ϴ�.
 *
 * �� ������ C++ ���� ���α׷��� Ʃ�丮���� ���� �����Դϴ�.
 * ��쿡 ���󼭴� C++11 �̻��� ���뵵 ���Ե� �� �ֽ��ϴ�.
 * ����� �� ������ ���� �ڵ� ���̵带 �����ϴ�.
 *
 * shop.cpp�� ������ �ʿ��� ������ ����� ������ �����Դϴ�.
 * ������ ��ǰ�� ���� �� ���� �־�� �ϹǷ� �ڷᱸ���� �ʿ��մϴ�.
 * �������� ��ǰ�� �� �ٴڳ��� �� ��ǰ�� ��Ͽ��� �����˴ϴ�.
 */

#include "shop.h"
#include <iomanip>
#include <iostream>

// list�� �˻��ؼ� ��ǰ�� �߰�
// �̹� �ִ� ��ǰ�̸� ������ �߰�
void Shop::AddItem(const Item &item, bool is_first /* = false */)
{
	// iterator�� ���ڰ� i
	for (std::list<Item>::iterator i = item_list_.begin(); i != item_list_.end(); ++i)
	{
		// ������ �켱������ ���� ��ȣ�� �ľ� ��
		// ������ ��ǰ�� ã�� ���
		if ((*i).get_name() == item.get_name())
		{
			(*i).AddOne();
			return;
		}
	}

	// ��ǰ�� �� ã���� ���� �߰�
	item_list_.push_back(item);

	if (is_first == false)
	{
		// �ʱ�ȭ ��ǰ�� �ƴϰ� ���� �߰��Ǵ�
		// ��ǰ�̶�� ������ 1�� ����
		item_list_.back().set_count(1);
	}

	// ��ǰ�� �߰��Ǹ� ��ǰ�� �̸���
	// �ִ� �������� Ȯ��
	CheckMaxNameLength();
}

// ��ǰ�� �̸��� �ִ� �������� ����
void Shop::CheckMaxNameLength()
{
	int length;
	for (std::list<Item>::iterator i = item_list_.begin(); i != item_list_.end(); ++i)
	{
		length = (*i).get_name().size();
		if (length > max_name_length_)
		{
			max_name_length_ = length;
		}
	}
}

// list�� �˻��ؼ� ��ǰ�� ����
// ��ǰ�� ������ 0���� ��ǰ�� ��Ͽ��� ����
bool Shop::RemoveOneItem(const std::string &item_name)
{
	for (std::list<Item>::iterator i = item_list_.begin(); i != item_list_.end(); ++i)
	{
		if ((*i).get_name() == item_name)
		{
			// ��ǰ�� ã���� ������ �ϳ� ����
			(*i).RemoveOne();

			if ((*i).get_count() <= 0)
			{
				item_list_.erase(i);
				return true;
			}
		}
	}
	return false;
}

// ���� ����
void Shop::IntoShop(Player &player)
{
	bool is_done = false;
	char input;

	while (is_done == false)
	{
		ShowShop();
		player.ShowPlayer();

		std::cout << "��~ �ϰ� ���� �� ����? (������ q, ���� b, �Ǹ� s) : ";
		std::cin >> input;
		std::cout << std::endl;

		if (input == tolower('q'))
		{
			std::cout << "�� ����~ ������ �� ��~\n";
			std::cin.ignore();
			is_done = true;
		}
		else
		{
			if (input == tolower('b'))
			{
				SellItem(player);
			}
			else if (input == tolower('s'))
			{
				BuyItem(player);
			}
			system("pause");
			system("cls");
		}
	}
}

// ��ǰ�� ������
void Shop::GetItem(const std::string &item_name, Item &item)
{
	for (std::list<Item>::iterator i = item_list_.begin(); i != item_list_.end(); ++i)
	{
		if ((*i).get_name() == item_name)
		{
			item = *i;
		}
	}
}

// �������� �Ǹ�
bool Shop::SellItem(Player &player)
{
	std::cout << "������ ��ǰ�� ������ �˷���\n";
	std::cout << " >> ";
	std::string input_name;
	std::cin.ignore();
	getline(std::cin, input_name);
	std::cout << std::endl;

	Item item;
	GetItem(input_name, item);

	if (item.get_name() == "�̸� ����")
	{
		std::cout << "�׷� ��ǰ�� ������� �ʾ�\n";
		return false;
	}

	if (player.BuyItem(item) == false)
	{
		std::cout << "���� " << item.get_price() - player.get_money()
			<< "��ŭ ������ �� ������?\n";
		return false;
	}
	else
	{
		std::cout << "����~ �����ϰ� �������~\n";
		money_ += item.get_price();
		RemoveOneItem(input_name);
		return true;
	}
	return true;
}

// �������� ����
bool Shop::BuyItem(Player &player)
{
	std::cout << "�Ǹ��� ��ǰ�� ������ �˷���~ 80% ���ݿ� ���~\n";
	std::cout << " >> ";
	std::string input_name;
	std::cin.ignore();
	getline(std::cin, input_name);
	std::cout << std::endl;

	Item item;
	player.GetItem(input_name, item);

	if (item.get_name() == "�̸� ����")
	{
		std::cout << "�� �Ȱ� ���� �ž�?\n";
		return false;
	}

	int price = static_cast<int>(item.get_price() * 0.8);
	std::cout << input_name << "�� ���ε� ���� : " << price << std::endl;

	if (money_ >= price)
	{
		// �ǸŴ� 80% �������� �Ǹ�
		AddItem(item);
		player.SellItem(input_name, price);
		money_ -= price;
		std::cout << "����~ �� ����Ұ�~\n";
		return true;
	}
	else
	{
		std::cout << "�̾�������, ���� " << price - money_
			<< "��ŭ �����ؼ� ������ ���� ����...\n";
		return false;
	}
	return true;
}

// ������ ������ ���
void Shop::ShowShop()
{
	std::cout << "--------------------------------------------\n";
	std::cout << "��" << name_ << "��\n";
	std::cout << "�츮 ������ �� �Ծ�~\n";
	std::cout << "���� �ں� : " << money_ << std::endl << std::endl;
	ShowItemList();
	std::cout << "--------------------------------------------\n";
}

// list�� �˻��ؼ� ��ǰ�� ���
void Shop::ShowItemList()
{
	int num = 1;
	for (std::list<Item>::iterator i = item_list_.begin(); i != item_list_.end(); ++i, ++num)
	{
		std::cout << num << ". " << std::setw(max_name_length_) << std::left
			<< (*i).get_name() << " x " << std::setw(3) << (*i).get_count()
			<< "| �� : " << (*i).get_price() << "\n";
	}
}
