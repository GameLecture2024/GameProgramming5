/*
*   �ܼ� â ���� �����ϴ� ��ɵ�.
*   ANSI ESCAPE ������ ���� �����ϴ� ����� �����ϴ�.
*/

#include <iostream>
#include <Windows.h>
#include <InventoryDP.h>
#include <queue>
#include <string>
using namespace std;

/*
*  ��ǥ : ���ڷ� ǥ�⸦ �ϴ� ���� �ƴ϶�, ����� �˾ƺ��� ������ Ŭ���� ������.
*  Helper Ŭ����.	 
*  ex) Color::White , Color::BG_White, Color::UnderLine
*/

// 30 ~ 39 ���ڻ�,  40 ~ 44  ����

class Color
{
public:
	static const string	RESET;
	static const string	UNDERLINE;

	static const string BLACK, RED, GREEN, YELLOW, BLUE, MAGENTA, CYAN, WHITE;
	static const string BG_RED, BG_GREEN, BG_YELLOW, BG_BLUE, BG_MAGENTA, BG_CYAN, BG_WHITE, BG_BLACK;

	static void Print(const string& BG, const string& textColor, const string& message)
	{
		cout << BG << textColor << message << Color::RESET;
	}
};

const string Color::RESET = "\033[0m";
const string Color::UNDERLINE = "\033[4m";
const string Color::BLACK = "\033[30m";
const string Color::RED   = "\033[31m";
const string Color::GREEN = "\033[32m";
const string Color::YELLOW = "\033[33m";
const string Color::BLUE = "\033[34m";
const string Color::MAGENTA = "\033[35m";
const string Color::CYAN = "\033[36m";
const string Color::WHITE = "\033[37m";

const string Color::BG_RED = "\033[41m";
const string Color::BG_GREEN = "\033[42m";
const string Color::BG_YELLOW = "\033[43m";
const string Color::BG_BLUE = "\033[44m";
const string Color::BG_MAGENTA = "\033[45m";
const string Color::BG_CYAN = "\033[46m";
const string Color::BG_WHITE = "\033[47m";
const string Color::BG_BLACK = "";

void PrintMenu()
{
	cout << "=====  �޴� =====" << endl;

	
	Color::Print(Color::BG_BLACK, Color::GREEN, "1. ");
	cout << "���ο� ����" << endl;
	cout << Color::WHITE << "2. " << Color::RESET << "�ҷ�����" << endl;
	cout << Color::WHITE << "3. " << Color::RESET << "����" << endl;
	cout << Color::WHITE << "4. " << Color::RESET << "����" << endl;
}

void PrintProgressBar(int current, int total, int width = 30)
{
	float progress = (float)current / total;
	int filled = (int)(width * progress);

	for (int i = 0; i < filled; i++)
	{
		cout << Color::GREEN << "��";
	}

	for (int i = filled; i < width; i++)
	{
		cout << Color::WHITE << "��";
	}

	cout << Color::RESET << (int)(progress * 100) << "%";
}

void LoadingAnimation()
{
	const int total = 3;
	const int width = 30;

	cout << "�ε� ���� ��Ȳ�� �׷��ش�." << endl;
	for (int i = 0; i <= total; i++)
	{
		system("cls");
		PrintProgressBar(i, total, width);
		cout.flush();
		Sleep(50);
	}

	// vector�ڷᱸ���� ������Ȳ�� �׸����� ������ �ߴٰ� ������ �ϴ� ���.
}

void DrawBox(int width, int height)	// ����, ����
{
	/*
	*  ���ڴ� ��, �߰�, �Ʒ� �κ����� ������ �˴ϴ�.
	*  �ݺ����� �̿��ؼ� ǥ���غ�����.
	*/

	// �Ӹ�
	cout << Color::BG_CYAN << "+";
	for (int i = 0; i < width; i++)
	{
		cout << "-";
	}
	cout <<	"+" << Color::RESET << endl;


	for (int y = 0; y < height; y++)
	{
		// ���� ��
		Color::Print(Color::BG_CYAN, Color::WHITE, "|");

	    // ����
		for (int i = 0; i < width; i++)
		{
			cout << " ";
		}
		// ������ ��
		Color::Print(Color::BG_CYAN, Color::WHITE, "|");
		cout << endl;
	}

	// �ٴ�
	cout << Color::BG_CYAN << "+";
	for (int i = 0; i < width; i++)
	{
		cout << "-";
	}
	cout << "+" << Color::RESET << endl;
}

/*
*  gotoXY(int x, int y)
*/

