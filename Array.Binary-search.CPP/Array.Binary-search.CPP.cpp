//Implement a binary search for the integer in a sorted array
//IN:
//A sorted array, the element to search for
//OUT: 
//The position of the element in the array, or -1 if not found
//==============================================================================
#include <iostream>
#include <iomanip>
using namespace std;
//==============================================================================
void print_arr(int arr[], int n) 
{
	for (int i = 0; i < n; i++)
		cout << "[" << setw(2) << right << i << "]:" << setw(3) << right << arr[i] << endl;
	cout << endl;
}
//==============================================================================
const int NOT_FOUND = -1;
int array_binary_search_cpp(int heap[], int needle, int left, int right)
{
	//cout << left << "-" << right << endl;
	if (right < left) return NOT_FOUND;
	if (right == left) return heap[left] == needle ? left : NOT_FOUND;
	int middle = (right + left) / 2;
	if (heap[middle] == needle) return middle;
	if (heap[middle] > needle) return array_binary_search_cpp(heap, needle, left, middle - 1);
	return array_binary_search_cpp(heap, needle, middle + 1, right);
}
//==============================================================================
int main()
{
	int arr[] = { 1, 2, 3, 4, 6, 7, 8, 9, 11 };
	int n = sizeof(arr) / sizeof(arr[0]);
	print_arr(arr, n);

	for (int i = 0; i < n; i++)
		cout << array_binary_search_cpp(arr, i, 0, n - 1) << endl;

	getchar(); // pause the program
	return 0;
}
