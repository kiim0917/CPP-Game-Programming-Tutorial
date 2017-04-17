/* 
 * item.h
 *
 *       Copyright (c) Ruvendix. ��� ���۱��� ���ο��� �ֽ��ϴ�.
 *
 * �� ������ C++ ���� ���α׷��� Ʃ�丮���� ���� �����Դϴ�.
 * ��쿡 ���󼭴� C++11 �̻��� ���뵵 ���Ե� �� �ֽ��ϴ�.
 * ����� �� ������ ���� �ڵ� ���̵带 �����ϴ�.
 *
 * item.h�� ��ǰ�� �ʿ��� ������ ����� ������ �����Դϴ�.
 * ���� �Լ��� �ζ��� �������� ���ǵǾ������� �����ϼ���.
 */

#ifndef ENHANCEDSHOP_ITEM_ITEM_H
#define ENHANCEDSHOP_ITEM_ITEM_H

#include <string>

class Item
{
public:
	// �⺻ ������
	// ������ �ʱ�ȭ(��� �̴ϼȶ�����)�� �⺻�� ����
	Item() : name_("�̸� ����"), price_(0), code_(0xFFFFFFFF), count_(0) {}
	
	// �����ε��� ������
	Item(const std::string &name, int price, int code, int count)
		: name_(name), price_(price), code_(code), count_(count)
	{
		// ��ǰ�� ������ 0�� �̸��̸� 0,
		// 99�� �ʰ��ϸ� 99���� ����
		if (count < 0)
		{
			count_ = 0;
		}
		else if (count > 99)
		{
			count_ = 99;
		}
	}

	// �����ε��� ������
	Item(const std::string &name) : name_(name) {}

	// ��ǰ�� �ϳ� �߰�
	void AddOne();

	// ��ǰ�� �ϳ� ����
	void RemoveOne();

	// ����� ���� ���
	void ShowItemInfo();

	// get �޼���
	// const ��ü�� ����� �� �ֵ��� const�� ����
	std::string get_name() const { return name_; }
	int get_code() const { return code_; }
	int get_price() const { return price_; }
	int get_count() const { return count_; }

	// set �޼���
	void set_name(const std::string &name) { name_ = name; }
	void set_code(const int code) { code_ = code; }
	void set_price(const int price) { price_ = price; }
	void set_count(const int count) { count_ = count; }
protected:
private:
	std::string name_; // ��ǰ�� �̸�
	int code_;         // ��ǰ�� ������ȣ
	int price_;        // ��ǰ�� ����
	int count_;        // ��ǰ�� ����
};

#endif