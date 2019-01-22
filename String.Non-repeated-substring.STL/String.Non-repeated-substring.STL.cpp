/*
Given a string, find the max size of the sub-string which has no duplicate characters.
*/
#include <bits/stdc++.h>
using namespace std;
//==============================================================================
int getNonRepeatedSubstring(string s) {
	int result = 0, left = 0, right = 0;
	map<char, bool> counter;
	while (left < s.size())
	{
		char c = s[right];
		if (counter.find(c) == counter.end())
		{
			counter[c] = true;
			if (right + 1 >= s.size())
			{
				result = max(result, right + 1 - left);
				break;
			}
			right++;
		}
		else
		{
			result = max(result, right - left);
			while (s[left] != c)
				counter.erase(s[left++]);
			counter.erase(s[left++]);
		}
	}
	return result;
}
//==============================================================================
//UNIT TEST
void check(string s, int expected) {
	int actual = getNonRepeatedSubstring(s);
	cout << boolalpha;
	cout << (actual == expected ? "PASS" : "FAIL") << " "
		<< " ( " << expected << " / " << actual << ")" << endl;
}
//==============================================================================
int main()
{
	check("", 0);
	check("a", 1); // "a"
	check("aaaaaa", 1); // "a"
	check("aaaaab", 2); // "ab"
	check("abcdeacde", 5); // "abcde"
	check("abacdefcde", 6); // "bacdef"
	check("abcabaabccfdsaewer", 7); // "cfdsaew"

	system("pause");
	return 0;
}
