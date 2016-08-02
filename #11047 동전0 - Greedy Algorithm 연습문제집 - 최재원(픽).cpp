/*
#11047 동전0 - Greedy Algorithm 연습문제집 - 최재원(픽)
2016.8.2
서성준
*/

#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n;
	long long k, input, count=0;
	vector<long long> coins;
	cin >> n >> k;
	int index;
	for (int i = 0; i < n; i++) {
		cin >> input;
		if (input > k)
			index = i - 1;
		else
			index = n - 1;
		coins.push_back(input);
	}

	for (int i = index; i >= 0; i--) {
		if (k / coins[i] > 0) {
			count += k / coins[i];
			k %= coins[i];
			if (k == 0)
				break;
		}
	}
	cout << count;
	return 0;
}