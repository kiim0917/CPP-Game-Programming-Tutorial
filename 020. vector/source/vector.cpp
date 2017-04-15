/* 
 * vector.cpp
 *
 *       Copyright (c) Ruvendix. ��� ���۱��� ���ο��� �ֽ��ϴ�.
 *
 * �� ������ C++ ���� ���α׷��� Ʃ�丮���� ���� �����Դϴ�.
 * ��쿡 ���󼭴� C++11 �̻��� ���뵵 ���Ե� �� �ֽ��ϴ�.
 * ����� �� ������ ���� �ڵ� ���̵带 �����ϴ�.
 *
 * vector.cpp�� STL �߿��� vector�� �˾ƺ��ϴ�.
 * vector�� �迭�� ��������� ũ�Ⱑ �þ ���� �ְ�,
 * �پ�� ���� �ִ� ������ �迭�Դϴ�.
 * vector�� ���԰� ������ �������, �˻��� ���� �ڷᱸ���Դϴ�.
 * �����ϰ� push_back(), pop_back(), back() ������ �˾ƺ��ϴ�.
 * resize(), reserve()�� �����մϴ�.
 */

// std::cout�� ����� �����ִ� ��� ����
#include <iomanip>

// ǥ�� ������� ���� C++�� ��� ����
// using namespace std;�� �̿����� ����!
#include <iostream>

// std::string�� ���� ��� ����
// string.h�� �ƴ϶� string��!
#include <string>

// std::vector�� ���� ��� ����
// �ݵ�� �� ��� ������ �����ؾ� ��!
#include <vector>

void ShowItems(const std::vector<std::string> &item_vec);

// ���α׷��� ������
// ��, ���α׷��� ���۵Ǵ� �κ�!
int main()
{
	system("title vector ����");

	// ũ�Ⱑ 0�� vector ����
	// STL�� <> �ȿ� �ڷ����� ��� ��!
	std::vector<int> empty_vec;
	
	// vector�� ũ��� size()�� �˾Ƴ� �� ����
	std::cout << "empty_vec�� ũ�� : " << empty_vec.size() << std::endl;

	// ũ�Ⱑ 10�� vector ����
	std::vector<int> ten_vec(10);
	std::cout << "ten_vec�� ũ��   : " << ten_vec.size() << std::endl << std::endl;

	// std::string�� ��� vector ����
	// �׳� ���ȣ�� ������ C++11 �̻���� ����!
	std::vector<std::string> item_vec = {"�尩", "��", "����"};
	ShowItems(item_vec);

	// ���ο� ������ �߰�
	std::cout << "�ָԹ�, ȸ���� �߰�!\n";
	item_vec.push_back("�ָԹ�");
	item_vec.push_back("ȸ����");
	ShowItems(item_vec);

	// �� �ڿ� �ִ� ������ ����
	std::cout << "ȸ���� ����!\n";
	item_vec.pop_back();
	ShowItems(item_vec);

	// �� �ڿ� �ִ� �������� �� ��° ���������� �ű��
	// �� ��° �������� ������ ������
	std::cout << "�� ����!\n";
	item_vec[1] = item_vec.back();
	ShowItems(item_vec);

	// �ڵ� ���� ����!
	system("pause");

	// ���α׷��� ���������� ����ȴٴ� ���� �ǹ�
	// exit(EXIT_SUCCESS); �̰Ͱ� �����!
	return 0;
}

void ShowItems(const std::vector<std::string> &item_vec)
{
	for (int i = 0; i < static_cast<int>(item_vec.size()); ++i)
	{
		std::cout << item_vec[i] << std::endl;
	}
	std::cout << "--------------------\n";
}