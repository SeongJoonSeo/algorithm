#include <iostream>

using namespace std;

int moveNum = 0;

void solve(int n, int from, int to) {
	int temp;
	if (n == 1)
		cout << from << " " << to << endl;
	else {
		temp = 6 - from - to;
		solve(n-1, from, temp);
		cout << from << " " << to << endl;
		solve(n-1, temp, to);
	}
	moveNum++;
}

int main() {
	int n;
	cin >> n;
	solve(n, 1, 3);
	cout << moveNum;

	return 0;
}