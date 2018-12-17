/*
Sieve of Eratosthenes
https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes
Find all the prime numbers up to a given limit
*/

#include <bits/stdc++.h>

using namespace std;

void SieveOfEratosthenes(int n)
{
	if (n < 2)
	{
		cout << "<None>" << endl;
		return;
	}
	vector<bool> Numb3rs(n, true); // could have used bitset, but it needs to know the size at the compile time
	for (int i = 2; i <= sqrt(n); i++)
		if (Numb3rs[i])
			for (int j = i * i; j <= n; j += i)
				Numb3rs[j] = false;
	for (int i = 2; i <= n; i++)
		if (Numb3rs[i])
			cout << i << endl;
}

int main()
{
	SieveOfEratosthenes(100);
	system("pause");
	return 0;
}
