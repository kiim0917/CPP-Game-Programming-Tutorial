/* 
 * type-casting.cpp
 *
 *       Copyright (c) Ruvendix. ��� ���۱��� ���ο��� �ֽ��ϴ�.
 *
 * �� ������ C++ ���� ���α׷��� Ʃ�丮���� ���� �����Դϴ�.
 * ��쿡 ���󼭴� C++11 �̻��� ���뵵 ���Ե� �� �ֽ��ϴ�.
 * ����� �� ������ ���� �ڵ� ���̵带 �����ϴ�.
 *
 * type-casting.cpp�� �⺻ �ڷ����� ����ȯ�� �˾ƺ��ϴ�.
 * C������ ()�� �̿��ؼ� ����ȯ�� ������
 * C++������ ����ȯ�� �������� ���� 4������ ���� �ֽ��ϴ�.
 * ���⼭�� �⺻ �ڷ����� ����ȯ�� ����ϴ� static_cast�� �˾ƺ��Կ�.
 * ����ȯ�� �� �� ����� �˾ƺ��� ���� cout�� �̿��մϴ�.
 */

// std::cout�� ����� �����ִ� ��� ����
#include <iomanip>

// ǥ�� ������� ���� C++�� ��� ����
// using namespace std;�� �̿����� ����!
// cstdio�� ���ԵǾ������Ƿ� C ��Ÿ���� ǥ�� ����µ� ��� ����!
#include <iostream>

// ���α׷��� ������
// ��, ���α׷��� ���۵Ǵ� �κ�!
int main()
{
	system("title ����ȯ �����ϱ�");

	int num1 = 4;
	int num2 = 6;

	// int / int
	std::cout << "num1 / num2 = " << num1 / num2 << std::endl << std::endl;

	// (float)(int / int)
	std::cout << "(float)(num1 / num2) = " << static_cast<float>(num1 / num2)
		<< std::endl << std::endl;

	// (float)(int) / int
	std::cout << "(float)(num1) / num2 = " << static_cast<float>(num1) / num2
		<< std::endl << std::endl;

	// �ڵ� ���� ����!
	system("pause");

	// ���α׷��� ���������� ����ȴٴ� ���� �ǹ�
	// exit(EXIT_SUCCESS); �̰Ͱ� �����!
	return 0;
}