/*
 * static-variable-reference.cpp
 * 
 *       Copyright (c) Ruvendix. ��� ���۱��� ���ο��� �ֽ��ϴ�.
 *
 * �� ������ C++ ���� ���α׷��� Ʃ�丮���� ���� �����Դϴ�.
 * ��쿡 ���󼭴� C++11 �̻��� ���뵵 ���Ե� �� �ֽ��ϴ�.
 * ����� �� ������ ���� �ڵ� ���̵带 �����ϴ�.
 *
 * static-variable-reference.cpp�� ���� ������ �����ڿ� ���� �˾ƺ��ϴ�.
 * ���� ������ �Լ� �ȿ��� ���Ǹ� ���� ������ �������� �� ���� �ʱ�ȭ�˴ϴ�.
 * ���Ŀ� ��� �Լ��� ȣ���ϰ� �Ǹ� ���� ������ �������� ��� ���ŵ˴ϴ�.
 * �����ڴ� ���ڸ� �����ؼ� �Ű������� �ѱ�� �� �ƴ϶� ������ ������ �ѱ�ϴ�.
 * ���� �Ű������� �����ϸ� ���ڵ� ���� �����˴ϴ�.
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

// �Լ��� ���� ���� ����
void StartGame();
int InputNum(std::string object_name);
void SimulateBattle(int &humans, int &skeletons);
void ShowGameResult(int humans, int max_humans, int skeletons, int max_skeletons);

void CountNum();
void AddNum(int &num); // �����ڴ� &�� ����

// ���α׷��� ������
// ��, ���α׷��� ���۵Ǵ� �κ�!
int main()
{
	//// ó������ 10
	//CountNum();
	//
	//// �� ��°���� 11
	//CountNum();

	//// �� ��°���� 12
	//CountNum();

	//int num = 10;

	//// ó������ 11
	//AddNum(num);

	//// �� ��°���� 12
	//AddNum(num);

	//// �� ��°���� 13
	//AddNum(num);

	system("title ���� ��Ȳ ����");

	// ������ �����ϴ� �Լ�
	StartGame();

	// �ڵ� ���� ����!
	system("pause");

	// ���α׷��� ���������� ����ȴٴ� ���� �ǹ�
	// exit(EXIT_SUCCESS); �̰Ͱ� �����!
	return 0;
}

void StartGame()
{
	int num_of_human, max_num_of_human;
	int num_of_skeleton, max_num_of_skeleton;

	// �ΰ��� ���� �Է¹޴� �Լ�
	max_num_of_human = num_of_human = InputNum("�ΰ�");

	// �ذ��� ���� �Է¹޴� �Լ�
	max_num_of_skeleton = num_of_skeleton = InputNum("�ذ�");

	std::cout << "������ �����մϴ�!\n\n";
	SimulateBattle(num_of_human, num_of_skeleton);
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

	ShowGameResult(num_of_human, max_num_of_human, num_of_skeleton, max_num_of_skeleton);
}

// �ΰ�, �ذ��� ���� �Է¹޴� �Լ��� ����
// ���� �� �Լ��� �̿��ϸ� ����, �̶� � ��� ����!
int InputNum(std::string object_name)
{
	int num_of_object;
	std::cout << object_name << "�� ���� �Է��ϼ��� : ";
	std::cin >> num_of_object;
	std::cout << object_name << "�� ���� " << num_of_object << "���� �����Ǿ����ϴ�.\n\n";
	return num_of_object;
}

void SimulateBattle(int &humans, int &skeletons)
{
	// �ΰ��� ����
	float human_hp = 250.0f;
	float human_max_hp = human_hp;
	float human_attack = 0.6f;
	float human_damage = 200.0f;

	// �ذ��� ����
	float skeleton_hp = 100.0f;
	float skeleton_max_hp = skeleton_hp;
	float skeleton_attack = 0.4f;
	float skeleton_damage = 150.0f;

	// ������ ���� ������
	// ������ ���ǿ��� �ο� �� �ֵ��� static���� ���� �߻��⸦ ����
	// �ֳ��ϸ� �õ尪�� �ð��� �ʸ��� ��� ����ǹǷ� ���� �߻��� ������ �޶����� ����
	static std::default_random_engine random_generator(static_cast<unsigned>(time(nullptr)));
	std::uniform_real_distribution<float> attack_probability(0.0f, 1.0f);

	// ���� ���� Ȯ���� ���� ����
	float attack_result;

	// ���� �ڰ��� ������ ���� ����
	char turn = 'H';

	std::cout << "<<<������! ìì! ���ƾƾ�! �ٿ�������!>>>\n\n";

	// �ΰ��� ���� �ذ��� ���� 0 �̻��� ���� ����!
	// ��� ������ �й��ϸ� �װɷ� ������ ����!
	while ((humans > 0) &&
		(skeletons > 0))
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

					skeletons--;
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

					humans--;
				}
			}

			turn = 'H';
		}
	}
}

// �Ű������� ���ڴ� �̸��� �޶� ��!
void ShowGameResult(int humans, int max_humans, int skeletons, int max_skeletons)
{
	std::cout << "���� �ΰ��� �� : " << humans << std::endl;
	std::cout << "���� �ذ��� �� : " << skeletons << std::endl;
	std::cout << "���� �ΰ��� �� : " << max_humans - humans << std::endl;
	std::cout << "���� �ذ��� �� : " << max_skeletons - skeletons << std::endl;
}

void CountNum()
{
	static int num = 10;
	std::cout << "num�� �� : " << num << std::endl;
	num++; // num�� 10���� ��� ����!
}

void AddNum(int &num)
{
	num++; // �̷��� �������� �����!
	std::cout << "num�� �� : " << num << std::endl;
}