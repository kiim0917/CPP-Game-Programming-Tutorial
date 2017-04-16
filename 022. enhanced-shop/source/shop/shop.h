/*
 * shop.h
 *
 *       Copyright (c) Ruvendix. ��� ���۱��� ���ο��� �ֽ��ϴ�.
 *
 * �� ������ C++ ���� ���α׷��� Ʃ�丮���� ���� �����Դϴ�.
 * ��쿡 ���󼭴� C++11 �̻��� ���뵵 ���Ե� �� �ֽ��ϴ�.
 * ����� �� ������ ���� �ڵ� ���̵带 �����ϴ�.
 *
 * shop.h�� ������ �ʿ��� ������ ����� ������ �����Դϴ�.
 * ���� �Լ��� �ζ��� �������� ���ǵǾ������� �����ϼ���.
 */

#ifndef ENHANCEDSHOP_SHOP_SHOP_H
#define ENHANCEDSHOP_SHOP_SHOP_H

#include <list>
#include <string>
#include "../item/item.h"
#include "../player/player.h"

class Shop
{
public:
	Shop() : name_("�̸� ����"), money_(0) {}
	Shop(const std::string &name, int money) : name_(name), money_(money) {}
	
	// list ������ ���� �Ҹ��� ���
	~Shop() { item_list_.clear(); }

	// ��ǰ �߰�
	void AddItem(const Item &item, bool is_first = false);

	// ��ǰ�� �̸��� �ִ� �������� ����
	void CheckMaxNameLength();

	// ��ǰ�� �̸����� ��ǰ �ϳ� ����
	bool RemoveOneItem(const std::string &item_name);

	// ���� ����
	void IntoShop(Player &player);

	// ��ǰ ��������
	void GetItem(const std::string &item_name, Item &item);

	// �������� �Ǹ�
	bool SellItem(Player &player);

	// �������� ����
	bool BuyItem(Player &player);

	// ���� ���� ���
	void ShowShop();
	
	// ������ ��ǰ ��� ���
	void ShowItemList();

	// get �޼���
	std::string get_name() const { return name_; }

	// set �޼���
	void set_name(const std::string &name) { name_ = name; }
protected:
private:
	std::list<Item> item_list_; // ��ǰ ���
	std::string name_;          // ���� �̸�
	int money_;                 // ���� ��
	int max_name_length_;       // ��ǰ �̸��� �ִ� ����
};

#endif