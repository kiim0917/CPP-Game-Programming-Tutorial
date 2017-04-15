/* 
 * finish-shop.cpp
 *
 *       Copyright (c) Ruvendix. ��� ���۱��� ���ο��� �ֽ��ϴ�.
 *
 * �� ������ C++ ���� ���α׷��� Ʃ�丮���� ���� �����Դϴ�.
 * ��쿡 ���󼭴� C++11 �̻��� ���뵵 ���Ե� �� �ֽ��ϴ�.
 * ����� �� ������ ���� �ڵ� ���̵带 �����ϴ�.
 *
 * finish-shop.cpp�� ������ �ϼ��մϴ�.
 * �̹����� constexpr�� ����ϴµ� �Լ��� constexpr�� �ٴ� ��
 * C++14 �̻���� �����ϹǷ� �� ���� �����ؾ� �մϴ�.
 */

// std::cout�� ����� �����ִ� ��� ����
#include <iomanip>

// ǥ�� ������� ���� C++�� ��� ����
// using namespace std;�� �̿����� ����!
#include <iostream>

// std::string�� ���� ��� ����
// string.h�� �ƴ϶� string��!
#include <string>

// constexpr �Լ��� ���Ǳ��� �ؾ� ��!
// constexpr�� ������ Ÿ�ӿ� ����� ����ϰڴٴ� ��
// ���� �迭�� ũ�⸦ ������ �� �̿��� �� ����!
constexpr int GetMaxCount()
{
	return 6;
}

// ���� ���
// static�� ���̸� ���� �ҽ� ���� �ȿ����� ��� ����!
// static const int item_count = 6; �̰��� ����� ������ ����
static const std::string item_list[GetMaxCount()] = {"��", "����", "��ź", "ȸ����", "�ָԹ�", "���̾Ƹ��"};

// ��ǰ�� ���ݵ� �̷��� �迭�� ǥ���ϸ� switch ~ case�� ����� �ʿ䰡 ����
static const int item_price[GetMaxCount()] = {10000, 5000, 3000, 1000, 2000, 200000000};

// �Լ��� ���� ���� ����
void IntoShop(int player_inventory[], int player_money);
void ShowItemList();
void ShowPlayerInventory(const int player_inventory[]);
bool BuyItem(int player_inventory[], int &player_money);

// ���α׷��� ������
// ��, ���α׷��� ���۵Ǵ� �κ�!
int main()
{
	system("title ���� �����");

	// ���̸��� �κ��丮
	// ������ �ִ� ��ǰ�� ������ ��ġ!
	// ���� ������ �ִ� ��ǰ�� ���� �״�� ���� ��!
	int player_inventory[GetMaxCount()] = {1, 0, 0, 1, 3, 0};
	int player_money = 50000;

	// ���̸ӿ��� �κ��丮�� �������Ƿ�
	// IntoShop()�� ��ȭ�� ���ܾ� ��!
	IntoShop(player_inventory, player_money);

	// �ڵ� ���� ����!
	system("pause");

	// ���α׷��� ���������� ����ȴٴ� ���� �ǹ�
	// exit(EXIT_SUCCESS); �̰Ͱ� �����!
	return 0;
}

void IntoShop(int player_inventory[], int player_money)
{
	std::cout << "����~ �츮 ���Կ� �� �Դ�~\n";
	std::cout << "�ʿ��� �� ������ �ѹ� ��󺸶��!\n\n";

	bool is_done = false;

	// is_done�� true�� �ƴ� ������ �ݺ�
	while (is_done == false)
	{
		std::cout << "���� ���� �� : " << player_money << std::endl;
		ShowItemList();
		ShowPlayerInventory(player_inventory);
		is_done = BuyItem(player_inventory, player_money);

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
	for (int i = 0; i < GetMaxCount(); ++i)
	{
		std::cout << i + 1 << ". " <<item_list[i] << 
			"(" << item_price[i] << ")" << std::endl;
	}
	std::cout << "---------------------------------\n";
}

void ShowPlayerInventory(const int player_inventory[])
{
	std::cout << "<���� ������ �ִ� ������>\n";
	for (int i = 0; i < GetMaxCount(); ++i)
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

bool BuyItem(int player_inventory[], int &player_money)
{
	int input;
	std::cout << "������ ��ǰ��? (1 ~ " << GetMaxCount() << ", ��Ҵ� -1) : ";
	std::cin >> input;

	if (input == -1) return true;
	
	// �Է� ���� �˻�
	if (input - 1 < 0 ||
		input > GetMaxCount())
	{
		std::cout << "�߸��� �Է��Դϴ�!\n";
		return false;
	}

	// ���̸��� �κ��丮�� ��ǰ �߰�
	// ���� ���� ���� ������ ��ǰ�� ���ݺ��� ���� ���� ����
	if (player_money >= item_price[input - 1])
	{
		player_money -= item_price[input - 1];
		player_inventory[input - 1]++;
		std::cout << item_list[input - 1] << "��(��) �����ߴ�!\n";
	}
	else
	{
		// ������ �ݾ��� (��ǰ ���� - ���� ���� ��)
		std::cout << "�ݾ��� " << item_price[input - 1] - player_money << "��ŭ �����մϴ�!\n";
	}
	return false;
}