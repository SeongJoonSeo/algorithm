/*
2016.8.16
서성준
알고리즘 연습문제 - Algorithm & STL
#10866 덱 - (Algorithm & STL 문제집, 김강산 픽)
*/


#include <iostream>
#include <vector>
#include <deque>
#include <string>

using namespace std;

int main() {
	deque<int> d;
	int n,input;
	cin >> n;
	string cmd;
	for (int i = 0; i < n; i++) {
		cin >> cmd;
		if (cmd == "push_front") {
			cin >> input;
			d.push_front(input);
		}
		else if (cmd == "push_back") {
			cin >> input;
			d.push_back(input);
		}
		else if (cmd == "pop_front") {
			if (d.empty())
				cout << -1 << endl;
			else {
				cout << d.front() << endl;
				d.pop_front();
			}
		}
		else if (cmd == "pop_back") {
			if (d.empty())
				cout << -1 << endl;
			else {
				cout << d.back() << endl;
				d.pop_back();
			}
		}
		else if (cmd == "size") {
			cout << d.size() << endl;
		}
		else if (cmd == "empty") {
			if (d.empty())
				cout << 1 << endl;
			else {
				cout << 0 << endl;
			}
		}
		else if (cmd == "front") {
			if (d.empty())
				cout << -1 << endl;
			else {
				cout << d.front() << endl;
			}
		}
		else if (cmd == "back") {
			if (d.empty())
				cout << -1 << endl;
			else {
				cout << d.back() << endl;
			}
		}

	}
	return 0;
}