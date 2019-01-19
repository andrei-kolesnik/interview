/*
Given an array, sort it using the quick sort alrorithm
IN:
Unsorted array with n elements
Out:
Sorted array
*/

#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;
//==============================================================================
void print_array(int arr[], int n)
{
	for (int i = 0; i < n; i++)
		cout << setw(3) << right << arr[i];
	cout << endl;
}

void swap(int* a, int* b)
{
	int swap = *a;
	*a = *b;
	*b = swap;
}

int partition_array(int arr[], int left, int right)
{
	int pivot = arr[right];
	int pos = left;
	for (size_t i = left; i < right; i++)
		if (arr[i] < pivot)
		{
			swap(&arr[i], &arr[pos]);
			pos++;
		}
	swap(&arr[pos], &arr[right]);
	return pos;
}

void quick_sort_array(int arr[], int left, int right)
{
	if (left < right)
	{
		int pos = partition_array(arr, left, right); // the element at [pos] is already at its place
		quick_sort_array(arr, left, pos - 1); // everything on the left of [pos] is smaller, we can quick sort it
		quick_sort_array(arr, pos + 1, right); // everything on the right of [pos] is bigger, we can quick sort it as well
	}
}

//==============================================================================
int main()
{
	int arr[] = { 5, 2, 4, 7, 1, 3, 2, 6 };
	int n = sizeof(arr) / sizeof(arr[0]);

	print_array(arr, n);
	quick_sort_array(arr, 0, n - 1);
	print_array(arr, n);

	system("pause");
	return 0;
}
