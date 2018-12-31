/*
Given an array of n + 1 integers between 1 and n, find one of the duplicates.
If there are multiple possible answers, return one of the duplicates.
If there is no duplicate, return -1.

Input 1: [1, 2, 2, 3]
Output 1: 2

Input 2: [3, 4, 1, 4, 1]
Output 2: 4 or 1
*/
#include <iostream>
using namespace std;
//==============================================================================
int array_duplicate_brute(int arr[], int n) {
	// We will compare every number to everything after it
	// Since this is rather foolproof, we'll use it as the expected result in our unit tests
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
			if (arr[i] == arr[j])
				return arr[i];
	return -1;
}
//==============================================================================
int array_duplicate_map(int arr[], int n) {
	// We simple count all the seen occurences
	int* map = (int*)calloc(n, sizeof(int));
	int result = -1;
	for (int i = 0; i < n; i++)
		if (map[arr[i]]++)
		{
			result = arr[i];
			break;
		}
	free(map);
	return result;
}
//==============================================================================
int array_duplicate_sum(int arr[], int n) {
	//The difference between the sum of all the numbers between 1 and n-1 and the actual array sum is the duplicated number
	//This won't work, if more than one number is duplicated
	int sum_expected = 0, sum_actual = 0;
	for (int i = 0; i < n; i++)
	{
		if (i < n - 1) sum_expected += i + 1;
		sum_actual += arr[i];
	}
	if (sum_actual != sum_expected)
		return sum_actual - sum_expected;
	else
		return -1;
}
//==============================================================================
int array_duplicate_marker(int arr[], int n) {
	// We use the fact that all the numbers are positive, so we can mark indexes of the seen numbers with the negative sign
	int result = -1;
	for (int i = 0; i < n; i++)
		if (arr[arr[i]] < 0) 
		{
			result = abs(arr[i]); // we have seen this number before
			break;
		}
		else arr[arr[i]] = -arr[arr[i]];
	//we need to restore all the original numbers
	for (int i = 0; i < n; i++)
		arr[i] = abs(arr[i]);
	return result;
}
//==============================================================================
int array_duplicate_cycle(int arr[], int n) {
	// we can treat the array as a linked list, so the duplicate will cause a loop
	int slow = arr[0];
	int fast = arr[arr[0]];
	while (slow != fast) 
	{
		slow = arr[slow];
		fast = arr[arr[fast]];
	}

	slow = 0;
	while (slow != fast) 
	{
		slow = arr[slow];
		fast = arr[fast];
	}
	return slow;
}
//==============================================================================
void check(int nums[], int size) {
	int expected = array_duplicate_brute(nums, size);
	int actual1 = array_duplicate_map(nums, size);
	int actual2 = array_duplicate_sum(nums, size);
	int actual3 = array_duplicate_marker(nums, size);
	int actual4 = array_duplicate_cycle(nums, size);
	cout << boolalpha;
	cout << (actual1 == expected && actual2 == expected && actual3 == expected && actual4 == expected ? "PASS" : "FAIL") << " "
		<< " ( " << expected << " / " << actual1 << " & " << actual2 << " & " << actual3 << " & " << actual4 << ")" << endl;
}
//==============================================================================
int main() {
	int arr1[] = { 1, 2, 2, 3 };
	check(arr1, 4); // 2

	int arr2[] = { 3, 4, 1, 4, 1 };
	check(arr2, 5); // 4 or 1

	getchar(); // pause the program
	return 0;
}
