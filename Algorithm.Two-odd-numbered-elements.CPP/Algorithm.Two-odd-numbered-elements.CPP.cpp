/*
You are given an integer array, where all numbers except for TWO numbers appear even number of times.
Find out the two numbers which appear odd number of times.
*/
#include <iostream>
using namespace std;

int firstSetBitMask(int x) {
	// return the mask for the first 1 bit in the number
	if (!x) return 0; // should never happen if the dataset is correct
	int result = 1;
	while (x)
		if (x & result) return result;
		else result <<= 1;
}

bool twoOddNumberedElements(int nums[], int size, int& a, int& b) {
	if (size % 2) return false; // should be an even number of elements
	int totalXor = 0;
	for (size_t i = 0; i < size; i++)
		totalXor ^= nums[i];
	// totalXor has now a XOR b, because all other numbers have cancelled out
	if (!totalXor) return false; // no odd numbered elements detected

	a = 0;
	b = 0;
	int mask = firstSetBitMask(totalXor); // a and b have at leat one bit different
	for (size_t i = 0; i < size; i++)
		if (nums[i] & mask) a ^= nums[i]; // only a, since all the numbers with the bit set cancelled out
		else b ^= nums[i];                // only b, since all the numbers with the bit cleared cancelled out
	return true;
}

//==============================================================================
void check(int nums[], int size, int expected_a, int expected_b) {
	int actual_a, actual_b;
	bool actual = twoOddNumberedElements(nums, size, actual_a, actual_b);
	cout << boolalpha;
	cout << (actual_a == expected_a && actual_b == expected_b ? "PASS" : "FAIL") << " "
		<< actual << " ( " << expected_a << " / " << actual_a << " --- " << expected_b << " / " << actual_b << ")" << endl;
}
//==============================================================================
int main() {
	int arr[] = { 2,3,2,3,3,4,5,4,2,2,5,6 };
	check(arr, 12, 3, 6); // 2

	getchar(); // pause the program
	return 0;
}
