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
//VERSION 2a: using character map/count
bool string_anagram_map1(string str1, string str2)
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
//VERSION 2b: using two character maps
bool string_anagram_map2(string str1, string str2)
{
	unordered_map<char, int> chars1;
	for (char c : str1)
		if (c != ' ') 
			chars1[c]++; 

	unordered_map<char, int> chars2;
	for (char c : str2)
		if (c != ' ') 
			chars2[c]++; 

	return chars1 == chars2; //same character count in both strings - they are anagrams
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
		cout << a[0] << "|" << a[1] << " | " << (string_anagram_map1(a[0], a[1]) ? "Yes" : "No") << endl;
		cout << a[0] << "|" << a[1] << " | " << (string_anagram_map2(a[0], a[1]) ? "Yes" : "No") << endl;
	}
	getchar();
}
