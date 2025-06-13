#include <iostream>
#include <vector>
#include <algorithm>

/*
*  	nums �迭���� �׽�Ʈ ���̽��� ���´�.
*   nums vector��  1,3,8,2,9... ������ ������ ���ɴϴ�.
    �� ���ڸ� ������������ �����غ�����. �� ������ ���� answer�� �����ؼ� ��ȯ�ϼ���.	 
	������ �غ�����.
*/

/*
*   �ڵ带 ���� �� �ִ� = �� ���� �˰��� �ڵ尡 �����Ѵ�.
*   �ð� ���⵵, ���� ���⵵.
*   �ּ� : �ڵ尡 ������ ������ ���� ����ϴ� �ڵ�.
    �ð��� ������ ������ �����ϰ�, �ð��� ������ ������ �� ����ϴ� ��찡 ����.
*/

/*
*   O(1), (log n) (n) (n^2)
* 
*   ���� ū ������ �Ű� ����.   (n^2 + 2n + 1)
* 
*   1000n           n^2 +1
* 
*   1000            2
* 
*   n�� ũ��   1    10         100   1000     1000,000
*   O(1)	   1	1	        1	   1		 1
*   O(log n)   0   	1			2		3		  6
*   O(n)       1	10		   100	1000	  1000,000
*   O(n^2)     1
* 
*   ���� : ��κ��� �˰��� ������ �׽�Ʈ ���̽��� ������ ���� ��츦 �����Ѵ�.
*/

/*
*  �ð� ���⵵�ε� �� ���� �ð��� ���ϴ� ���� �ƴ϶� ���� Ƚ���� ���ұ��?
*  - ȯ�濡 ���� ��� ���� �޶�����. 
*  - ���� Ƚ���� ������ ���� ���� ū ������ �񱳸� ����.
*  - O(n) ��� ǥ���.
*/

#pragma region �ð� ���⵵ ����ϱ�

void Test1()
{
	// 1 ~ 5������ ���ڸ� ���� ���� ���� ����ϼ���.
	// int sum ����. for �ݺ����� ����ؼ� sum�� �����غ�����.

	int sum = 0;  // intŸ�� sum�� �� 0�� �Ҵ�. ���� 1��.

	int n = 0;
	std::cin >> n;	   // n�� ũ�Ⱑ �������� �ʾҴ�.

	for (int i=1; i<6; i++)
	{
		sum += i; // n�� ����.
	}

	// 52 �ڵ��� ���� Ƚ�� : n + 3

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			sum += i * j;	   // ��� ����? n * n
		}
	}

	// 64 �ڵ��� ���� Ƚ�� : N^2 + n + 3
}

#pragma endregion

std::vector<int> solution(std::vector<int> nums)
{
	std::vector<int> answer;
	std::sort(nums.begin(), nums.end());  // STL �����Ǿ� �ִ� ������ ����ϰڴ�.
	answer = nums;
	return answer;
}

// ���ĵǾ� ���� ���� ���ڸ� �迭�� �޾ƿͼ� �� ���� �����ϴ� �Լ��� ����� ������.

// ���� ����, ���� ����, ���� ����

#pragma region ���� ����

// ������ ���������� �ð��� ���� �ɸ��� �����Դϴ�.
void bubblesort(int arr[], int n)
{
	// ����Ŭ�� �� �� ���ƾ��ϴ°�?

	for (int i = 0; i < n - 1; i++)	 // n - 1�� (3)
	{
		for (int j = 0; j < n - i - 1; j++)				 // j, i, 3���� ǥ���Ϸ��� ��� �ؾ��ұ�?
		{
			// swap�� ���� ������ ����

			if (arr[j] > arr[j + 1]) // ���� ���� �ٷ� ���� �� ���� ũ��.. ���� �����ϼ���.
			{
				// swap�� �����ϼ���.

				std::swap(arr[j], arr[j + 1]);
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		std::cout << arr[i] << " ";
	}

	// ����Ŭ ���� ������ �ؾ��ϴ°�?

	// 1. �迭 ��ҳ��� �񱳸� �Ѵ�.
	// 2. (k��°) (k+1) ū ��쿡 �迭 ��Ҹ� �����Ѵ�.
}

// vector.size()

// �ð� ���⵵ : O(n^2)
// �ּ�, �־�, ���
// ���� ����    :  �ּ�(O(n)), �־�(O(n^2)), ��� (O(n^2))

void bubblesort(std::vector<int> nums)
{
	int n = nums.size();

	for (int i = 0; i < n - 1; i++) // �ڽŰ��� �񱳸� ���ص� �Ǽ� -1, ����Ŭ ���� ���� ū���� ��������.
	{
		for (int j = 0; j < n - i - 1; j++) // �� ����Ŭ ���� ���ϴ� Ƚ�� , ����Ŭ ���� �پ���.
		{
			if (nums[j] > nums[j + 1])
			{
				std::swap(nums[j], nums[j + 1]);
			}
		}
	}

	for (int n : nums)
	{
		std::cout << n << " ";
	}
}


#pragma endregion

#pragma region ���� ����

// ���� ���� ���� ����.
// �� �տ� ������ ������� �����Ѵ�.
// ����Ŭ ���� ���� ���� ���� ����� ��ġ�� ã�ƾ� �մϴ�.

// �ð� ���⵵ : O(n^2) O(n)

// Min()�Լ�.   ��ü �迭 �߿��� ���� ���� ���� ��ȯ�ϴ� �Լ�.

void SelectionSort(int arr[], int n)
{
	// �� �� ����Ŭ ���ƾ� �ұ��? 

	for (int i = 0; i < n - 1; i++)
	{
		int min_idx = i;

		// for �ݺ��� ǥ��, j�� �� i+1..
		for (int j = i + 1; j < n; j++)
		{
			// arr[min_idx]   arr[j] ���ؼ� ������ �ʰ� �ּҰ�.
			if (arr[min_idx] > arr[j])
			{
				min_idx = j;
			}
		}

		if (i != min_idx)
		{
			std::swap(arr[i], arr[min_idx]);
		}
	}

	// arr[j]�� ����, ���� ���� ��(Index) arr[min]

	// swap   arr[��] arr[min]

	for (int i = 0; i < n; i++)
	{
		std::cout << arr[i] << " ";
	}
}


void SelectionSort(std::vector<int> nums)
{
	int n = nums.size();
}


#pragma endregion

#pragma region ���� ����

#pragma endregion

void Execute()
{
	std::vector<int> nums = { 1,5,3,4,2,8 };

	auto v = solution(nums);

	for (auto& elem : v)
	{
		std::cout << elem << " ";
	}
}

int main()
{
	//Execute();

	std::cout << "\n���� ���� �ڵ� ����" << std::endl;
	int arr[5] = { 3,1,2,9,4 };
	bubblesort(arr, 5);

	std::cout << "\n���� ���� �ڵ� ����2" << std::endl;
	std::vector<int> nums = { 9,2,3,4 };
	bubblesort(nums);

	std::cout << "\n���� ���� �ڵ� ����" << std::endl;
	int arr2[5] = { 3,1,2,9,4 };
	SelectionSort(arr2, 5);
}