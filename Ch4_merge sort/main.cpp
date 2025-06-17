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



// sorted  4번으로 right 갯수만큼을 arr값에 복사하는 코드를 만들어 완성해보세요.
// for(int i=0; i< 갯수; i++) arr[i] = sorted[i];

int main()
{
	std::cout << "\n병합 정렬 배열 버전 " << std::endl; 

	int arr[6] = { 3 , 2, 5 , 1 , 4 , 8 };
	mergesort(arr, 6, 0, 5);
	for (int i = 0; i < 6; i++)
	{
		std::cout << arr[i] << " ";
	}


	std::cout << "\n병합 정렬 vector 버전 " << std::endl;
}