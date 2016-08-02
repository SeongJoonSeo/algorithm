/*
#11399 ATM - Greedy Algorithm 연습문제집 - 최재원(픽)
2016.8.2
서성준
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	vector<int> p;
	int n,input;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> input;
		p.push_back(input);
	}
	
	sort(p.begin(), p.end());
	int sum = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			sum += p[j];
		}
	}

	cout << sum;

	return 0;
}