void gotoXY(int x, int y)
{
	COORD pos{ x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

/*
*  DrawBox�� ���� ���ϴ� ��ǥ�� �׸� �� �ֵ��� �Ʒ� �Լ��� �����غ�����.
*  gotoXY�� �̿��ϼ���. ž, ����, �ٴ�
*/

// ���� �׸��� + ��ġ �̵� ��ģ��. => �־��� �ڷḦ ���ϴ� ��ġ�� ���� ���·� ����ϴ� UI �����.

void DrawBox(int px, int py, int width, int height, const ItemW& item)	// ����, ����
{
	/*
	*  ���ڴ� ��, �߰�, �Ʒ� �κ����� ������ �˴ϴ�.
	*  �ݺ����� �̿��ؼ� ǥ���غ�����.
	*/

	// �Ӹ�
	gotoXY(px, py);
	cout << Color::BG_CYAN << "+";
	for (int i = 0; i < width; i++)
	{
		cout << "-";
	}
	cout << "+" << Color::RESET << endl;


	for (int y = 0; y < height; y++)
	{
		gotoXY(px, py + 1 + y);
		// ���� ��
		Color::Print(Color::BG_CYAN, Color::WHITE, "|");

		// item�� ������ ���
		string content = "";

		if (y == 1)
		{
			content = "�̸� : " + item.GetName();
		}
		else if (y == 2)
		{
			content = "���� : " + to_string(item.GetWeight());
		}
		else if (y == 3)
		{
			content = "��ġ : " + to_string(item.GetValue());
		}
		
		if (!content.empty())
		{
			cout << Color::CYAN << content;

			for (int i = content.length(); i < width; i++)
			{
				cout << " ";
			}
		}
		else
		{
			// ����
			for (int i = 0; i < width; i++)
			{
				cout << " ";
			}
		}
	
		// ������ ��
		Color::Print(Color::BG_CYAN, Color::WHITE, "|");
		cout << endl;
	}

	// �ٴ�
	gotoXY(px, py + height + 1);
	cout << Color::BG_CYAN << "+";
	for (int i = 0; i < width; i++)
	{
		cout << "-";
	}
	cout << "+" << Color::RESET << endl;
}


void TestI(const ItemW& item)
{
	cout << item.GetName() << endl;
}

void ProcedualDrawBox(int startX, int startY, std::vector<ItemW>& items)
{
	queue<ItemW> itemQueue;

	for (auto& item : items)
	{
		itemQueue.push(item);
	}



	// ctrl + R + R
	int currentRow = 0; // ���� �׷����� ������ X��ǥ
	int currentCol = 0; // ���� �׷����� ������ Y��ǥ

	const int Box_Width = 20;
	const int Box_Height = 10;
	const int Box_RowSpacing = 5;
	const int Box_ColSpacing = 5;

	// 3 * 3
	while (!itemQueue.empty())
	{
		ItemW currentItem = itemQueue.front();
		itemQueue.pop();
		// ItemW Ÿ���� ����ϴ� �Լ��� ��������.

		int boxX = startX + (currentRow * (Box_RowSpacing + Box_Width));
		int boxY = startY + (currentCol * (Box_ColSpacing + Box_Height));

		// ��ǥ�� �������ִ� �ڵ带 �ۼ��ϼ���. 3x3 �ڽ��� �������� �׷������� �ڵ带 ��������.

		DrawBox(boxX, boxY, Box_Width, Box_Height, currentItem);

		currentRow++; // 0 ,1 , 2
		if (currentRow >= 3)
		{
			currentRow = 0;
			currentCol++;
		}

		Sleep(100);
	}
}

int main()
{
	cout << "\033[47m" <<  "����" <<"\033[0m" << endl;
	cout << "\033[46m" << "����" << "\033[0m" << endl;
	cout << "\033[4m" << "����" << "\033[0m" << endl;

	// ����� ���ڿ� ������ �׾��� ����

	cout << Color::BG_BLUE << Color::GREEN << "==== TITLE ====" << Color::RESET << endl;

	Color::Print(Color::BG_BLUE, Color::GREEN, "==== TITLE ====");

	// �ε���, �޴� ǥ�� , UIǥ��

	PrintMenu();
	// ���� - ColorŬ������ ����ؼ� 
	// 1. ���� ���� 
	// 2. ���� ����
	
	LoadingAnimation();
	//system("cls");

	InventoryW inventory(7);

	// 6, 4, 3, 5
	// 13,8, 6, 12
	ItemW A("A", 6, 13);
	ItemW B("B", 4, 8);
	ItemW C("C", 3, 6);
	ItemW D("D", 5, 12);

	std::vector<ItemW> selectableTable{ A,B,C,D };

	std::pair<int, std::vector<ItemW>> bestitems = inventory.findBestItem(7, selectableTable);

	std::cout << "�־��� �������� �ִ� ��ġ :" << bestitems.first << std::endl;
	std::vector<ItemW> ItemC = bestitems.second;

	ProcedualDrawBox(5,5, ItemC);
}