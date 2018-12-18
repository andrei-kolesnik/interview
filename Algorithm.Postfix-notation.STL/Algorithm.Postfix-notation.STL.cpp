/*
Parse and calculate an arithmetic expression in Reverse Polish / postfix notation
IN: 
- an expression in postfix notation
OUT:
- the expression result
*/
#include <bits/stdc++.h>

using namespace std;

int postfix(string s) {
	stack<int> OpStack;
	istringstream iss(s);
	string op, ops = "+-*/";
	int result = 0, op1, op2;
	while (iss >> op)
	{
		if (ops.find(op) != string::npos)
		{
			op2 = OpStack.top(); OpStack.pop();
			op1 = OpStack.top(); OpStack.pop();
			switch (op[0]) {
			case '+': result = op1 + op2; break;
			case '-': result = op1 - op2; break;
			case '*': result = op1 * op2; break;
			case '/': result = op1 / op2; break;
			}
		}
		else
			result = stoi(op);
		OpStack.push(result);
	}
	return OpStack.top();
}

void check(string s, int expected) {
	int actual = postfix(s);
	cout << boolalpha;
	cout << (actual == expected ? "PASS" : "FAIL") << " "
		<< " ( " << expected << " / " << actual << ")" << endl;
}

int main()
{
	check("3 4 +", 7);
	check("5 2 -", 3);
	check("3 5 *", 15);
	check("15 5 /", 3);
	check("15 7 1 1 + - / 3 * 2 1 1 + + -", 5);
	system("pause");
	return 0;
}
