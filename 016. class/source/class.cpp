/*
 * class.cpp
 *
 *       Copyright (c) Ruvendix. ��� ���۱��� ���ο��� �ֽ��ϴ�.
 *
 * �� ������ C++ ���� ���α׷��� Ʃ�丮���� ���� �����Դϴ�.
 * ��쿡 ���󼭴� C++11 �̻��� ���뵵 ���Ե� �� �ֽ��ϴ�.
 * ����� �� ������ ���� �ڵ� ���̵带 �����ϴ�.
 *
 * class.cpp�� Ŭ������ ���� ������ �˾ƺ��ϴ�.
 * Ŭ������ ��ü�� ������ ����� �ϳ��� ���� �����̶�� �����Ͻø� �˴ϴ�.
 * ���� ��ư� �м��� �ʿ� ���� �׳� �����ϰԸ� �˾ƺ��Կ�.
 */

// std::cout�� ����� �����ִ� ��� ����
#include <iomanip>

// ǥ�� ������� ���� C++�� ��� ����
// using namespace std;�� �̿����� ����!
#include <iostream>

// std::string�� ���� ��� ����
// string.h�� �ƴ϶� string��!
#include <string>

// �̰� �ٷ� Ŭ����
// Ŭ�������� ���� �����ڰ� �ִ�!
// public    => �ܺο����� ���� ����
// protected => ��� ���迡�� ���� ����
// private   => �ܺο��� ���� �Ұ���
class Monster
{
public:
	// Ŭ������ �޼���(��� �Լ�)��
	// public���� ����� ��찡 ����!
	void Growl()
	{
		std::cout << "ũ�ƾ�!\n";
	}

	void set_name(const std::string &name)
	{
		name_ = name;
	}

	std::string get_name()
	{
		return name_;
	}
protected:

private:
	// std::string�� Ŭ����!
	// Ŭ������ �ʵ�(��� ����)���� _�� ����!
	std::string name_;
}; // ���� �ֹ��� �ʼ�!

// ���α׷��� ������
// ��, ���α׷��� ���۵Ǵ� �κ�!
int main()
{
	system("title Ŭ���� �����ϱ�");

	// Ŭ������ ��ü�� ������ ���� �̷��� �ؾ� ��
	Monster monster;

	//monster.name_; // �׳��� ���� �Ұ���!
	monster.set_name("�ط���"); // �̷��� �����ؾ� ��!

	// ��ü�� �����ϸ� �޼���� .�� �̿��ؼ� ȣ��!
	std::cout << "������ �̸� : " << monster.get_name() << std::endl;
	monster.Growl();

	// �ڵ� ���� ����!
	system("pause");

	// ���α׷��� ���������� ����ȴٴ� ���� �ǹ�
	// exit(EXIT_SUCCESS); �̰Ͱ� �����!
	return 0;
}