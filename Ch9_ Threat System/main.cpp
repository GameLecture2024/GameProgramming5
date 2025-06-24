/*
*  RPG����. �������̵�.  5����Ƽ. [����, ����, �ü�, ������, ������]
*  ������ �������� ��ų�� ����� �� ���� ���� ��׷ΰ� �����մϴ�.
*  �� 5���� ���� ���� ���� ������ �켱������ �����ϴ��� ã�� ������ �ۼ��غ�����.
*  �̶�, ������ Ư�� ������ ������ �� ���� �� ������ ��׷δ� 0���� �ʱ�ȭ�� �˴ϴ�.
* 		     1��   2��  3��  4��  5��
*  ����   :  10    5	   8     7   6    ( �����ϰų�, �������� ��ų�� ���� �� ��ġ�� ����)
*  ���� 	  :
*  �ü�	  :
*  ������ :
*  ������ :
*
*  [������ ��ų�� �����ϴ� ����]
*  ���� :  ��Ƽ�ȿ��� ���� ���� �������ΰ�?,  ���� ���� �� �������ΰ�?
*
*  (1) n���� ���� ���� �켱������ �� ���� ū ������ ����Ѵ�.
*  (2) Heap �ڷᱸ���� ����ؼ� k��° ������ ã�´�.
*
*  - ������ ������ �������� 1�� ����� ȿ�����̴�.
*  - 2���� ����ؾ��ϴ� ������ ã�ƾ��� �켱 ���� ����� ������ �������� 2�� ����� ȿ�����̴�.
*/

#include <iostream>
#include <vector>
#include <queue>	 // queue, priority_queue  
#include <utility>   // pair

using namespace std;

// ����, ������, �ü�, ����, ������
// ����   :  10    5	   8     7   6  
class Character
{
private:
	string name;
	vector<int> threatLevel;   // threatLevel {10,5,8,7,6}

	int currentTurn;
public:
	Character(string name, vector<int> TL) : name(name), threatLevel(TL), currentTurn(0) {}

	int getCurrentThreat()
	{
		if (threatLevel.size() <= currentTurn)
		{
			throw runtime_error("Out of Range");
		}
		return threatLevel[currentTurn];
	}

	void NextTurn()
	{
		currentTurn++;
	}

	void PrintStat()
	{
		cout << name << "(���� ������ : " << getCurrentThreat() << ")" << std::endl;
	}
};

class Boss
{
public:
	string name;
	int currentTurn;
	priority_queue<int> threatQueue;       // priority_queue<int, int> TQ; 
	Boss(string name) : currentTurn(0) {}

	void clear()
	{
		while (!threatQueue.empty())
		{
			threatQueue.pop();
		}
	}

	void UpdateThreatQueue(vector<Character>& party)
	{
		clear();

		for (auto& character : party)
		{
			int threat = character.getCurrentThreat();
			threatQueue.push(threat);
			character.NextTurn();     // ��Ƽ�� ��� ĳ������ ���� 1 ������Ų��.
		}							 // �������� ���� ū���� ����.
	}

	int FindMostThreatCharacter(vector<Character>& party)
	{
		//Character* target = nullptr;

		int MostThreatValue = threatQueue.top();		
		return MostThreatValue;
	}

	void Attack()
	{
		// target = FindTarget();
		// character.TakeDamage(); 
	}
};


// maxHeap , minHeap
// 1�� �켱���� ť�� �̿��ؼ� �������� �ۼ��غ��ô�.

bool myLess(int a, int b)
{
	return a < b;
}

bool myGreater(int a, int b)
{
	return a > b;
}

// k��°�� ���� �� ���ϱ�, k��°�� ū �� ���ϱ� �켱���� ť�� ����ϸ� ���� ǥ���� �� �ִ�.
// logN �ð����� k ��° ���� ���� ã�� �� �ִ�. => (k��° ���� ã�´�, 1:1���� N�ð����� �ڵ带 �ۼ��ϸ� �ð��� �ʰ��߽��ϴ�.)

class MinHeap // ���� ���� ���� ���� ���� �ִ� ����. 
{
private:
	priority_queue<int, vector<int>, less<int>> pq; // �ּҰ��� ���� ���� �ö󰡴� ����
	
public:
	MinHeap() = default;

	// push, pop, empty, top (<=extractMax)
	void push(int value) 
	{
		pq.push(value);
	}
	bool isEmpty() const
	{
		return pq.empty();
	}

	const int& top() const// ����Ǿ��ִ� ���� ���� ���� �����Ѵ�.
	{
		if (isEmpty())
		{
			throw runtime_error("Priority Queue is Empty!");
		}

		return pq.top();
	}

	int pop() 
	{
		if (isEmpty())
		{
			throw runtime_error("Priority Queue is Empty!");
		}
		int minValue = pq.top();
		pq.pop();
		return minValue;
	}    // ���縦 �� �Ŀ�, �ڷᱸ������ ����
};

void FindkthExample()
{
	MinHeap myHeap;

	myHeap.push(11);
	myHeap.push(7);
	myHeap.push(5);
	myHeap.push(3);

	std::cout << "�ּ� ���� ���� �� : " << myHeap.top() << std::endl;

	int k = 3;
	// ??

	// for �ݺ����� k�� ǥ���Ͽ� k��° ���� ã�ƺ�����.

	std::cout << "k��° ���� ���� ����ϼ��� : " << std::endl;

	//MaxHeap mMaxHeap;
}

void ThreatSystem()
{
   // 1. ���� ĳ������ �������� ����ϼ���.

	Character a("����", { 1,2,3,4,5 });
	Character b("����", { 1,1,1,10,5 });
	Character c("�ü�", { 3,6,3,3,3 });
	Character d("������", { 0,1,6,6,6 });
	Character e("������", { 0,0,10,0,20 });

	std::vector<Character> party;

	party.push_back(a);
	party.push_back(b);
	party.push_back(c);
	party.push_back(d);
	party.push_back(e);

	for (auto& character : party)
	{
		character.PrintStat();
	}

	/// ������ ���� �������� ���� ���ڸ� ã���� �غ�����.
	Boss boss("ŷ���");
	boss.UpdateThreatQueue(party);	 // ù��° ��
	int value = boss.FindMostThreatCharacter(party);
	std::cout << "ù��° �Ͽ��� �������� ���� ū ��ġ : " << value << std::endl;

	boss.UpdateThreatQueue(party);	 // �ι�° ��
	value = boss.FindMostThreatCharacter(party);
	std::cout << "�ι�° �Ͽ��� �������� ���� ū ��ġ : " << value << std::endl;

	int nextTurnValue = 3;
	// ���縸 3��° �� ���� ������ �������� ����غ�����.
	int currentThreat = 0;
	for (int i = 0; i < nextTurnValue; i++)
	{
		currentThreat += a.getCurrentThreat();
		a.NextTurn();
	}

	cout << "===������ 3�� �� ������ : " << currentThreat <<  std::endl;

	// n��° ���� �� �� ������ �������� ����� �Ϸ��� ��� �ϸ� �ɱ�?
	// �� �Ͽ� �������� ���� �������� ���ؼ� �߰��غ�����.

}

int main()
{
	//FindkthExample();
	ThreatSystem();
}