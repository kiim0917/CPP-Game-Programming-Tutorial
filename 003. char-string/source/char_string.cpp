/*
 * char_string.cpp
 *
 *       Copyright (c) Ruvendix. ��� ���۱��� ���ο��� �ֽ��ϴ�.
 *
 * �� ������ C++ ���� ���α׷��� Ʃ�丮���� ���� �����Դϴ�.
 * ��쿡 ���󼭴� C++11 �̻��� ���뵵 ���Ե� �� �ֽ��ϴ�.
 * ����� �� ������ ���� �ڵ� ���̵带 �����ϴ�.
 *
 * char_string.cpp�� �⺻ �ڷ����� char�� ǥ�� ���̺귯�� std::string�� �ٷ�ϴ�.
 * ������ ���ڴ� char�� �̿��ϰ�, ���ڿ��� std::string�� �̿��ϰڽ��ϴ�.
 *
 */

// ǥ�� ������� ���� C++�� ��� ����
// using namespace std;�� �̿����� ����!
// ��а��� printf() ��� std::cout�� ����ϰ���!
#include <iostream>

// std::string�� ���� ��� ����
// string.h�� �ƴ϶� string��!
#include <string>

// ���α׷��� ������
// ��, ���α׷��� ���۵Ǵ� �κ�!
int main()
{
	// ���ڸ� �ٷ� ���� char!
	// char�� ���� �ϳ��� ������ �� ����!
	// ���ڸ� ǥ���� ���� ' '�� ��� ��!
	char alphabet = 'B';

	std::cout << "���ĺ� : " << alphabet << std::endl << std::endl;

	// ������ �̷��� ���� ����(���ڿ�)�� �ٷ� ���� ����!
	// ���� ���ڸ� �ٷ���� char�� �ƴ϶� �ٸ� ����� �ʿ���!
	// �̷��� ���� ���ڸ� �����ϸ� �� �����ʿ� �ִ� ���� �ϳ��� �����!
	char dog_name = 'Ben';

	std::cout << "�� �̸� : " << dog_name << std::endl << std::endl;

	// ���ڿ��� �ٷ� ���� std::string!
	// std::string�� �⺻ �ڷ����� �ƴ�!
	// ���ڿ��� ���ϰ� ����� ���� std::cout ���� ����!
	// ���ڿ��� ǥ���� ���� " "�� ��� ��!
	std::string player_name = "Ben";

	std::cout << "������ �г����� " << player_name << "�Դϴ�." << std::endl;

	// std::string���� ������ ����� ����!
	// length()�� ���ڿ��� ���̸� �˷���!
	std::cout << "�г����� " << player_name.length() << "���� ���ڷ� �Ǿ��ֽ��ϴ�."
		<< std::endl << std::endl;

	// std::string�� �̷��� ���ڿ� ��ü�� ����!
	player_name = "�纥��";

	std::cout << "������ �г����� " << player_name << "�Դϴ�." << std::endl;
	std::cout << "�г����� " << player_name.length() << "���� ���ڷ� �Ǿ��ֽ��ϴ�." << std::endl;

	// �ڵ� ���� ����!
	system("pause");

	// ���α׷��� ���������� ����ȴٴ� ���� �ǹ�
	// exit(EXIT_SUCCESS); �̰Ͱ� �����!
	return 0;
}