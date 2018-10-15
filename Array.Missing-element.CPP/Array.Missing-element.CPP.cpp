//IN:
//An unsorted array of size n containing the integers 1 through n in random order with one element randomly replaced by 0
//OUT: 
//The missing element
//==============================================================================
#include <iostream>
#include <iomanip>
using namespace std;
//==============================================================================
void print_arr(int* arr, int n) //passing array as a pointer
{
	for (int i = 0; i < n; i++, arr++)
		cout << "[" << setw(2) << right << i << "]:" << setw(3) << right << *arr << endl;
	cout << endl;
}
//==============================================================================
void array_missing_element_cpp(int arr[], int n) //passing array as an array
{
	int sum_expected = 0, sum_actual = 0;
	for (int i = 0; i < n; i++)
	{
		sum_expected += i + 1;
		sum_actual += arr[i];
	}
	cout << setw(20) << "Sum Expected:"    << setw(4) << sum_expected << endl;
	cout << setw(20) << "Sum Actual:"      << setw(4) << sum_actual << endl;
	cout << setw(20) << "Missing Element:" << setw(4) << sum_expected - sum_actual << endl;
}
//==============================================================================
int main()
{
	int arr[] = { 1, 7, 0, 3, 10, 8, 9, 6, 5, 2};
	int n = sizeof(arr) / sizeof(arr[0]);
	print_arr(arr, n);

	array_missing_element_cpp(arr, n);

	getchar(); // pause the program
	return 0;
}
