/*
 * variables.cpp
 *
 *       Copyright (c) Ruvendix. ��� ���۱��� ���ο��� �ֽ��ϴ�.
 *
 * �� ������ C++ ���� ���α׷��� Ʃ�丮���� ���� �����Դϴ�.
 * ��쿡 ���󼭴� C++11 �̻��� ���뵵 ���Ե� �� �ֽ��ϴ�.
 * ����� �� ������ ���� �ڵ� ���̵带 �����ϴ�.
 *
 * variables.cpp�� �⺻ �ڷ����� int, float, double�� ����մϴ�.
 * double�� float���� �� ���е��� ������ ������ float�� ����ص� �������ϴ�.
 * float�� ����ϱ� �������� double�� ����ϼŵ� �˴ϴ�.
 *
 */

// ������ �Ǽ��� ��� ������ ��
// �ش�Ǵ� ��� ������� �ʴ� �ڵ�
// ���α׷��� �Ը� Ŀ���� ������� ����ٸ�
// �� �ڵ带 �� Ȱ���ؾ� ��!
//#pragma warning(disable:4244)

// ǥ�� ������� ���� C++�� ��� ����
// using namespace std;�� �̿����� ����!
// ��а��� printf() ��� std::cout�� ����ϰ���!
#include <iostream>

// ���α׷��� ������
// ��, ���α׷��� ���۵Ǵ� �κ�!
int main()
{
	// int�� �⺻ �ڷ��� �� ����!
	// �Ҽ����� ������� �ʴ´ٸ�
	// ������ ������ ���ڴ� int�� �̿�!
	int zombies = 300; // zombies��� ������ 300�� �ְڴ�!��� ��
	std::cout << "���� ������ �� : " << zombies << std::endl;

	zombies = 200; // zombies�� �̷��� �� ���浵 ����!
	std::cout << "���� ������ �� : " << zombies << std::endl;

	zombies = 200 + 50; // +�� ������ ������ ����!
	std::cout << "���� ������ �� : " << zombies << std::endl << std::endl;

	// float�� �⺻ �ڷ��� �� �Ǽ�!
	// �Ҽ��� �ܰ���� ���ڰ� �����ؾ� �Ѵٸ�
	// float�̳� double�� �̿�!
	// ���� ���� �Ǵ� ���� ����� �ٷ�� ��
	// �ƴ϶�� ��а��� float���ε� ���!
	float plants = 200.8f; // f�� float���̴�!��� �˸��� ��!
	std::cout << "���� �Ĺ��� �� : " << plants << std::endl << std::endl;

	float small_plants = 200.0f;
	float big_plants   = 200.0f;

	// *�� ������ ���ϱ�� ����! 0�� ���ϸ� ������ 0�� ��!
	std::cout << "���� �Ĺ��� �� : " << small_plants * big_plants << std::endl;

	// /�� ������ �������� ����! big_plants�� 0�̶�� ������ ���� �߻�!
	// �׷��Ƿ� big_plants ��ġ�� 0�� �ִ� �Ǽ��� ������ ����!
	std::cout << "���� �Ĺ��� �� : " << small_plants / big_plants << std::endl << std::endl;

	// �Ұ�ȣ�� ���� �۾��� ó���϶�� ǥ��!
	float plants_damage = (small_plants + big_plants) * 8.0f;

	// ������ �Ǽ��� ������ ���ذ� �߻�������
	// ũ�� �Ű� �� �ʿ�� ����!
	// ��� �ߴ� �� ��������
	// #pragma warning(disable:4244)�� �� ���� �Է�!
	float zombies_health = static_cast<float>(zombies * 20);

	std::cout << "���� �Ĺ����� ���ط� : " << plants_damage << std::endl;
	std::cout << "���� ������� ����� : " << zombies_health << std::endl << std::endl;
	std::cout << "�Ĺ����� ������� ������ �����Ѵ�!" << std::endl << std::endl;

	// ������� ��ȭ�� ����� = ������� ���� ����� - �Ĺ����� ���ط�
	zombies_health = zombies_health - plants_damage;
	
	std::cout << "���� ������� ����� : " << zombies_health << std::endl;

	// �ڵ� ���� ����!
	system("pause");

	// ���α׷��� ���������� ����ȴٴ� ���� �ǹ�
	// exit(EXIT_SUCCESS); �̰Ͱ� �����!
	return 0;
}