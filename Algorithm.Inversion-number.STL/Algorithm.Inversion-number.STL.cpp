/* Inversion number */
#include <bits/stdc++.h>

using namespace std;

// version 1: strightforward count
int inversionNumber(vector<int> v) {
	int n = v.size(), result = 0;
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
			if (v[i] > v[j])
				result++;
	return result;
}

// version 2: merge sort
// see https://www.geeksforgeeks.org/counting-inversions/

int main()
{
	int A[4] = { 1, 2, 3, 4 }; int N = sizeof(A) / sizeof(A[0]);
	vector<int> V(A, A + N);
	sort(V.begin(), V.end());

	do {
		for (auto a : V) cout << a << " ";
		cout << " inv#: " << inversionNumber(V) << endl;
	} while (next_permutation(V.begin(), V.end()));

	system("pause");
	return 0;
}
