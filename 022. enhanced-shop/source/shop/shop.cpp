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

 // ��ǰ �߰�
 // list�� �˻��ؼ� �ߺ��Ǵ� �̸��� ��ǰ�� �߰ߵǸ�
 // �� ��ǰ�� ������ ������Ű��, ���ο� ��ǰ�� �߰ߵǸ� list�� ����
void Shop::AddItem(const Item &item, bool is_first /* = false */)
{
	// iterator�� ���ڰ� i
	for (std::list<Item>::iterator i = item_list_.begin(); i != item_list_.end(); ++i)
	{
		// ������ �켱������ ���� ��ȣ�� �ľ� ��
		// ������ ��ǰ�� ã�� ���
		if ((*i).get_name() == item.get_name())
		{
			(*i).AddOne(); // ���� ��ǰ �ϳ� ����
			return;
		}
	}

	// ��ǰ�� �� ã���� ���� �߰�
	item_list_.push_back(item);

	// �ʱ�ȭ���� �ƴ϶��
	// ���� ���� ��ǰ�� ������ ������ 1��
	if (is_first == false)
	{
		item_list_.back().set_count(1);
	}

	// ����ϰ� ����ϱ� ����
	// ��ǰ�� �̸��� �ִ� �������� Ȯ��
	CheckMaxNameLength();
}

// ��ǰ�� �̸��� �ִ� �������� ����
void Shop::CheckMaxNameLength()
{
	int length;
	for (std::list<Item>::iterator i = item_list_.begin(); i != item_list_.end(); ++i)
	{
		// list�� �ִ� ��� ��ǰ�� �˻��ؼ�
		// ��ǰ�� �̸��� ���̸� ��� ����
		length = (*i).get_name().size();

		// ��ǰ�� �̸��� ���� ������
		// �ִ� ���̺��� ��ٸ� ����
		if (length > max_name_length_)
		{
			max_name_length_ = length;
		}
	}
}

// ��ǰ ����
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

// ��ǰ ��������
// list�� �˻��ؼ� ��ǰ�� �̸��� ã��,
// ��ǰ�� �̸��� ã���� item�� ����
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

// �������� �Ǹ� => ���̸��� ����
bool Shop::SellItem(Player &player)
{
	std::cout << "������ ��ǰ�� ������ �˷���\n";
	std::cout << " >> ";

	// ������ ������ ���ڿ��� �Է¹޴� ���
	// ���͸� ġ�� ���� ���ڰ� �Է� ���ۿ� �����Ƿ�
	// ignore()�� ���� �ϳ��� �����ϸ� ��
	std::string input_name;
	std::cin.ignore();
	getline(std::cin, input_name);
	std::cout << std::endl;

	Item item;
	GetItem(input_name, item); // ������ ��ǰ�� ã�Ƽ� item�� ����

	// ��ǰ�� �̸��� �⺻ �����̶��
	// ��ǰ�� ã�� ���ߴٴ� ��
	if (item.get_name() == "�̸� ����")
	{
		std::cout << "�׷� ��ǰ�� ������� �ʾ�\n";
		return false;
	}

	// ���̸Ӱ� ���Ÿ� ������ ���
	if (player.BuyItem(item) == false)
	{
		std::cout << "���� " << item.get_price() - player.get_money()
			<< "��ŭ ������ �� ������?\n";
		return false;
	}
	else // ���̸Ӱ� ���Ÿ� ������ ���
	{
		std::cout << "����~ �����ϰ� �������~\n";
		money_ += item.get_price(); // ������ �ں� ����
		RemoveOneItem(input_name);  // ������ ��ǰ �ϳ� ����
		return true;
	}
	return true;
}

// �������� ���� => ���̸��� �Ǹ�
bool Shop::BuyItem(Player &player)
{
	std::cout << "�Ǹ��� ��ǰ�� ������ �˷���~ 80% ���ݿ� ���~\n";
	std::cout << " >> ";

	// ������ ������ ���ڿ��� �Է¹޴� ���
	// ���͸� ġ�� ���� ���ڰ� �Է� ���ۿ� �����Ƿ�
	// ignore()�� ���� �ϳ��� �����ϸ� ��
	std::string input_name;
	std::cin.ignore();
	getline(std::cin, input_name);
	std::cout << std::endl;

	Item item;
	player.GetItem(input_name, item); // ���̸��� ��ǰ�� ã�Ƽ� item�� ����

	// ��ǰ�� �̸��� �⺻ �����̶��
	// ��ǰ�� ã�� ���ߴٴ� ��
	if (item.get_name() == "�̸� ����")
	{
		std::cout << "�� �Ȱ� ���� �ž�?\n";
		return false;
	}

	// �������� ���̸ӿ��� ��ǰ�� ������ ����
	// �⺻ ������ 80%��ŭ�� ����
	// ��, 20% ���εȴٰ� �����ϸ� ��
	// item.get_price() * 0.8�� �� �� ���ϰ�
	// ����Ϸ��� price��� ������ ������ ����
	int price = static_cast<int>(item.get_price() * 0.8);
	std::cout << input_name << "�� ���ε� ���� : " << price << std::endl;

	// ������ �ں��� ��ǰ�� ���ݺ��� ���� ���
	if (money_ >= price)
	{
		// �ǸŴ� 80% �������� �Ǹ�
		AddItem(item); // ���̸Ӱ� �Ǹ��� ��ǰ�� �߰�
		player.SellItem(input_name, price); // ���̸��� �� ����
		money_ -= price; // ������ �ں� ����
		std::cout << "����~ �� ����Ұ�~\n";
		return true;
	}
	else // ������ �ں��� ��ǰ�� ���ݺ��� ���� ���
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
		// ��ǰ�� �ִ� ���̸� �̿��ؼ� ������ �ڿ� ���
		std::cout << num << ". " << std::setw(max_name_length_) << std::left
			<< (*i).get_name() << " x " << std::setw(3) << (*i).get_count()
			<< "| �� : " << (*i).get_price() << "\n";
	}
}
