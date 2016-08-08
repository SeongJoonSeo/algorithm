/*
2016.8.8
서성준
알고리즘 연습문제 - dp
#2294번 동전2 - (돌게임 그룹,dp 문제집, 최재원 픽) - 재시도, 성공
*/


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> coins,dp;

int solve(int k) {
	if (k <= 0)
		return -1;
	int& ret = dp[k];
	if (ret != -1)
		return ret;
	int m = 987654321;
	for (int i = 0; i < coins.size(); i++) {
		int val = solve(k - coins[i]);
		if (val <= 0)
			continue;
		m = min(m, val);
	}
	if (m == 987654321)
		return ret = 0;
	else
		return ret = m + 1;
}

int main() {
	int n, k, coin;
	cin >> n >> k;
	//dp array 안에 0~k원 까지 저장할 공간을 만든다.
	dp.assign(k + 1, -1);
	//동전의 종류를 입력받는다.
	for (int i = 0; i < n; i++) {
		cin >> coin;
		coins.push_back(coin);
		//만약 구하고자 하는 가격이 동전의 종류에 있는 가격이면 1가지가 최소이다.
		dp[coin] = 1;
	}
	////동전을 내림차순으로 정렬한다.
	//sort(coins.begin(), coins.end());
	//reverse(coins.begin(), coins.end());
	int result = solve(k);
	cout << result;
	return 0;
}