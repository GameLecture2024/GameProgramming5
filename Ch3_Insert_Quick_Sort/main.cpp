#include <iostream>
#include <vector>
#include <algorithm>

/*
*  삽입 정렬
*  - 특정 수를 정렬된 위치로 옮기는 방식
*  - 앞에서 부터 데이터를 정렬한다.
*/

void InsertSort(int arr[], int n)
{
   // 몇 번 cycle 돌아야 하나요?

	for (int i = 1; i < n; i++)
	{
		// 현재 key의 값이 무엇인가?

		int key = arr[i];

		// key의 값 이전의 값들과 비교를 해라.
		int j = i - 1;

		// while()  조건이 true일 때 중괄호{} 코드를 실행하라.

		while ( j >= 0 && arr[j] > key ) { // j값 보다 key 값이 작을 때 또는 인덱스의 값이 0보다 클때
			arr[j + 1] = arr[j];  // 왼쪽의 데이터와 새로 들어온 데이터의 위치를 변경해라
			j--;  // 현재 key의 위치
		}

		arr[j + 1] = key;
	}  
}

void InsertSort(std::vector<int>& nums)
{
	// 몇 번 cycle 돌아야 하나요?

	int n = nums.size();
	for (int i = 1; i < n; i++)
	{
		// 현재 key의 값이 무엇인가?
		int key = nums[i];
		int j = i - 1;
		
		 // key 왼쪽에 있는 모든 데이터들과 비교해서 위치를 찾은 다음에 그 위치에 삽입.
		while (j >= 0 && nums[j] > key) // j의 값이 0보다 크거나 같을 때만 또는 key의 값이 왼쪽에 있는 값보다 작을 때만
		{
			// 작으면 왼쪽과 키에 들어있는 값을 변경하고
			// index를 왼쪽으로 이동해서 다음 수와 또 비교한다.
			nums[j + 1] = nums[j];
			j--;
		}
		// 위치를 찾았으면 해당 위치에 key를 저장하라

		nums[j + 1] = key;
	}
}

/*
*  장점 : 모든 경우에 위치 변경이 발생하는 것이 아니라, while 조건에 해당 할 때만 위치 변경(swap)이 발생한다.
*  컨테이너 데이터가 정렬되어 있을 수록 정렬 속도가 빠르다.	"분할 정복" 정렬, n*logN
*  사이클 : n 
*  while() 1 ~ n 크기를 가질 수 있다.
*  최선의 경우 O(n)   평균, 최악의 경우(O(N^2))
*  단점 : n의 제곱에 비례해서 시간이 걸린다.
*/

/*
*  log 시간이 얼마나 빠를까?
*  2^10 = 1024 // 대략 1000
*  2^20 = 2^10 * 2^10 // 1,000,000 대략 백만
*  1og2(2^20) = 20;   n번(백만 번) log n 번 (20번)
* 
*  시간을 단축하게 하기 위해서는 logn으로 표현하는 방법을 찾는다.
*  "분할 정복" 알고리즘
*/

/*
*  1 2 3 4 5 6 7 8 9 10  O(n^2)  100
* 
*  1 2 3 4 5    = 5^2 = 25
*  6 7 8 9 10   = 5^2 = 25	  50		   
*/

#pragma region 퀵 정렬

/*
*  임의의 pivot을 정한다. 가장 왼쪽의 값을 피벗으로 한다.
*  pivot 피벗 : 기준점 
   분할 정복 알고리즘. 분할을 하기 위한 기준이다.
   특징 : 분할 정복 알고리즘을 사용하고 있다. 재귀 함수로 구현된다.
   평균 O(n * logn) 시간을 갖는다.
   O(n^2) 정렬 방식으로 알고리즘 구하세요. (버블, 선택, 삽입) 
   O(n log n) 정렬 방식으로 알고리즘 구하세요. (퀵, 병합)
*/

