/*
 * random.cpp
 *
 *       Copyright (c) Ruvendix. ��� ���۱��� ���ο��� �ֽ��ϴ�.
 *
 * �� ������ C++ ���� ���α׷��� Ʃ�丮���� ���� �����Դϴ�.
 * ��쿡 ���󼭴� C++11 �̻��� ���뵵 ���Ե� �� �ֽ��ϴ�.
 * ����� �� ������ ���� �ڵ� ���̵带 �����ϴ�.
 *
 * random.cpp�� ���� �߻��⸦ �ٷ�ϴ�.
 * ���ӿ��� ������ ���� �ʼ����̹Ƿ� �� �˾Ƶμ���.
 * rand(), srand()�� �ƴ϶� random Ŭ������ �̿��մϴ�.
 * std::default_random_engine�� std::uniform_int_distribution�� �̿��մϴ�.
 * 
 */

// std::cout�� ����� �����ִ� ��� ����
#include <iomanip>

// ǥ�� ������� ���� C++�� ��� ����
// using namespace std;�� �̿����� ����!
#include <iostream>

// C++11 ���ĺ��� �߰��� ���� �߻��� ���� ��� ����
// �� ��� ������ �־�� ���� �߻��⸦ ����� �� ����!
#include <random>

// std::string�� ���� ��� ����
// string.h�� �ƴ϶� string��!
#include <string>

// ���� �߻����� ����(�õ�)�� ���� �ð� ���� ��� ����
#include <ctime>

// ���α׷��� ������
// ��, ���α׷��� ���۵Ǵ� �κ�!
int main()
{
	// ������ �� �� �ֵ��� �����ִ� ��
	// default_random_engine�� mt19937�� ����!
	// ���� ���ĸ� �׳� ������ ���ϴ� �����̶�� ���� ��!
	// �ð��� ������ ���ϴ� ��! ���� ������ ���� �߻��⸦ ���� �� ����!
	std::default_random_engine random_generator(time(nullptr));

	// �ּڰ����� �ִ񰪱����� ������ �� �ִ� ��
	// �̸��� �����ֵ��� ������ �ڷ����� ������ �� ����!
	// <> �ȿ� ����ϰ��� �� ������ �ڷ����� �Է��ϸ� ��!
	std::uniform_int_distribution<int> probability(1, 100);
	
	// �Ʒ��� �ִ� ī��� ��ġ�Ƿ� ���⼭�� Ƚ���� ����!
	for (int i = 0; i < 3; ++i)
	{
		std::cout << "��� : " << probability(random_generator) << std::endl;
		system("pause");
		std::cout << std::endl;
	}

	/* ���� �߻��⸦ �̿��� ī�� �̱�(��í��� ����~) */
	std::default_random_engine card_random_generator(time(nullptr));
	
	// �������� �ƴ� �Ǽ����� ����!
	// �Ǽ��� Ȯ���� ������ ����
	std::uniform_real_distribution<float> card_probability(0.0000f, 1.0000f);

	// ī�� �̱�
	float result;
	int cash = 0;
	std::cout.precision(4); // �Ҽ��� ǥ�� ���� 4���� ����
	std::cout << std::fixed; // �Ҽ��� ���� ǥ��
	for (bool is_finish = false; is_finish == false;)
	{
		result = card_probability(card_random_generator);
		std::cout << "������� �� �� : " << cash << std::endl;
		std::cout << "���� Ȯ��      : " << result << std::endl;
		if (result <= 0.0005f) // ����� Ȯ��
		{
			std::cout << "1��� ī�带 �����̽��ϴ�!\n";
			//is_finish = true;
			//system("pause");
		} 
		else if (result <= 0.0100f) // �� ����� Ȯ��
		{
			std::cout << "2��� ī�带 �����̽��ϴ�!\n";
			//is_finish = true;
			//system("pause");
		}
		else if (result <= 0.0500f) // ������ Ȯ��
		{
			std::cout << "3��� ī�带 �����̽��ϴ�!\n";
		}
		else if (result <= 0.1000f) // ���� Ȯ��
		{
			std::cout << "4��� ī�带 �����̽��ϴ�!\n";
		}
		else if (result <= 0.9999f) // ������ ���� Ȯ��
		{
			std::cout << "5��� ī�带 �����̽��ϴ�!\n";
		}
		cash += 5000; // 5õ��
		system("pause");
		system("cls");
	}
	
	// �ڵ� ���� ����!
	system("pause");

	// ���α׷��� ���������� ����ȴٴ� ���� �ǹ�
	// exit(EXIT_SUCCESS); �̰Ͱ� �����!
	return 0;
}