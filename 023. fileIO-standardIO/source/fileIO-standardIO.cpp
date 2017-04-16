/* 
 * fileIO-standardIO.cpp
 *
 *       Copyright (c) Ruvendix. ��� ���۱��� ���ο��� �ֽ��ϴ�.
 *
 * �� ������ C++ ���� ���α׷��� Ʃ�丮���� ���� �����Դϴ�.
 * ��쿡 ���󼭴� C++11 �̻��� ���뵵 ���Ե� �� �ֽ��ϴ�.
 * ����� �� ������ ���� �ڵ� ���̵带 �����ϴ�.
 *
 * fileIO-standardIO.cpp�� ���� ����°� ǥ�� ����¿� ���� �˾ƺ��ϴ�.
 * ���� ����°� ǥ�� ������� ����� ������ ������ �ٷ�� ���Դϴ�.
 * ���� �����ÿ��� ������ ���� �� ������ �ٷ�� �κ��� ������ �����ߴµ�
 * �̹����� �� ������ �ٷ� �� �׷��� �ؾ� �ϴ��� �˷��帮�ڽ��ϴ�.
 */

// ���� ������� ���� C++�� ��� ����
#include <fstream>

// std::cout�� ����� �����ִ� ��� ����
#include <iomanip>

// ǥ�� ������� ���� C++�� ��� ����
// using namespace std;�� �̿����� ����!
#include <iostream>

// std::string�� ���� ��� ����
// string.h�� �ƴ϶� string��!
#include <string>

// ���α׷��� ������
// ��, ���α׷��� ���۵Ǵ� �κ�!
int main()
{
	system("title ���� ����°� ǥ�� �����");

	//// ���Ͽ� ���
	//// ������ �����Ǵ� ��δ� ������Ʈ�� �⺻ ���
	//std::ofstream write_file("test.txt");

	//// ���� ��Ʈ���� �������� ���� ���
	//if (write_file.fail() == true)
	//{
	//	perror("test.txt�� �������� ���߽��ϴ�!");
	//  exit(EXIT_FAILURE);
	//}

	//// ���Ͽ� ���ڿ� ����ϱ�
	//std::string test = "Hello World~\n";

	//write_file << test;

	//std::cout << "���Ͽ� ���ڿ��� ����߽��ϴ�.\n";

	//// ���� ��Ʈ�� ����
	//write_file.close();

	//// ���Ͽ��� �Է�
	//std::ifstream read_file("test.txt");

	//// ���� ��Ʈ���� �������� ���� ���
	//if (read_file.fail() == true)
	//{
	//	perror("test.txt�� �о���� ���߽��ϴ�!");
	//	exit(EXIT_FAILURE);
	//}

	//// ���Ͽ��� ������ �о������
	// ������ ������ ������ �ʿ���!
	//std::string test;

	//// ���Ͽ��� ���ڿ� �о����
	//read_file >> test;

	//std::cout << test << std::endl;

	//// ���Ͽ��� ���� ���ڿ� �о����
	//// �Է� �κе� �Լ��� �̿��ϴ� ���̹Ƿ�
	//// ��ȯ���� �ְ�, �� ��ȯ���� �̿��ϸ�
	//// ���̳� �����̳ĸ� �Ǵ��� �� ����!
	//for ( ; read_file >> test; )
	//{
	//	std::cout << test << std::endl;
	//}

	// ������ ������ ���ڿ� �о����
	//getline(read_file, test);

	//std::cout << test << std::endl;

	//// ������ ������ ���� ���ڿ� �о����
	//for ( ; getline(read_file, test); )
	//{
	//	std::cout << test << std::endl;
	//}

	//std::cout << "���Ͽ��� ���ڿ��� �о�Խ��ϴ�.\n";

	//read_file.close();

	////// ������ ������ ���ڿ� �Է¹ޱ�
	//std::string test;

	////std::cout << "������ ������ ���ڿ��� �Է��ϼ���\n";
	////std::cout << " >> ";
	//
	//// ������ ������ ���ڿ��� �Է¹��� ����
	//// getline()�� �̿��ؾ� ��!
	//std::cout << "���ڿ��� �Է��ϼ���\n";
	//std::cout << " >> ";
	//std::cin >> test;
	//std::cout << "\n�Է��� ���ڿ� : " << test << std::endl << std::endl;

	//// �Է� ���ۿ� �����ִ� ������
	//// �о ������ �Լ�
	//// �⺻���� 1, eof
	////
	//// ������ ������ŭ �о
	//// ������ ���� ������ ������
	//// ��� ������ ����
	//std::cin.ignore(128, '\n');

	//std::cout << "���ڿ��� �Է��ϼ���\n";
	//std::cout << " >> ";
	//getline(std::cin, test);
	//std::cout << "\n�Է��� ���ڿ� : " << test << std::endl;

	// std::cin�� ���� �߻�
	int num;

	for ( ; ; )
	{
		std::cout << "���ڸ� �Է��ϼ��� : ";
		std::cin >> num;

		// ���Ŀ� ���� �ʴ� �Է��� �߻��ϸ�
		// failbit�� ������
		if (std::cin.fail() == true)
		{
			std::cout << "�Է� ���� �߻�! ���� ��ȣ : " << std::cin.rdstate() << std::endl;

			// �Է� ������ �߻��Ǹ�
			// std::cin�� ������ failbit�� ������!
			// ���� ���� ���¸� �ʱ�ȭ�����
			// ignore()�� ���������� �۵���!
			// �׷��� clear()���� ����� ��!
			std::cin.clear();

			// ignore()�� std::cin��
			// ������ ���� �� ���������� �۵���!
			// ��, goodbit�� ���� �۵��� �����!
			std::cin.ignore(128, '\n');

			system("pause");
		}

		std::cout << "�Է��� ���� : " << num << std::endl << std::endl;
	}

	// �ڵ� ���� ����!
	system("pause");

	// ���α׷��� ���������� ����ȴٴ� ���� �ǹ�
	// exit(EXIT_SUCCESS); �̰Ͱ� �����!
	return 0;
}