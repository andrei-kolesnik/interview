//Determine if two strings are anagrams
//IN:
//Two strings
//OUT:
//- true is if the two strings are anagrams
//- false otherwise
#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
//==============================================================================
//VERSION 1: using sorting
string string_sort_stl(string str)
{
	str.erase(remove(str.begin(), str.end(), ' '), str.end()); //remove al the spaces
	vector<char> v(str.begin(), str.end()); //convert to a vector
	sort(v.begin(), v.end()); //sort
	return string(v.begin(), v.end()); //put the sorted string back together
}
//==============================================================================
bool string_anagram_stl(string str1, string str2)
{
	return !string_sort_stl(str1).compare(string_sort_stl(str2)); //just compare both string when sorted
}
//==============================================================================
//VERSION 2: using character map/count
bool string_anagram_map(string str1, string str2)
{
	unordered_map<char, int> chars;
	for (char c : str1)
		if (c != ' ') //we don't care about the spaces
			chars[c]++; //count every character in str1

	for (char c : str2)
		if (c != ' ') //we still don't care about the spaces
		{
			if (chars.find(c) == chars.end()) return false; //character in str1 not seen in str1 - cannot be an anagram
			chars[c]--; //count the character backwards
			if (chars[c] == 0) chars.erase(c); //and if that was the last one - remove it from the map
		}

	return chars.size() == 0; //if the map ends up empty after all this - we have an anagram
}
//==============================================================================
int main()
{
	array<array<string, 2>, 4> samples{ {
		{ "", "" },
		{ "forty five", "over fifty" },
		{ "customers", "store scum" },
		{ "determine if two strings", "are anagrams" }
	}};

	for (auto a : samples)
	{
		cout << a[0] << "|" << a[1] << " | " << (string_anagram_stl(a[0], a[1]) ? "Yes" : "No") << endl;
		cout << a[0] << "|" << a[1] << " | " << (string_anagram_map(a[0], a[1]) ? "Yes" : "No") << endl;
	}
	getchar();
}
