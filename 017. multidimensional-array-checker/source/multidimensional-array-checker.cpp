/* 
 * multidimensional-array-checker.cpp
 *
 *       Copyright (c) Ruvendix. ��� ���۱��� ���ο��� �ֽ��ϴ�.
 *
 * �� ������ C++ ���� ���α׷��� Ʃ�丮���� ���� �����Դϴ�.
 * ��쿡 ���󼭴� C++11 �̻��� ���뵵 ���Ե� �� �ֽ��ϴ�.
 * ����� �� ������ ���� �ڵ� ���̵带 �����ϴ�.
 *
 * multidimensional-array-checker.cpp�� 2���� �迭�� üĿ���� ����մϴ�.
 * 2���� �迭�� 1���� �迭�� ���� �߰��� �����Դϴ�.
 * 2���� �迭�� ��� ���� �̿��ϹǷ� �簢�� ���°� ������
 * �װ� ������ ������ ���̰� �����δ� �׳� 1�����Դϴ�.
 * �޸� ������ �簢���� �ƴ϶� 1�����̶�� �� �� �˾Ƶμ���.
 */

// std::cout�� ����� �����ִ� ��� ����
#include <iomanip>

// ǥ�� ������� ���� C++�� ��� ����
// using namespace std;�� �̿����� ����!
#include <iostream>

// std::string�� ���� ��� ����
// string.h�� �ƴ϶� string��!
#include <string>

class CheckerBoard
{
public:
	void InitBoard()
	{
		// 2���� �迭�� ���� ������ ���ΰ�
		// �� ������ ���� ó���ؾ� ��!
		for (int row = 0; row < 8; ++row)
		{
			for (int col = 0; col < 8; ++col)
			{
				// ������׷� ����Ϸ��� �� + ���� ������ ��
				// �� + ���� ���ڰ� ���������� �����ϱ� ����!
				if ((row + col) % 2 == 0)
				{
					board_[row][col] = '*';
				}
				else
				{
					board_[row][col] = 'o';
				}
			}
		}
	}

	void PrintBoard()
	{
		for (int row = 0; row < 8; ++row)
		{
			for (int col = 0; col < 8; ++col)
			{
				std::cout << board_[row][col];
			}
			std::cout << std::endl;
		}
	}
protected:

private:
	char board_[8][8];
};

// ���α׷��� ������
// ��, ���α׷��� ���۵Ǵ� �κ�!
int main()
{
	system("title üĿ�� ����ϱ�");

	CheckerBoard checker_board;
	checker_board.InitBoard();
	checker_board.PrintBoard();

	// �ڵ� ���� ����!
	system("pause");

	// ���α׷��� ���������� ����ȴٴ� ���� �ǹ�
	// exit(EXIT_SUCCESS); �̰Ͱ� �����!
	return 0;
}