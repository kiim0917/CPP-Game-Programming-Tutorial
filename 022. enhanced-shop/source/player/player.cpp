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
void Player::AddItem(const Item &item, bool is_first /* = false */)
{
	for (std::list<Item>::iterator i = item_list_.begin(); i != item_list_.end(); ++i)
	{
		if ((*i).get_name() == item.get_name())
		{
			(*i).AddOne();
			return;
		}
	}

	item_list_.push_back(item);

	if (is_first == false)
	{
		item_list_.back().set_count(1);
	}
	CheckMaxNameLength();
}

// ��ǰ�� �̸��� �ִ� �������� ����
void Player::CheckMaxNameLength()
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

// ��ǰ ����
bool Player::RemoveOneItem(const std::string &item_name)
{
	for (std::list<Item>::iterator i = item_list_.begin(); i != item_list_.end(); ++i)
	{
		if ((*i).get_name() == item_name)
		{
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
		std::cout << num << ". " << std::setw(max_name_length_) << std::left
			<< (*i).get_name() << " x " << std::setw(3) << (*i).get_count()
			<< "| �� : " << (*i).get_price() << "\n";
	}
}

// ��ǰ ����
bool Player::BuyItem(const Item &item)
{
	int price = item.get_price();
	bool overlap = false;
	std::list<Item>::iterator i;

	for (i = item_list_.begin(); i != item_list_.end(); ++i)
	{
		if ((*i).get_name() == item.get_name())
		{
			overlap = true;
			break;
		}
	}

	// ���� ���� ���� �� ���� ���� ��ǰ�� ����
	if (money_ >= price)
	{
		money_ -= price;

		if (overlap == true)
		{
			(*i).AddOne();
		}
		else
		{
			AddItem(item);
		}
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