/*
*  언제 사용하는가? data의 갯수가 10만 개가 넘어갈때,  10만 X 10만 = 10 ~ 몇백억 0.00001 * 10억
*  데이터의 개수가 많을 때 사용한다.
* 
*  단점 : 정렬되어 있는 데이터에서 quickSort 사용할 경우 O(n^2) 시간이 걸린다.
*  1 2 3 4 5
*  알고리즘 문제에 quickSort 구현했을 때 시간이 초과했다. 
   정렬되어 있는 케이스를 받을 때 비효율적이다.
*/

// bool compare	( a < b) return

void quickSort(int data[], int start, int end)	// true, false
{
	if (start >= end) // 데이터가 1개만 있을 때 , 재귀 함수를 끝내기 위한 조건 return 표현
	{
		return;
	}

	int pivot = start;   // 기준이 되는 값
	int i = start + 1;	 // 왼쪽에서 변경할 위치
	int j = end;		 // 오른쪽에서 변경할 위치
	int temp;			 // swap 사용하기 위한 임시 변수

	while (i <= j) { // 왼쪽 인덱스를 오른쪽 인덱스가 추월 했을 때 까지 반복
		while (i <= end && data[i] >= data[pivot] )// 피벗보다 큰 값을 만날 때 그 값을 찾아라
		{
			//(작을 때 계속 i를 증가해라)
			i++;
		}
		while (j > start && data[j] <= data[pivot])    // 피벗보다 작은 값을 만날 때 그 값을 선택해라
		{
			//(j의 값을 변경해주는 코드)
			j--;
		}

		// i > j  // 왼쪽 인덱스가 오른쪽 인덱스 보다 크면 (엇갈렸다) 피벗에 있는 값과 j의 값을 변경하세요
		if (i > j)
		{
			temp = data[j];
			data[j] = data[pivot];
			data[pivot] = temp;

			//std::swap(data[pivot], data[j]);
		}
		else { 	// 엇갈리지 않았을 때 ( j 와 i에 있는 값을 변경하세요)

			temp = data[j];
			data[j] = data[i];
			data[i] = temp;

			//std::swap(data[i], data[j]);
		}

		// 재귀 함수

		// quicksort(왼쪽 파트 )   quicksort(오른쪽 파트)   
		// 현재 피벗의 위치인 j 기준으로 왼쪽 퀵 소트를 실행하고 오른쪽 퀵 소트 함수를 실행해보세요
		quickSort(data, start , j-1); // 왼쪽
		quickSort(data, j+1 , end);	// 오른쪽
	}
}

/*
*  내림차순 버전으로 퀵 정렬을 구현을 해보세요.
*  왼쪽과 오른쪽을 비교하는 코드를 (오름차순 : 왼쪽이 작은 수 ) (내림차순  왼쪽이 큰 수 )
*/

void quickSort(std::vector<int>& data, int start, int end)
{

}


#pragma endregion


int main()
{
	std::cout << "삽입 정렬 배열 형식" << std::endl;

	int arr1[10] = { 3, 5, 9 , 1 , 2 , 4 , 6, 8, 7 ,0 };
	InsertSort(arr1, 10);

	for (int i = 0; i < 10; i++)
	{
		std::cout << arr1[i] << " ";
	}
	
	std::cout << "\n\n삽입 정렬 vector 형식" << std::endl;
	std::vector<int> nums1 = { 3, 5, 9 , 1 , 2 , 4 , 6, 8, 7 ,0 };
	InsertSort(nums1);

	for (int num : nums1)
	{
		std::cout << num << " ";
	}

	std::cout << "\n\n퀵 정렬 배열 형식" << std::endl;
	int arr2[10] = { 3, 5, 9 , 1 , 2 , 4 , 6, 8, 7 ,0 };
	quickSort(arr2, 0, 9);

	for (int i = 0; i < 10; i++)
	{
		std::cout << arr2[i] << " ";
	}

	//std::cout << "\n\n퀵 정렬 vector 형식" << std::endl;
	//std::vector<int> nums2 = { 3, 5, 9 , 1 , 2 , 4 , 6, 8, 7 ,0 };
	//quickSort(nums1, 0, nums2.size()-1);
	//
	//for (int num : nums2)
	//{
	//	std::cout << num << " ";
	//}

}