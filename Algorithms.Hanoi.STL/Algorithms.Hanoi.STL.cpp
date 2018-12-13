#include <bits/stdc++.h>

using namespace std;

class HanoiTower {
private:
	stack<int> tower;
public:
	string name;
	HanoiTower(string _name) : name(_name) {}
	int Get() {
		int result = tower.top();
		tower.pop();
		return result;
	}
	void Put(int val) { tower.push(val); }
	void Print()
	{
		cout << name << ": ";
		while (!tower.empty())
			cout << Get() << " ";
		cout << endl;
	}
};

void hanoi(int n, HanoiTower &left, HanoiTower &middle, HanoiTower &right)
{
	if (n == 0) return;
	hanoi(n - 1, left, right, middle);
	right.Put(left.Get());
	cout << left.name << "->" << right.name << endl;
	hanoi(n - 1, middle, left, right);
}

int main() {
	HanoiTower left("left"), middle("middle"), right("right");
	int n = 6;
	for (int i = n; i > 0; i--)
		left.Put(i);
	hanoi(n, left, middle, right);
	right.Print();
	system("pause");
	return 0;
}
