#include <iostream>
#include <vector>

/*
*  ���� �پ��� ������� ���� ����.
*  �� ������ �ؾ��ϴ°�?
*  ���ο� ������(Item) �����̳� �߰��� ��
   ���ĵǾ� �ִ� ���·� ������ �Ǵ� ��찡 �ִ�.
*/

/*
*  Ž��? : �����̳� �ȿ� �����Ͱ� �ִ��� ������ ã�´�.
*  Ž���� ���α׷��� �ڵ�� �ѹ� �����غ���.
*  (1) �տ��� ���� �����͸� ���ؼ� �ִ��� ������ Ȯ��
*     - ���� Ž�� ���(linear search)
*  (2) ���� Ž�� (binary search)
*     - �����̳ʰ� ���ĵǾ� ���� �� �߾� ���� �������� �����͸� ����� ã�� ���.
*/

/*
*  ���� Ž���� ��쿡�� �ּ��� ���(best case) O(1) �ð��� �ɸ��� �־��� ���(worst case) n �ð��� �ɸ��ϴ�.
*  ��� O(n) �ð��� �ɸ���. �������� ������ �鸸�� �Ѿ�� ��ȿ�����̰ڴ�.
   "���� ���� �˰���" : ������ ����� ���� ������ �ذ��ϴ� ������� ������ Ǭ��.
*/

#include <utility>

/*
*  std::pair<int , Ŭ�����̸�> 
   std::pair<int, std::string> e;

   std::vector<std::pair<int, std::string>>	data;
   // pairŸ�� �����ϴ� ��� 
   data.push_back( {0, "AAA"});     0 ~  5  
   // �ش� �ϴ� �ε����� ������ �� �ε����� ����Ǿ� �ִ� ���ڸ� ����ϴ� �ڵ带 �����.

   // ������ ID�� ������ ���� ������ �����մϴ�. ������ ������ ID�� �������� �ش� ������ ����(�г���)��
   // �˻��ϴ� ����� �����غ�����.
*/

template<typename T1, typename T2>
struct myPair
{
	T1 first;
	T2 second;
	// ���� ����,  �̵�, ������ �����ε�....

};

class Item
{
	int price;
	bool operator<(const Item& other)
	{
		return price < other.price;
	}
};


void LinearSearch(int arr[], int n, int target)
{
	// ��ü ������ �ݺ��ؼ�  (for�ݺ���	) 
	// target�� ���� �����Ͱ� �����ϸ�  (���ǹ�) 
	for (int i = 0; i < n; i++)
	{
		// arr[0] arr[1] ... arr[n]

		if (arr[i] == target)
		{
			std::cout << "�ش��ϴ� ������ : " << target << "�� ã�ҽ��ϴ�" << std::endl;
			return;
		}		
	}

	std::cout << "�����͸� ã�� ���߽��ϴ�." << std::endl;
}

void LinearSearch(std::vector<int> arr, int target)
{
	int n = arr.size();

	for (int i = 0; i < n; i++)
	{
		// arr[0] arr[1] ... arr[n]

		if (arr[i] == target)
		{
			std::cout << "�ش��ϴ� ������ : " << target << "�� ã�ҽ��ϴ�" << std::endl;
			return;
		}
	}

	std::cout << "�����͸� ã�� ���߽��ϴ�." << std::endl;
}

// iterator ������� ������ ���� Ž���Դϴ�.


void BinarySearch(int arr[], int n, int target)
{
    // int mid = (left + right) / 2	 -  20�� + 20��  
	// int mid = left + (right - left) / 2  ���� ������ �Ÿ� /2 �����ش�.

	int i = 0;  // i ���� 	    arr[left] arr[right]
	int j = n - 1; // j ������
	
	int mid; // mid �ּ�. ���ڰ� ������ �ȵǾ� �ִ� ����

	while (i <= j) // ����, ������
	{
		mid = i + (j - i) / 2; // ������ �� �� ���� �߾Ӱ��� �������ش�.
		 // ���� mid���� target�� ���غ�����
		 
		if (arr[mid] == target)	  // target ã�� ��� : �����͸� ã�Ҵ�.
		{
			std::cout << "�ش��ϴ� ������ : " << target << "�� ã�ҽ��ϴ�" << std::endl;
			return;
		}
		else if (arr[mid] > target)  // target ���� ��� : ���ʿ��� �ٽ� ã������.
		{
			j = mid - 1; // mid�� �������� ��� j�� �ٲٸ� �ɱ�?
		}
		else {		// target ū ���
			i = mid + 1;// ���� i�� mid�� �������� ��� �ٲ�� �ɱ�?
		}	
	}
	std::cout << "�����͸� ã�� ���߽��ϴ�." << std::endl;
}

