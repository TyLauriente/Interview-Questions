#include <iostream>

/*
Given an array of integers, find the first missing positive integer in linear time and constant space. 
In other words, find the lowest positive integer that does not exist in the array. The array can contain 
duplicates and negative numbers as well.

For example, the input [3, 4, -1, 1] should give 2. 
The input [1, 2, 0] should give 3.
*/

int FindFirstMissingPositive(int arr[], int size) // Non Linear
{
	int lowest = 1;
	bool good = true;
	do
	{
		good = true;

		for (int i = 0; i < size; i++)
		{
			if (arr[i] == lowest)
			{
				good = false;
				lowest++;
			}
		}

	} while (!good);

	return lowest;
}


int main()
{
	int arr[4]{ 2, 4, -1, 1};

	int result = FindFirstMissingPositive(arr, sizeof(arr) / sizeof(int));

	using namespace std;

	cout << "Array: ";
	for (int i = 0; i < sizeof(arr) / sizeof(int); ++i)
	{
		cout << arr[i] << ", ";
	}
	cout << '\n';

	cout << "Lowest: " << result << '\n';

	system("pause");
	return 0;
}