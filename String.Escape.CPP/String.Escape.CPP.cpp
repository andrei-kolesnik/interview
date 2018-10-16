//Escape all % characters in a string with % as the escape character
//IN:
//A string with % characters
//OUT:
//The same string with all the % characters escaped with another % character
//==============================================================================
#include <stdio.h>
#include <string.h>
//ALTERNATIVE: #include <stdlib.h>
//ALTERNATIVE: #include <malloc.h>
using namespace std;
//==============================================================================
#define MAX_SIZE 40
char* string_escape_cpp(char* str)
{
	//ALTERNATIVE: char *str_esc = (char*)malloc(2*MAX_SIZE+1);
	static char str_esc[2*MAX_SIZE-1]; //static does not get destroyed after return; double size in case all the characters are "%"
	int i = 0;
	for (char *p = str; *p != 0; p++)
	{ 
		if (i > 2*MAX_SIZE-1) break;
		if (*p == '%') str_esc[i++] = *p;
		str_esc[i++] = *p;
	}
	str_esc[i] = 0;
	return str_esc;
}
//==============================================================================
#define NUM_STRS 7
int main()
{
	char strs[NUM_STRS][MAX_SIZE] = {
		"", //empty case
		"Nothing to escape here",
		"~75% of all students have loan debt",
		"5% + 5% = 10%",
		"set PATH=c:\\;%PATH%",
		"WHERE comment LIKE '%10%%%'",
		"%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" //extreme case
	};

	for (int i = 0; i < NUM_STRS; i++)
	{
		puts(string_escape_cpp(strs[i])); //safer and faster than printf()
//		printf("%s [%d-%d]\n", string_escape_cpp(strs[i]), strlen(strs[i]), strlen(string_escape_cpp(strs[i])));
	}
	getchar();
}