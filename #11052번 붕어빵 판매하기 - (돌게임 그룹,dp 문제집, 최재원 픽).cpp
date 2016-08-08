/*
2016.8.8
서성준
알고리즘 연습문제 - dp
#11052번 붕어빵 판매하기 - (돌게임 그룹,dp 문제집, 최재원 픽)
*/


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//price는 붕어빵 가격을 저장하는 vector.
vector<int> price;
//dp[i]는 i개를 팔아서 얻을 수 있는 최대 수익.
vector<int> dp;

//p개를 살 때의 최대 수익
int solve(int p) {
	if (p == 1)
		return price[p];
	int& ret = dp[p];
	if (ret != -1)
		return ret;
	int m = -1;
	for (int i = 1; i < p; i++) {
		m = max(price[p], price[i] + solve(p - i));
		ret = max(ret, m);
	}
	return ret;
}

int main() {
	int n,input;
	cin >> n;
	dp.assign(n+1, -1);
	//price[0]은 0개를 팔 때 세트 매뉴의 가격이다. 0개 이므로 0원이다.
	price.push_back(0);
	for (int i = 0; i < n; i++) {
		cin >> input;
		//세트 매뉴의 가격이다.
		price.push_back(input);
	}
	cout << solve(n);
	return 0;
}