/*
 * player.h
 *
 *       Copyright (c) Ruvendix. ��� ���۱��� ���ο��� �ֽ��ϴ�.
 *
 * �� ������ C++ ���� ���α׷��� Ʃ�丮���� ���� �����Դϴ�.
 * ��쿡 ���󼭴� C++11 �̻��� ���뵵 ���Ե� �� �ֽ��ϴ�.
 * ����� �� ������ ���� �ڵ� ���̵带 �����ϴ�.
 *
 * player.h�� ���̸ӿ��� �ʿ��� ������ ����� ������ �����Դϴ�.
 * ���� �Լ��� �ζ��� �������� ���ǵǾ������� �����ϼ���.
 */

#ifndef ENHANCEDSHOP_PLAYER_PLAYER_H
#define ENHANCEDSHOP_PLAYER_PLAYER_H

#include <list>
#include <string>
#include "../item/item.h"

class Player
{
public:
	Player() : name_("�̸� ����"), money_(0) {}
	Player(const std::string &name, int money) : name_(name), money_(money) {}

	// list ������ ���� �Ҹ��� ���
	~Player() { item_list_.clear(); }

	// ��ǰ �߰�
	void AddItem(const Item &item, bool is_first = false);

	// ��ǰ�� �̸��� �ִ� �������� ����
	void CheckMaxNameLength();

	// ��ǰ�� �̸����� ��ǰ �ϳ� ����
	bool RemoveOneItem(const std::string &item_name);

	// ���̸� ���� ���
	void ShowPlayer();

	// ��ǰ ���� ���
	void ShowItemList();

	// ��ǰ ����
	bool BuyItem(const Item &item);

	// ��ǰ �Ǹ�
	void SellItem(const std::string &item_name, const int price);

	// ��ǰ ��������
	void GetItem(const std::string &item_name, Item &item);

	// get �޼���
	std::string get_name() const { return name_; }
	int get_money() const { return money_; }

	// set �޼���
	void set_name(const std::string &name) { name_ = name; }
	int set_money(const int money) { money_ = money; }
protected:
private:
	std::list<Item> item_list_; // ��ǰ ���
	std::string name_;          // ���̸� �̸�
	int money_;                 // ���̸� ��
	int max_name_length_;       // ��ǰ �̸��� �ִ� ����
};

#endif