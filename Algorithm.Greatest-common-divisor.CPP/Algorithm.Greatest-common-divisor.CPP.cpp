/*
Find the greatest common divisor of the two given numbers using the Euclidean algorithm
IN: 252, 105
OUT: 21
*/
#include <iostream>

using namespace std;

int gcd_division(int a, int b) {
	while (b != 0) {
		int t = b;
		b = a % b;
		a = t;
	}
	return a;
}

int gcd_subtraction(int a, int b) {
	while (a != b) {
		if (a > b)
			a = a - b;
		else
			b = b - a;
	}
	return a;
}

int gcd_recursion(int a, int b) {
	if (b == 0)
		return a;
	else
		return gcd_recursion(b, a % b);
}

void check(int a, int b, int expected) {
	int actual1 = gcd_division(a, b);
	int actual2 = gcd_subtraction(a, b);
	int actual3 = gcd_recursion(a, b);
	cout << boolalpha;
	cout << (actual1 == expected && actual2 == expected && actual3 == expected ? "PASS" : "FAIL") << " "
	  	 << " ( " << expected << " / " << actual1 << " " << actual2 << " " << actual3 << ")" << endl;
}


int main() {
	check(17, 19, 1);
	check(252, 105, 21);
	check(1071, 462, 21);
	getchar();
	return 0;
}
