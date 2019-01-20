/*
Given an array, sort it using the merge sort alrorithm
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
//==============================================================================
//version 1: straightforward
void merge_array(int arr[], int left, int middle, int right)
{
	int n1 = middle - left + 1;
	int n2 = right - middle;
	int* L = new int[n1];
	int* R = new int[n2];

	for (int i = 0; i < n1; i++)
		L[i] = arr[left + i];
	for (int j = 0; j < n2; j++)
		R[j] = arr[middle + 1 + j];

	int i1 = 0, i2 = 0, k = left; 
	while (i1 < n1 && i2 < n2)
		if (L[i1] <= R[i2])
			arr[k++] = L[i1++];
		else
			arr[k++] = R[i2++];

	while (i1 < n1)
		arr[k++] = L[i1++];

	while (i2 < n2)
		arr[k++] = R[i2++];

	delete L;
	delete R;
}

//version 2: using extra sentinel elements
void merge_array_sentinel(int arr[], int left, int middle, int right)
{
	int n1 = middle - left + 1;
	int n2 = right - middle;
	int* L = new int[n1 + 1]; L[n1] = INT32_MAX;
	int* R = new int[n2 + 1]; R[n2] = INT32_MAX;

	for (int i = 0; i < n1; i++)
		L[i] = arr[left + i];
	for (int j = 0; j < n2; j++)
		R[j] = arr[middle + 1 + j];

	int i1 = 0, i2 = 0;
	for (int k = left; k <= right; k++)
		if (L[i1] <= R[i2])
			arr[k] = L[i1++];
		else
			arr[k] = R[i2++];

	delete L;
	delete R;
}

//version 3: in place
void merge_array_in_place(int arr[], int first, int middle, int last)
{
	int left = first;
	int right = middle + 1;
	//extra optional step: maybe everything happens to be already sorted and we can skip the merge
	if (arr[middle] <= arr[right]) 
		return;
	while (left <= middle && right <= last)
	{
		if (arr[left] <= arr[right]) //selecting from left: no swap, just advance left
			left++; 
		else //selecting from right: rotate one step to the right
		{
			int tmp = arr[right];
			for (int i = right; i > left; i--)
				arr[i] = arr[i - 1];
			arr[left] = tmp;
			left++; middle++; right++; //move everything by one step
		}
	}
	// Whatever remains in [right..last] is in place
}

//==============================================================================
void merge_sort_array(int arr[], int left, int right)
{
	if (left < right)
	{
		int middle = (left + right) / 2;
		merge_sort_array(arr, left, middle);
		merge_sort_array(arr, middle+1, right);
//		merge_array(arr, left, middle, right); //version 1
//		merge_array_sentinel(arr, left, middle, right); //version 2
		merge_array_in_place(arr, left, middle, right); //version 3
//		inplace_merge(arr + left, arr + middle + 1, arr + right + 1); //version 4: there is actually the function for this already in std::algorithm
	}
}
//==============================================================================
int main()
{
	int arr[] = { 5, 2, 4, 7, 1, 3, 2, 6 };
	int n = sizeof(arr) / sizeof(arr[0]);

	print_array(arr, n);
	merge_sort_array(arr, 0, n - 1);
	print_array(arr, n);

	system("pause"); 
	return 0;
}
