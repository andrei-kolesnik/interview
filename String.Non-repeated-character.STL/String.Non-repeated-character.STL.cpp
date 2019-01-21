/*
Find the first non-repeated character in a string
*/
#include <bits/stdc++.h>
using namespace std;
//==============================================================================
//VERSION 1: using two arrays
char getFirstNonRepeatedChar1(string s)
{
	vector<char> repeated;
	vector<char> non_repeated;
	vector<char>::iterator it;
	for (auto c : s)
	{
		if (find(repeated.begin(), repeated.end(), c) != repeated.end()) continue;
		if ((it = find(non_repeated.begin(), non_repeated.end(), c)) != non_repeated.end())
		{
			non_repeated.erase(it);
			repeated.push_back(c);
		}
		else
			non_repeated.push_back(c);
	}
	if (non_repeated.size() > 0)
		return non_repeated[0];
	else return ' ';
}
//==============================================================================
//VERSION 2: using character map/count
char getFirstNonRepeatedChar2(string s)
{
	map<char, int> M;
	for (auto c : s) M[c]++;
	for (auto c : s) if (M[c] == 1) return c;
	return ' ';
}
//==============================================================================
//UNIT TEST
void check(string s, char expected, char f(string)) {
	char actual = f(s);
	cout << boolalpha;
	cout << (actual == expected ? "PASS" : "FAIL") << " "
		<< " ( " << expected << " / " << actual << ")" << endl;
}
//==============================================================================
int main()
{
	string s1 = "abcdeacde";
	check(s1, 'b', getFirstNonRepeatedChar1);
	check(s1, 'b', getFirstNonRepeatedChar2);

	string s2 = "abcdeabcde";
	check(s2, ' ', getFirstNonRepeatedChar1);
	check(s2, ' ', getFirstNonRepeatedChar2);

	string s3 = "";
	check(s3, ' ', getFirstNonRepeatedChar1);
	check(s3, ' ', getFirstNonRepeatedChar2);

	system("pause");
	return 0;
}
