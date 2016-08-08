/*
2016.8.8
서성준
알고리즘 연습문제 - dp
#1904번 01타일 - (돌게임 그룹,dp 문제집, 최재원 픽)
*/


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<long long> dp;

int main() {
	int n;
	cin >> n;
	dp.assign(n+1, -1);
	dp[0] = 0; dp[1] = 1; dp[2] = 2;
	for (int i = 3; i < n + 1; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
		if (dp[i] > 15746)
			dp[i] %= 15746;
	}
	cout << dp[n];
	return 0;
}