/*
Implement binary addition using Finite-state-machine
IN: 
- two binary numbers
OUT:
- the sum of the numbers
*/
#include <bits/stdc++.h>

using namespace std;

enum states { b0c0, b0c1, b1c0, b1c1 };
typedef pair<bool, bool> bits;
typedef pair<states, bits> state_input;

class FSM_adder {
private:
	states state;
	map<state_input, states> FSM_table;

	__int64 VtoB(vector<bool> digits) {
		int result = 0, power = 1;
		for (size_t i = 0; i < digits.size(); i++)
		{
			result += digits[i] * power;
			power <<= 1;
		}
		return result;
	}

	vector<bool> BtoV(__int32 N) {
		vector<bool> result(32);
		for (size_t i = 0; i < result.size(); i++)
		{
			result[i] = N & 1;
			N >>= 1;
		}
		return result;
	}

	bool feedPair(bool a, bool b) {
		state = FSM_table[make_pair(state, make_pair(a, b))];
		return state == b1c0 || state == b1c1;
	}

	bool isCarry() { return state == b0c1 || state == b1c1; }
public:
	FSM_adder() : state(b0c0) {
		bits b00 = make_pair(0, 0);
		bits b01 = make_pair(0, 1);
		bits b10 = make_pair(1, 0);
		bits b11 = make_pair(1, 1);
		FSM_table[make_pair(b0c0, b00)] = b0c0;
		FSM_table[make_pair(b0c0, b10)] = b1c0;
		FSM_table[make_pair(b0c0, b01)] = b1c0;
		FSM_table[make_pair(b0c0, b11)] = b0c1;
		FSM_table[make_pair(b1c0, b00)] = b0c0;
		FSM_table[make_pair(b1c0, b10)] = b1c0;
		FSM_table[make_pair(b1c0, b01)] = b1c0;
		FSM_table[make_pair(b1c0, b11)] = b0c1;
		FSM_table[make_pair(b0c1, b00)] = b1c0;
		FSM_table[make_pair(b0c1, b10)] = b0c1;
		FSM_table[make_pair(b0c1, b01)] = b0c1;
		FSM_table[make_pair(b0c1, b11)] = b1c1;
		FSM_table[make_pair(b1c1, b00)] = b1c0;
		FSM_table[make_pair(b1c1, b10)] = b0c1;
		FSM_table[make_pair(b1c1, b01)] = b0c1;
		FSM_table[make_pair(b1c1, b11)] = b1c1;
	}

	__int64 add(__int32 a, __int32 b)
	{
		vector<bool> aV = BtoV(a);
		vector<bool> bV = BtoV(b);
		vector<bool> sumV;
		for (size_t i = 0; i < aV.size(); i++)
			sumV.push_back(feedPair(aV[i], bV[i]));
		if (isCarry())
			sumV.push_back(1);
		return VtoB(sumV);
	}
};

__int64 addFSM(__int32 a, __int32 b)
{
	FSM_adder adder;
	return adder.add(a, b);
}

void check(__int32 a, __int32 b, __int64 expected) {
	__int64 actual = addFSM(a, b);
	cout << boolalpha;
	cout << (actual == a + b && actual == expected ? "PASS" : "FAIL") << " "
		<< " ( " << expected << " / " << actual << ")" << endl;
}

int main()
{
	check(0b1100100100100, 0b100100011000, 0b10001000111100);
	system("pause");
	return 0;
}