// ��� �Լ� ������� ������ ���� Ž��
void BinarySearchByRecursive(int arr[], int n, int target, int left, int right)	// ����, �������� ���� �ٲ��.
{
	 // ��� �Լ��� Ż���� �� �ִ� ����

	if (left > right)
	{
		std::cout << "�����͸� ã�� ���߽��ϴ�." << std::endl;
		return;
	}

	int mid = left + (right - left) / 2;

	if (arr[mid] == target)
	{
		std::cout << "�ش��ϴ� ������ : " << target << "�� ã�ҽ��ϴ�" << std::endl;
		return;
	}
	else if (arr[mid] > target) // ���� (right = mid - 1)
	{
		BinarySearchByRecursive(arr, n, target, left, mid - 1); // right = mid - 1;
	}
	else  // ������ (left = mid + 1)
	{
		BinarySearchByRecursive(arr, n, target, mid + 1, right); // left = mid + 1
	}
}

void Example()
{
	// pair ������ �ϳ��� ǥ���ϴ� ���. key, value ���� �����ؼ� �����ϴ� ���.
	// ������ �����ε�. Ŭ���� �񱳸� ������.
	// ������ ID - 7C4A3B0F282F

	std::vector<std::pair<int, std::string>> data;


	std::pair<int, std::string> a = { 1, "AAA" };
	data.push_back({ 0, "AAA" });
	data.push_back(a);
	data.push_back(std::make_pair(2, "CCC"));
	data.push_back({ 3, "DDD" });
	data.push_back({ 4, "EEE" });

	// ���� Ž��, ���� Ž���� ����ؼ� ������� ã������.

	// Ÿ���� �ٸ��� ������ �ش��ϴ� Ÿ������ �ٽ� ������ ����Ѵ�.

	std::vector<int> temp;
	for (int i = 0; i < data.size(); i++)
	{
		temp.push_back(data[i].first);
	}

	/*
	*  == �˰��� ���� ==
	*  1. ��ȯ�ϴ� ���� boolŸ������ �����غ�����.
	*  2. LinearSearch(vector<int> -> vector<pair<int, string>> �������� �����غ�����.
	*  3. UserId�� ����ؼ� ������ �г����� ����ϴ� �ڵ带 �ϼ��غ�����.
	*/

	LinearSearch(temp, 4); // ���� �����Ѵٸ�
	std::cout << "�����Ͱ� �����մϴ� : (" << data[4].second << ")" << std::endl;
}

// class UserDataManager

void UserDataSearch(std::vector<std::pair<int, std::string>>data, int userID)
{

}


int main()
{
	std::cout << "\n�迭�� ������ ���� Ž��" << std::endl;

	int arr[5] = { 0, 5 , 2 ,4 ,9 };
	LinearSearch(arr, 5, 2);

	std::cout << "\n���ͷ� ������ ���� Ž��" << std::endl;
	
	std::vector<int> data = { 0, 5 , 2 ,4 ,9 };
	LinearSearch(data, 2);

	std::cout << "\n�迭�� ������ ���� Ž��" << std::endl;

	int arr2[5] = { 0, 2 , 4 ,5 ,9 };
	// std::sort
	BinarySearch(arr2, 5, 5);

	std::cout << "\n�迭�� ������ ��� ����� ���� Ž��" << std::endl;

	int arr3[5] = { 0, 2 , 4 ,5 ,9 };
	BinarySearchByRecursive(arr3, 5, 2, 0, 4);

	std::cout << "\n���ͷ� ������ ���� Ž��" << std::endl;

	std::vector<int> data2 = { 0, 5 , 2 ,4 ,9 };
	// std::sort(data2.begin(), data2.end()); 
	//BinarySearch(data, 2);

	Example();
}