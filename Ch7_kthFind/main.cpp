/*
*  �˰��� ��ǥ ����
*  - ���� �����ϰ� Ž���ϱ�
*  - �ܼ��� ���. �����͸� ���Ľ�Ų��.
*  - k��° ������? ���ʺ��� �ϳ��� ���
*  - k��° ū��?   �����ʺ��� �ϳ��� ���
*/

// ����ȯ�� ������ �����ص帳�ϴ�. vector<int>
// ���� �����ؾ��ϴ� ȯ�ڰ� 1������ �����մϴ�.

// Ʈ���� ���� ����� �����ؼ� ���� ū���� ã�� ���¸� �����ϸ�
// ���?

#include <iostream>
#include <vector>
#include <utility> // pair  
#include <map>     // insert  {people �ε���, ��}
#include <algorithm> // sort
void EmergencyExample()
{
	std::vector<int> people = { 10, 5 , 7, 25, 4, 27, 9 };
	std::vector<int> answer;
	answer.assign(people.size(), 0);
	std::map<int, int> sheets;

	for (int i = 0; i < people.size(); i++)
	{
		sheets.insert({ i,people[i] });
	}

	// poeple ���� ����.

	std::sort(people.begin(), people.end());

	// answer�� ����ִ� ���� ū ��?
	// int key = sheets.find(answer[answer.size() - 1])->first;
	// sheets�� find�� ���� first���� ��ȯ���ּ���.
	// answer[key] = 1;

	/*
	*  Tree ��� ����
	*  Tree ������ ������ ���
	*  Idea1. Ʈ���� �����͸� ���� �� ���������� ������ �Ǵ°� �ƴѰ�?
	*  ä�� ���� ������ ����Ʈ������ �ϳ��� ��Ģ�� ������ �غ���.
	*  Heap : ����Ʈ���� �θ��尡 ���� ū������ �Ѵ�. 
	   ���� ���� �ִ� ��尡 ���� ū ��. maxHeap
	   ���� ���� �ִ� ��尡 ���� ���� ��. minHeap
	   heapify() - Ʈ���� �������� �������ϴ� �ڵ� �Լ�
	   heapSort() - �� ����
	*/

	for (int i = 0; i < people.size(); i++)	 //7
	{
		auto it = sheets.find(people[people.size() - 1 - i]);
		int key = it->first;
		answer[key] = i + 1;
	}

	std::cout << "[";
	for (int i = 0; i < answer.size(); i++)
	{
		std::cout << answer[i] << " ";
	}
	std::cout << "]" << std::endl;

}

int main()
{
	EmergencyExample();
}