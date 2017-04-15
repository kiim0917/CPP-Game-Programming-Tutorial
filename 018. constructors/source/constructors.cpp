/* 
 * constructors.cpp
 *
 *       Copyright (c) Ruvendix. ��� ���۱��� ���ο��� �ֽ��ϴ�.
 *
 * �� ������ C++ ���� ���α׷��� Ʃ�丮���� ���� �����Դϴ�.
 * ��쿡 ���󼭴� C++11 �̻��� ���뵵 ���Ե� �� �ֽ��ϴ�.
 * ����� �� ������ ���� �ڵ� ���̵带 �����ϴ�.
 *
 * constructors.cpp�� Ŭ������ �����ڿ� ���� �˾ƺ��ϴ�.
 * �������ʹ� Ŭ���� ���� ������ ���� ������ ����˴ϴ�.
 * ������ ������ �� ���Ϳ� ������ ��ġ��ų �״� �����ϼ���.
 */

// std::cout�� ����� �����ִ� ��� ����
#include <iomanip>

// ǥ�� ������� ���� C++�� ��� ����
// using namespace std;�� �̿����� ����!
#include <iostream>

// std::string�� ���� ��� ����
// string.h�� �ƴ϶� string��!
#include <string>

// �⺻ ��ο��� ������ ã�ƾ� ��!
#include "monster/monster.h"

// ���α׷��� ������
// ��, ���α׷��� ���۵Ǵ� �κ�!
int main()
{
	system("title ������ �����ϱ�");

	// �⺻ �����ڰ� �־�� ���� ����!
	Monster monster_list[100];

	// ù ��°�� ������ ÷�ڷ� Ȯ���غ���
	monster_list[0].ShowName();
	monster_list[99].ShowName();

	std::cout << std::endl;

	// �����ε��� �����ڸ� �̿��� ����
	// �Լ��� ȣ���ϴ� ��ó�� ���ڸ� �ѱ�� ��
	Monster dragon("��");
	Monster dark_elf("���� ����");

	dragon.ShowName();
	dark_elf.ShowName();	

	// �ڵ� ���� ����!
	system("pause");

	// ���α׷��� ���������� ����ȴٴ� ���� �ǹ�
	// exit(EXIT_SUCCESS); �̰Ͱ� �����!
	return 0;
}