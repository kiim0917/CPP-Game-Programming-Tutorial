/* 
 * vector.cpp
 *
 *       Copyright (c) Ruvendix. ��� ���۱��� ���ο��� �ֽ��ϴ�.
 *
 * �� ������ C++ ���� ���α׷��� Ʃ�丮���� ���� �����Դϴ�.
 * ��쿡 ���󼭴� C++11 �̻��� ���뵵 ���Ե� �� �ֽ��ϴ�.
 * ����� �� ������ ���� �ڵ� ���̵带 �����ϴ�.
 *
 * list.cpp�� STL �߿��� vector�� �˾ƺ��ϴ�.
 * list�� vectoró�� ũ�Ⱑ �þ ���� �ְ�,
 * �پ�� ���� �ִ� ������ �ڷᱸ���Դϴ�.
 * list�� ���԰� ������ ��������, �˻��� ���� �ڷᱸ���Դϴ�.
 * �����ϰ� push_back(), push_front(), begin(), end(), remove() ������ �˾ƺ��ϴ�.
 */

// std::cout�� ����� �����ִ� ��� ����
#include <iomanip>

// ǥ�� ������� ���� C++�� ��� ����
// using namespace std;�� �̿����� ����!
#include <iostream>

// std::string�� ���� ��� ����
// string.h�� �ƴ϶� string��!
#include <string>

// std::list�� ���� ��� ����
// �ݵ�� �� ��� ������ �����ؾ� ��!
#include <list>

void ShowItems(const std::list<std::string> &item_list);

// ���α׷��� ������
// ��, ���α׷��� ���۵Ǵ� �κ�!
int main()
{
	system("title list ����");

	// ũ�Ⱑ 0�� list ����
	// STL�� <> �ȿ� �ڷ����� ��� ��!
	std::list<int> empty_list;
	
	// list�� ũ��� size()�� �˾Ƴ� �� ����
	std::cout << "empty_list�� ũ�� : " << empty_list.size() << std::endl;

	// ũ�Ⱑ 10�� list ����
	std::list<int> ten_list(10);
	std::cout << "ten_list�� ũ��   : " << ten_list.size() << std::endl << std::endl;

	// std::string�� ��� list ����
	// �׳� ���ȣ�� ������ C++11 �̻���� ����!
	std::list<std::string> item_list = {"�尩", "��", "����"};
	ShowItems(item_list);

	// �� �ڿ� �տ� ������ �߰�
	std::cout << "<�ָԹ�, ȸ���� �߰�!>\n";
	item_list.push_back("�ָԹ�");
	item_list.push_front("ȸ����");
	ShowItems(item_list);

	// �� �ڿ� �տ� �ִ� ������ ����
	std::cout << "<�ָԹ�, ȸ���� ����!>\n";
	item_list.pop_back();
	item_list.pop_front();
	ShowItems(item_list);

	// �� ����
	std::cout << "<�� ����!>\n";
	item_list.remove("��");
	ShowItems(item_list);

	// ��ź, ���, �ż� �߰�
	// �ݺ��ڷ� ��� ����
	std::cout << "<��ź, ���, �ż� �߰��ϰ� ��� ����!>\n";
	item_list.push_back("��ź");
	item_list.push_back("���");
	item_list.push_back("�ż�");

	// auto�� ����� ���� �ڷ����� ���� �ľ��ؾ� ��!
	// std::list<std::string>::iterator�� �𸥴ٸ�
	// auto�� ���� ���� ���ͺ��� ����!
	for (auto iter = item_list.begin(); iter != item_list.end(); ++iter)
	{
		// ��̸� �˻�
		if (*iter == "���")
		{
			// erase()�� ���� ��Ҹ� �����ϰ�
			// ���� �ּҸ� ��ȯ�ϱ� ������
			// iter�� ���� �ּҸ� �޾ƾ� ��!
			// erase()�� iter�� �����ϹǷ� �׳� ++iter�δ�
			// ���� ��ġ�� �˾Ƴ� �� ����!
			// ������ vector�� �� �ڸ��� ä�����Ƿ� ++iter�ε� ����
			// 
			// erase(iter++)�� �ּҸ� �ϳ� �Ѿ �� �����Ƿ� ��õ���� ����
			iter = item_list.erase(iter);
		}
	}
	ShowItems(item_list);

	// �ڵ� ���� ����!
	system("pause");

	// ���α׷��� ���������� ����ȴٴ� ���� �ǹ�
	// exit(EXIT_SUCCESS); �̰Ͱ� �����!
	return 0;
}

void ShowItems(const std::list<std::string> &item_list)
{
	// C++11 �̻���ʹ� �������� auto�� ��ü
	// auto iter�� std::list<std::string>::iterator�� �˾Ƽ� ã����
	// iterator�� Ŭ����! � ������ Ŭ�������� �˷���� ��!
	// �ݺ����� ����� const��� const_iterator�� �̿��ؾ� ��!
	//
	// begin()�� ���� ù ��° ����� �ּҸ� ��ȯ
	// end()�� �� �ڿ� �ִ� ��� ������ �ּҸ� ��ȯ
	// ���� iter�� �����ϴٰ� ������ ���� ����� �ּҿ� �����ϸ�
	// end()�� ��ȯ���� �Ȱ������Ƿ� �ݺ����� Ż���ϰ� ��!
	for (std::list<std::string>::const_iterator iter = item_list.begin();
		iter != item_list.end(); ++iter)
	{
		// iter�� ����� ��ġ�� ���� ����
		// ���� ��ҿ� �����Ϸ��� * �����ڸ� �̿��ؾ� ��!
		std::cout << *iter << std::endl;
	}
	std::cout << "------------------------------------------\n";
}