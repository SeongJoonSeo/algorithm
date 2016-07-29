#include <iostream>
#include <vector>

using namespace std;

vector<vector<int> > table;

int one, zero, negative;

class Point {
public:
	int x;
	int y;
	Point(int a, int b)
		: x(a), y(b) {}
};

//O(n^2)
bool allSame(Point start, Point end) {
	bool ret = true;
	int first = table[start.y][start.x];
	for (int i = start.y; i < end.y; i++)
		for (int j = start.x; j < end.x; j++)
			if (first != table[i][j])
				ret = false;
	return ret;
}

void solve(Point start, Point end) {
	if (allSame(start, end) ){//|| start.x+1 == end.x
		if (table[start.y][start.x] == 0)
			zero++;
		else if (table[start.y][start.x] == 1)
			one++;
		else
			negative++;
	}
	else {
		int deltaX = (end.x - start.x) / 3;
		int deltaY = (end.y - start.y) / 3;

		solve(Point(start.x, start.y), Point((start.x + deltaX), start.y + deltaY));
		solve(Point((start.x + deltaX), start.y), Point((start.x + deltaX * 2), start.y + deltaY));
		solve(Point((start.x + deltaX * 2), start.y), Point(end.x, start.y + + deltaY));

		solve(Point(start.x, start.y + deltaY), Point((start.x + deltaX), start.y + deltaY * 2));
		solve(Point((start.x + deltaX), start.y + deltaY), Point((start.x + deltaX * 2), start.y + deltaY * 2));
		solve(Point((start.x + deltaX * 2), start.y + deltaY), Point(end.x, start.y + deltaY * 2));

		solve(Point(start.x, start.y + deltaY * 2), Point((start.x + deltaX), end.y));
		solve(Point((start.x + deltaX), start.y + deltaY * 2), Point((start.x + deltaX * 2), end.y));
		solve(Point((start.x + deltaX * 2), start.y + deltaY * 2), Point(end.x, end.y));


	}
}

int main() {
	one = 0; zero = 0; negative = 0;
	int n;
	cin >> n;
	int input;
	table.assign(n, vector<int>(n,-2));//-2이면 아직 uninitialized
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> input;
			table[i][j] = input;
		}
	}
	Point start(0, 0);
	Point end(n, n);
	solve(start, end);

	cout << negative << endl;
	cout << zero << endl;
	cout << one << endl;

	return 0;
}