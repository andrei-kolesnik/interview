#include <bits/stdc++.h>

using namespace std;

class HanoiTower {
private:
	stack<int> tower;
public:
	string name;
	int disks;
	HanoiTower(string _name, int _disks = 0) : name(_name), disks(_disks) {
		for (int i = disks; i > 0; i--)
			Put(i);
	}
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

void hanoi(int n, HanoiTower &from, HanoiTower &through, HanoiTower &to)
{
	if (n == 0) return;
	hanoi(n - 1, from, to, through);
	to.Put(from.Get());
	cout << from.name << "->" << to.name << endl;
	hanoi(n - 1, through, from, to);
}

int main() {
	HanoiTower left("left", 6), middle("middle"), right("right");
	hanoi(left.disks, left, middle, right);
	right.Print();
	system("pause");
	return 0;
}
