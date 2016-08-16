/*
2016.8.16
서성준
알고리즘 연습문제 - Algorithm & STL
#11723 집합 - (Algorithm & STL 문제집, 김강산 픽)
*/


#include <iostream>
#include <vector>
#include <set>//for set
#include <functional>//for comparing
#include <string>//for command

using namespace std;

int main() {
	int n,input;
	string cmd;
	set<int> s,s2,s3;
	vector<bool> b,c,d;
	b.assign(21, false);
	c.assign(21, true);
	d.assign(21, true);
	for (int i = 1; i < 21; i++)
		s2.insert(i);
	set<int>::iterator it;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		cin >> cmd;
		if (cmd == "add") {
			cout << "d";
			scanf("%d", &input);
			//it = s.find(input);			
			if (!b[input]) {
				s.insert(input);
				b[input] = true;
			}
		}
		else if (cmd == "check") {
			scanf("%d", &input);
			//it = s.find(input);
			if (!b[input])
				printf("%d\n", 0);
			else
				printf("%d\n", 1);
		}
		else if (cmd == "remove") {
			scanf("%d", &input);
			it = s.find(input);
			if (!b[input]) {
				s.erase(it);
				b[input] = false;
			}
		}
		else if (cmd == "toggle") {
			scanf("%d", &input);
			it = s.find(input);
			if (it != s.end()) {
				s.erase(it);
				b[input] = false;
			}
			else {
				s.insert(input);
				b[input] = true;
			}
		}
		else if (cmd == "all") {
			s = s2;
			b = c;
		}
		else if (cmd == "empty") {
			s = s3;
			b = d;
		}
	}
	return 0;
}
