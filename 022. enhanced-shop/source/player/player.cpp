/*
 * player.cpp
 *
 *       Copyright (c) Ruvendix. ��� ���۱��� ���ο��� �ֽ��ϴ�.
 *
 * �� ������ C++ ���� ���α׷��� Ʃ�丮���� ���� �����Դϴ�.
 * ��쿡 ���󼭴� C++11 �̻��� ���뵵 ���Ե� �� �ֽ��ϴ�.
 * ����� �� ������ ���� �ڵ� ���̵带 �����ϴ�.
 *
 * player.cpp�� ���̸ӿ��� �ʿ��� ������ ����� ������ �����Դϴ�.
 * ���̸Ӵ� ����ó�� ��ǰ ��ϰ� ���� ���� �ֽ��ϴ�.
 * ������ ���̸Ӱ� �ٸ� ���� ���̸Ӵ� �Է� ����� �ִٴ� �̴ϴ�.
 */

#include "player.h"
#include <iomanip>
#include <iostream>

// ��ǰ �߰�
// list�� �˻��ؼ� �ߺ��Ǵ� �̸��� ��ǰ�� �߰ߵǸ�
// �� ��ǰ�� ������ ������Ű��, ���ο� ��ǰ�� �߰ߵǸ� list�� ����
void Player::AddItem(const Item &item, bool is_first /* = false */)
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
void Player::CheckMaxNameLength()
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
bool Player::RemoveOneItem(const std::string &item_name)
{
	for (std::list<Item>::iterator i = item_list_.begin(); i != item_list_.end(); ++i)
	{
		if ((*i).get_name() == item_name)
		{
			// ��ǰ�� ã���� ������ �ϳ� ����
			(*i).RemoveOne();

			// ��ǰ�� ������ 0�� ���϶��
			// list���� ��ǰ ����
			if ((*i).get_count() <= 0)
			{
				item_list_.erase(i);
				return true;
			}
		}
	}
	return false;
}

// ���̸��� ���� ���
void Player::ShowPlayer()
{
	std::cout << "--------------------------------------------\n";
	std::cout << "���̸��� �̸� : " << name_ << std::endl;
	std::cout << "���� ���� ��  : " << money_ << std::endl << std::endl;
	ShowItemList();
	std::cout << "--------------------------------------------\n";
}

// ���̸��� ��ǰ ���� ���
void Player::ShowItemList()
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

// ��ǰ ����
// AddItem()�� �̿��ؼ� ó��
bool Player::BuyItem(const Item &item)
{
	// ������ ��ǰ�� ������ �ӽ÷� ����
	// item.get_price()�� ��� ȣ���ص� ������
	// �Լ��� ȣ���� ���̴� ������ ������带 ���� �� ����
	// �׷��� �� ���� ���� �Լ��̹Ƿ� �״��� ������ ���� ����
	int price = item.get_price();

	// ���� ���� ���� �� ���� ���� ��ǰ�� ����
	if (money_ >= price)
	{
		money_ -= price;
		AddItem(item);
		return true;
	}
	else
	{
		return false;
	}
	return false;
}

// ��ǰ �Ǹ�
void Player::SellItem(const std::string &item_name, const int price)
{
	RemoveOneItem(item_name);
	money_ += price;
}

// ��ǰ ��������
// list�� �˻��ؼ� ��ǰ�� �̸��� ã��,
// ��ǰ�� �̸��� ã���� item�� ����
void Player::GetItem(const std::string &item_name, Item &item)
{
	for (std::list<Item>::iterator i = item_list_.begin(); i != item_list_.end(); ++i)
	{
		if ((*i).get_name() == item_name)
		{
			item = *i;
		}
	}
}