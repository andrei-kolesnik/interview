#include <bits/stdc++.h>

using namespace std;

int countOneBitsSimple(int val)
{
	int result = 0;
	while (val)
	{
		result += val & 1;
		val >>= 1;
	} 
	return result;
}

int countOneBitsKernighan(int val)
{
	int result = 0;
	while (val)
	{
		val &= val - 1;
		result++;
	}
	return result;
}

int main() {
	cout << countOneBitsSimple(0) << " | " << countOneBitsKernighan(0) << endl;
	cout << countOneBitsSimple(1) << " | " << countOneBitsKernighan(1) << endl;
	cout << countOneBitsSimple(0b0111111111111111) << " | " << countOneBitsKernighan(0b0111111111111111) << endl;
	cout << countOneBitsSimple(0b10101010) << " | " << countOneBitsKernighan(0b10101010) << endl;
	system("pause");
	return 0;
}
