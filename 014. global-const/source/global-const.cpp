/*
 * global-const.cpp
 *
 *       Copyright (c) Ruvendix. ��� ���۱��� ���ο��� �ֽ��ϴ�.
 *
 * �� ������ C++ ���� ���α׷��� Ʃ�丮���� ���� �����Դϴ�.
 * ��쿡 ���󼭴� C++11 �̻��� ���뵵 ���Ե� �� �ֽ��ϴ�.
 * ����� �� ������ ���� �ڵ� ���̵带 �����ϴ�.
 *
 * global-const.cpp�� ���� ����� ���� �˾ƺ��ϴ�.
 * ���� ����� ���� ������ �� �������� ���� �����ʹ� �ٸ��� ������ �� �����ϴ�.
 * ���� ����� �̿��ؼ� ������ �� �� �ٵ��ô�.
 */

// std::cout�� ����� �����ִ� ��� ����
#include <iomanip>

// ǥ�� ������� ���� C++�� ��� ����
// using namespace std;�� �̿����� ����!
#include <iostream>

// std::string�� ���� ��� ����
// string.h�� �ƴ϶� string��!
#include <string>

// ���� ���
// static�� ���̸� ���� �ҽ� ���� �ȿ����� ��� ����!
static const int item_count = 5;
static const std::string item_list[item_count] = {"��", "����", "��ź", "ȸ����", "�ָԹ�"};

// �Լ��� ���� ���� ����
void IntoShop(int player_inventory[item_count]);
void ShowItemList();
void ShowPlayerInventory(const int player_inventory[item_count]);
bool BuyItem(int player_inventory[item_count]);

// ���α׷��� ������
// ��, ���α׷��� ���۵Ǵ� �κ�!
int main()
{
	system("title ���� �����");

	// ���̸��� �κ��丮
	// ������ �ִ� ��ǰ�� ������ ��ġ!
	// ���� ������ �ִ� ��ǰ�� ���� �״�� ���� ��!
	int player_inventory[item_count] = {1, 0, 0, 1, 3};

	// ���̸ӿ��� �κ��丮�� �������Ƿ�
	// IntoShop()�� ��ȭ�� ���ܾ� ��!
	IntoShop(player_inventory);

	// �ڵ� ���� ����!
	system("pause");

	// ���α׷��� ���������� ����ȴٴ� ���� �ǹ�
	// exit(EXIT_SUCCESS); �̰Ͱ� �����!
	return 0;
}

void IntoShop(int player_inventory[item_count])
{
	std::cout << "����~ �츮 ���Կ� �� �Դ�~\n";
	std::cout << "�ʿ��� �� ������ �ѹ� ��󺸶��!\n\n";

	bool is_done = false;

	// is_done�� true�� �ƴ� ������ �ݺ�
	while (is_done == false)
	{
		ShowItemList();
		ShowPlayerInventory(player_inventory);
		is_done = BuyItem(player_inventory);

		// is_done�� ������ �����ǹǷ�
		// true�� �ٲ�� �� �̻� ȭ���� ���� �ʿ䰡 ����!
		if (is_done == false)
		{
			system("pause");
			system("cls");
		}
	}

	std::cout << "�� ����~ ������ �� ��~\n";
}

void ShowItemList()
{
	std::cout << "----------- ��ǰ ��� -----------\n";
	for (int i = 0; i < item_count; ++i)
	{
		std::cout << i + 1 << ". " <<item_list[i] << std::endl;
	}
	std::cout << "---------------------------------\n";
}

void ShowPlayerInventory(const int player_inventory[item_count])
{
	std::cout << "<���� ������ �ִ� ������>\n";
	for (int i = 0; i < item_count; ++i)
	{
		// ������ 1�� �̻��� ���� ���!
		if (player_inventory[i] > 0)
		{
			std::cout << std::setw(6) << std::left <<  item_list[i] << " x "
				<< player_inventory[i] << std::endl;
		}
	}
	std::cout << std::endl;
}

bool BuyItem(int player_inventory[item_count])
{
	int input;
	std::cout << "������ ��ǰ��? (1 ~ 5, ��Ҵ� -1) : ";
	std::cin >> input;

	if (input == -1) return true;
	
	// �Է� ���� �˻�
	if (input <= 0 ||
		input > item_count)
	{
		std::cout << "�߸��� �Է��Դϴ�!\n";
		return false;
	}

	// ���̸��� �κ��丮�� ��ǰ �߰�
	player_inventory[input - 1]++;

	std::cout << item_list[input - 1] << "��(��) �����ߴ�!\n";
	return false;
}