/*
 * battle-simulation.cpp
 *
 *       Copyright (c) Ruvendix. ��� ���۱��� ���ο��� �ֽ��ϴ�.
 *
 * �� ������ C++ ���� ���α׷��� Ʃ�丮���� ���� �����Դϴ�.
 * ��쿡 ���󼭴� C++11 �̻��� ���뵵 ���Ե� �� �ֽ��ϴ�.
 * ����� �� ������ ���� �ڵ� ���̵带 �����ϴ�.
 *
 * battle-simulation.cpp�� ������ ���� ��Ȳ�� �����غ��ϴ�.
 * �ݺ���, ���ù�, ���� ���� ���յ� �����̹Ƿ� ���ݱ����� ������ �� �˰� �־�� �մϴ�.
 * �ҽ� �ڵ带 ���� ����ġ�� �� �ƴ϶� �帧�� �����غ��鼭 �ۼ��غ�����.
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
	system("title ���� ��Ȳ ����");

	// �ΰ��� ����
	float human_hp = 250;
	float human_max_hp = human_hp;
	float human_attack = 0.6f;
	float human_damage = 200.0f;

	// �ذ��� ����
	float skeleton_hp = 250;
	float skeleton_max_hp = skeleton_hp;
	float skeleton_attack = 0.4f;
	float skeleton_damage = 150.0f;

	int num_of_human, max_num_of_human;
	int num_of_skeleton, max_num_of_skeleton;

	std::cout << "�ΰ��� ���� �Է��ϼ��� : ";
	std::cin >> num_of_human;
	max_num_of_human = num_of_human;
	std::cout << "�ΰ��� ���� " << num_of_human << "���� �����Ǿ����ϴ�.\n\n";

	std::cout << "�ذ��� ���� �Է��ϼ��� : ";
	std::cin >> num_of_skeleton;
	max_num_of_skeleton = num_of_skeleton;
	std::cout << "�ذ��� ���� " << num_of_skeleton << "���� �����Ǿ����ϴ�.\n\n";
	
	// ������ ���� ������
	std::default_random_engine random_generator(static_cast<unsigned>(time(nullptr)));
	std::uniform_real_distribution<float> attack_probability(0.0f, 1.0f);

	// ���� ���� Ȯ���� ���� ����
	float attack_result;

	// ���� �ڰ��� ������ ���� ����
	char turn = 'H';

	// �ΰ��� ���� �ذ��� ���� 0 �̻��� ���� ����!
	// ��� ������ �й��ϸ� �װɷ� ������ ����!
	while ((num_of_human > 0) &&
		(num_of_skeleton > 0))
	{
		// ���� Ȯ�� ���ϱ�
		attack_result = attack_probability(random_generator);

		if (turn == 'H')
		{
			if (attack_result <= human_attack)
			{
				skeleton_hp -= human_damage;

				if (skeleton_hp < 0)
				{
					// ���� �ذ� ����
					skeleton_hp = skeleton_max_hp;

					num_of_skeleton--;
				}
			}

			turn = 'S';
		}
		else
		{
			if (attack_result <= skeleton_attack)
			{
				human_hp -= skeleton_damage;

				if (human_hp < 0)
				{
					// ���� �ΰ� ����
					human_hp = human_max_hp;

					num_of_human--;
				}
			}

			turn = 'H';
		}
	}

	std::cout << "������ ����Ǿ����ϴ�!\n\n";
	std::cout << "���� ����� �����帮�ڽ��ϴ�.\n\n";
	
	// ���� �������� �̰�°�?
	if (num_of_human > 0)
	{
		std::cout << "<�ΰ��� �¸�!>\n";
	}
	else
	{
		std::cout << "<�ذ��� �¸�!>\n";
	}

	std::cout << "���� �ΰ��� �� : " << num_of_human << std::endl;
	std::cout << "���� �ذ��� �� : " << num_of_skeleton << std::endl;
	std::cout << "���� �ΰ��� �� : " << max_num_of_human - num_of_human << std::endl;
	std::cout << "���� �ذ��� �� : " << max_num_of_skeleton - num_of_skeleton << std::endl;

	// �ڵ� ���� ����!
	system("pause");

	// ���α׷��� ���������� ����ȴٴ� ���� �ǹ�
	// exit(EXIT_SUCCESS); �̰Ͱ� �����!
	return 0;
}