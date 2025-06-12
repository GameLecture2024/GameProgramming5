/*
*  게임에서 위치를 표현하는 방법 (2D)
*  map 2차원 배열.
*  미로 찾기 (maze), AI 존재 탈출구 까지 이동하는 코드를 작성하세요.
*/		  

#include <iostream>
#include <vector>
#include <Windows.h>

#define SIZE 10

// 0 이동할 수 있는 공간, 1 벽
// 입구를 (x,y) = (1, 0)
// 출구는 (x,y) = (9, 5)
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

// maze[y][x] 의 값이 0이면 '  ', 1이면 '■' 표현하는 코드를 만들어보세요.

// 방향 (상,하,좌,우)
// 상 : x 의 변화? 0  y의변화 ? -1
// 하 : x 의 변화? 0 y : 1
// 좌 : x -2 y 0

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
	// 이중 반복문을 사용해보세요.

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
				std::cout << "■";
			}
		}
		std::cout << std::endl;
	}

#pragma region 이동할 길을 미리 만들어 둔다.
	//std::vector<int> direction = { 1,1,3,3,3,1,1,3,3,3,3,3,3};
	//int sx = 2; int sy = 0;	  // *2 (가로는 2개가 1칸)
	//GoToXY(sx, sy);
	//std::cout << "☆";
	//
	//// direction 숫자를 받아와서 GoToXY의 좌표를 변경해보세요.
	//
	//int pre_x = sx;
	//int pre_y = sy;
	//
	//for (int i = 0; i < direction.size(); i++)
	//{
	//	// 잔상이 남는 현상을 해결해보세요. system("cls")
	//	// pre_x, pre_y;     이전 위치값을 저장하고, 이전 위치를 빈 공간으로 그리는 코드   
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
	//	std::cout << "☆";
	//	Sleep(500);
	//}


#pragma endregion

#pragma region 길을 따라 이동하는 몬스터
	std::vector<int> path = { 1,1,3,3,3,1,1,3,3,3,3,3,3 };
	int monster_count = 5;
	int interval = 2;
	int steps = path.size() + monster_count + interval; // 전체 몬스터의 이동 거리
	int sx = 2; int sy = 0;	  // *2 (가로는 2개가 1칸)

	std::vector<Monster> monsters;

	for (int i = 0; i < steps; i++)
	{
		if (i % interval == 0 && monsters.size() < monster_count)
		{
			monsters.emplace_back(sx, sy, path);
		}
	}

	GoToXY(sx, sy);
	std::cout << "☆";

	// direction 숫자를 받아와서 GoToXY의 좌표를 변경해보세요.

	int pre_x = sx;
	int pre_y = sy;

	for (int i = 0; i < monsters.size(); i++)
	{
		Monster& monster = monsters[i];

		if (monster.step >= monster.direction.size()) continue;

		// 잔상이 남는 현상을 해결해보세요. system("cls")
		// pre_x, pre_y;     이전 위치값을 저장하고, 이전 위치를 빈 공간으로 그리는 코드   
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
		std::cout << "☆";
		Sleep(500);
	}
#pragma endregion

// 2. 여러가지 몬스터가 각자의 방향으로 움직이는 코드를 작성해보세요. 


// 3. 맵에 따라서 도착지점을 자동으로 찾아주는 코드를 작성하기(길찾기 문제 DFS,BFS) 

}


