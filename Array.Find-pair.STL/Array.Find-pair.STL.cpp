/*
Find a pair with the given sum in an unsorted array
IN:
- An unsorted array
- A number
OUT:
- All the element pairs which sum equals to the given number
COMMENTS:
Sorting solution: complexity O(n*log(n)) / space O(1) (see the brute force solution in C#)
*/
#include <iostream>
#include <iomanip>
#include <array>
#include <algorithm>
using namespace std;
//==============================================================================
template<class T, size_t SIZE>
void print_arr(array<T, SIZE> &arr)
{
	for (auto it = arr.begin(); it != arr.end(); ++it)
		cout << "[" << setw(2) << right << distance(arr.begin(), it) << "]:" << setw(3) << right << *it << endl;
	cout << endl;
}
//==============================================================================
template<class T, size_t SIZE>
void array_find_pair(array<T, SIZE> &arr, int sum)
{
	sort(arr.begin(), arr.end());
	cout << "Sorted:" << endl;
	print_arr<T, SIZE>(arr);
	auto low = arr.begin(), high = arr.end();
	high--;
	bool found = false;
	while (low < high)
	{
		if (*low + *high == sum)
		{
			cout << "Pair found at index [" <<
				distance(arr.begin(), low) << "] and [" <<
				distance(arr.begin(), high) << "]: (" << *low << " + " << *high << ")" << endl;
			low++;
			high--;
			found = true;
		}
		else if (*low + *high < sum) low++;
		else high--;
	}
	if (!found) cout << "Nothing found" << endl;
}
//==============================================================================
int main()
{
	array<int, 11> arr = { 3, 7, 6, 2, 11, 5, 1, 4, 8, 9, 10 };
	int sum = 12;
	print_arr<int, 11>(arr);
	array_find_pair<int, 11>(arr, sum);
	getchar(); // pause the program
	return 0;
}
