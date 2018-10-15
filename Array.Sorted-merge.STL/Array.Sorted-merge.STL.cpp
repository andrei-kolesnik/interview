//Merge two sorted arrays
//IN:
//- A sorted array1 of size  n with n elements
//- A sorted array2 of size 2n with n elements
//REQS:
//- in linear time and in-place
//OUT:
//- A merged sorted array of size 2n. 
//EXAMPLE:
//array1 = { 1, 4, 6 }
//array2 = { 2, 3, 5, _, _, _ }
//sortedArray = { 1, 2, 3, 4, 5, 6 }
#include <iostream>
#include <iomanip>
#include <array>
using namespace std;
//==============================================================================
template<class T, size_t SIZE>
void print_arr(array<T, SIZE> &arr)
{
	//with indexing:
	//for (size_t i = 0; i < arr.size(); i++)
	//	cout << "[" << setw(2) << right << i << "]:" << setw(3) << right << arr[i] << endl;

	//with iterator / distance:
	for (auto it = arr.begin(); it != arr.end(); ++it)
		cout << "[" << setw(2) << right << distance(arr.begin(), it) << "]:" << setw(3) << right << *it << endl;

	//with simplified iterator / no distance:
	//for (auto a : arr)
	//	cout << setw(3) << right << a << endl;
	cout << endl;
}
//==============================================================================
template<class T, size_t SIZE>
void array_merge(array<T, SIZE> &arr1, array<T, 2 * SIZE> &arr2)
{
	int n1 = arr1.size(), n2 = arr2.size();
	for (int i1 = n1 - 1, i2 = n1 - 1, i = n2 - 1; i1 >= 0; i--)
	{
		if (i2 < 0 || arr1[i1] > arr2[i2]) //optimization expected so arr2[i2] is not executed if i2 < 0
		{
			arr2[i] = arr1[i1];
			i1--;
		}
		else
		{
			arr2[i] = arr2[i2];
			i2--;
		}
	}
}
//==============================================================================
int main()
{
	array<int, 3> arr1 = { 1, 4, 6 };
	array<int, 6> arr2 = { 2, 3, 5 }; // { 0, 0, 0 } added
	print_arr<int, 3>(arr1);
	print_arr<int, 6>(arr2);

	array_merge<int, 3>(arr1, arr2);
	cout << "Merged:" << endl;
	print_arr<int, 6>(arr2);

	getchar(); // pause the program
	return 0;
}
