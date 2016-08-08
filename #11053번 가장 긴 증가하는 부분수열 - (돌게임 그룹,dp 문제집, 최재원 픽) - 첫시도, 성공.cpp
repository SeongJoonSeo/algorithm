/*
2016.8.8
서성준
알고리즘 연습문제 - dp
#11053번 가장 긴 증가하는 부분수열 - (돌게임 그룹,dp 문제집, 최재원 픽) - 첫시도
*/


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//a는 수열을 저장하는 vector.
vector<int> a;
//dp[i] 에는 i번째 숫자까지의 가장 긴 증가하는 부분 수열의 길이가 저장되어 있다.
vector<int> dp;

int solve(int index) {
	if (index < 0)
		return 0;
	int& ret = dp[index];
	if (ret != -1)
		return ret;
	int i = index - 1,m = 0;
	while (i>=0) {
		if (dp[i] != -1)
			m = max(m, dp[i]);
		else if (a[i] < a[index])
			m = max(m, solve(i));
		i--;
	}
	return ret = m + 1;
}

int main() {
	int n,input;
	cin >> n;
	dp.assign(n, -1);
	for (int i = 0; i < n; i++) {
		cin >> input;
		a.push_back(input);
	}
	for (int i = n - 1; i >= 0; i--) {
		if (dp[i] == -1)
			solve(i);
	}
	sort(dp.begin(), dp.end());
	cout << dp.back();
	return 0;
}