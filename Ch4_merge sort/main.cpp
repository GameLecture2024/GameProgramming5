#include <algorithm>
#include "mergesort.h";

void quicksort(std::vector<int>, int start, int end)
{

}

void BackJun2450()
{
	int n;
	std::cin >> n;
	std::vector<int> list;
	list.assign(n, 0);
	for (int i = 0; i < n; i++)
	{
		std::cin >> list[i];
	}

	std::sort(list.begin(), list.end());

	// quicksort

	for (int i = 0; i < n; i++)
	{
		std::cout << list[i] << std::endl;
	}
}



// sorted  4������ right ������ŭ�� arr���� �����ϴ� �ڵ带 ����� �ϼ��غ�����.
// for(int i=0; i< ����; i++) arr[i] = sorted[i];

int main()
{
	std::cout << "\n���� ���� �迭 ���� " << std::endl; 

	int arr[6] = { 3 , 2, 5 , 1 , 4 , 8 };
	mergesort(arr, 6, 0, 5);
	for (int i = 0; i < 6; i++)
	{
		std::cout << arr[i] << " ";
	}


	std::cout << "\n���� ���� vector ���� " << std::endl;
}