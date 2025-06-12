/*
*  ���ӿ��� ��ġ�� ǥ���ϴ� ��� (2D)
*  map 2���� �迭.
*  �̷� ã�� (maze), AI ���� Ż�ⱸ ���� �̵��ϴ� �ڵ带 �ۼ��ϼ���.
*/		  

#include <iostream>
#include <vector>
#include <Windows.h>

#define SIZE 10

// 0 �̵��� �� �ִ� ����, 1 ��
// �Ա��� (x,y) = (1, 0)
// �ⱸ�� (x,y) = (9, 5)
int maze[SIZE][SIZE] =
{
	{1,0,1,0,0,0,0,1,1,1},
	{1,0,1,1,1,0,1,1,0,1},
	{1,0,0,0,1,0,1,0,0,1},
	{1,0,1,0,0,0,0,0,0,1},
	{1,0,1,0,1,1,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0},
	{1,0,0,1,0,1,0,0,1,1},
	{1,0,0,1,0,0,0,1,0,0},
	{1,0,1,0,1,0,1,0,0,0},
	{1,0,0,0,0,1,0,0,0,0}
};

// maze[y][x] �� ���� 0�̸� '  ', 1�̸� '��' ǥ���ϴ� �ڵ带 ��������.

// ���� (��,��,��,��)
// �� : x �� ��ȭ? 0  y�Ǻ�ȭ ? -1
// �� : x �� ��ȭ? 0 y : 1
// �� : x -2 y 0

const int dx[4] = { 0,0,-2,2 };
const int dy[4] = { -1,1,0,0 };

struct Monster
{
	int x, y;
	int prev_x, prev_y;
	int step;
	std::vector<int> direction;

	Monster() = default;
	Monster(int x, int y, std::vector<int> direction) : x(x), y(y), direction(direction) 
	{
		prev_x = x;
		prev_y = y;
		step = 0;
	}
};

void GoToXY(int x, int y)
{
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

int main()
{
	// ���� �ݺ����� ����غ�����.

	for (int y=0; y < SIZE; y++)
	{
		for (int x =0; x < SIZE; x++)
		{
			if (maze[y][x] == 0)
			{
				std::cout << "  ";
			}				
			else if (maze[y][x] == 1)
			{
				std::cout << "��";
			}
		}
		std::cout << std::endl;
	}

#pragma region �̵��� ���� �̸� ����� �д�.
	//std::vector<int> direction = { 1,1,3,3,3,1,1,3,3,3,3,3,3};
	//int sx = 2; int sy = 0;	  // *2 (���δ� 2���� 1ĭ)
	//GoToXY(sx, sy);
	//std::cout << "��";
	//
	//// direction ���ڸ� �޾ƿͼ� GoToXY�� ��ǥ�� �����غ�����.
	//
	//int pre_x = sx;
	//int pre_y = sy;
	//
	//for (int i = 0; i < direction.size(); i++)
	//{
	//	// �ܻ��� ���� ������ �ذ��غ�����. system("cls")
	//	// pre_x, pre_y;     ���� ��ġ���� �����ϰ�, ���� ��ġ�� �� �������� �׸��� �ڵ�   
	//	// std::cout<< "  ";
	//
	//	GoToXY(pre_x, pre_y);
	//	std::cout << "  ";
	//
	//	int dir = direction[i];
	//	sx += dx[dir];
	//	sy += dy[dir];
	//	pre_x = sx;
	//	pre_y = sy;
	//	GoToXY(sx, sy);
	//	std::cout << "��";
	//	Sleep(500);
	//}


#pragma endregion

#pragma region ���� ���� �̵��ϴ� ����
	std::vector<int> path = { 1,1,3,3,3,1,1,3,3,3,3,3,3 };
	int monster_count = 5;
	int interval = 2;
	int steps = path.size() + monster_count + interval; // ��ü ������ �̵� �Ÿ�
	int sx = 2; int sy = 0;	  // *2 (���δ� 2���� 1ĭ)

	std::vector<Monster> monsters;

	for (int i = 0; i < steps; i++)
	{
		if (i % interval == 0 && monsters.size() < monster_count)
		{
			monsters.emplace_back(sx, sy, path);
		}
	}

	GoToXY(sx, sy);
	std::cout << "��";

	// direction ���ڸ� �޾ƿͼ� GoToXY�� ��ǥ�� �����غ�����.

	int pre_x = sx;
	int pre_y = sy;

	for (int i = 0; i < monsters.size(); i++)
	{
		Monster& monster = monsters[i];

		if (monster.step >= monster.direction.size()) continue;

		// �ܻ��� ���� ������ �ذ��غ�����. system("cls")
		// pre_x, pre_y;     ���� ��ġ���� �����ϰ�, ���� ��ġ�� �� �������� �׸��� �ڵ�   
		// std::cout<< "  ";

		GoToXY(monster.prev_x, monster.prev_y);
		std::cout << "  ";

		int dir = monster.direction[monster.step];
		monster.x += dx[dir];
		monster.y += dy[dir];
		monster.prev_x = monster.x;
		monster.prev_y = monster.y;
		monster.step++;


		GoToXY(monster.x, monster.y);
		std::cout << "��";
		Sleep(500);
	}
#pragma endregion

// 2. �������� ���Ͱ� ������ �������� �����̴� �ڵ带 �ۼ��غ�����. 


// 3. �ʿ� ���� ���������� �ڵ����� ã���ִ� �ڵ带 �ۼ��ϱ�(��ã�� ���� DFS,BFS) 

}


