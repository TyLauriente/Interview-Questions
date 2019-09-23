#include <iostream>
#include <cmath>

/*
Given an array of integers, find the first missing positive integer in linear time and constant space. 
In other words, find the lowest positive integer that does not exist in the array. The array can contain 
duplicates and negative numbers as well.

For example, the input [3, 4, -1, 1] should give 2. 
The input [1, 2, 0] should give 3.
*/

int FindMissingNoNegatives(int arr[], int size) // Only works on a non-negative array set
{
	for (int index = 0; index < size; ++index)
	{
		if (abs((double)arr[index]) - 1 < size && arr[(int)abs((double)arr[index]) - 1] > 0)
		{
			arr[(int)abs((double)arr[index]) - 1] = -arr[(int)abs((double)arr[index]) - 1];
		}
	}

	for (int index = 0; index < size; ++index)
	{
		if (arr[index] > 0)
		{
			return index + 1;
		}
	}

	return size + 1;
}

template<class T>
void Swap(T* a, T* b)
{
	T temp = *a;
	*a = *b;
	*b = temp;
}

int ShiftNegativesToLeft(int arr[], int size)
{
	int positiveStartIndex = -1; // -1 represents no found positive Start Index

	for (int index = 0; index < size; ++index)
	{
		if (positiveStartIndex == -1 && arr[index] > 0)
		{
			positiveStartIndex = index;
		}
		if (arr[index] <= 0 && positiveStartIndex != -1) // If we have a positive start index
		{
			Swap(&arr[index], &arr[positiveStartIndex]);
		}
	}

	return positiveStartIndex;
}

int FindMissing(int arr[], int size)
{
	int positiveStartIndex = ShiftNegativesToLeft(arr, size);

	return FindMissingNoNegatives(arr + positiveStartIndex, size - positiveStartIndex);
}


int main()
{
	int arr[4]{2, 4, 1, 3};

	int result = FindMissing(arr, sizeof(arr) / sizeof(int));

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