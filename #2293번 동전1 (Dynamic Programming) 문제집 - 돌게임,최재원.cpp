/*
#2293번 동전1 (Dynamic Programming) 문제집 - 돌게임,최재원
2016.8.3
서성준
*/

#include <iostream>
#include <vector>

using namespace std;

//동전의 종류를 받는 coins와 구할 금액을 저장해 놓는 money cache.
vector<int> money,coins;

int main() {
	//동전의 종류 n개, 원하는 금액 k원
	int n, k, coin;
	cin >> n >> k;
	//0원의 자리까지 생각하여 k+1개 assign해 놓는다.
	//0원일 때는 어떤 동전도 사용하지 않으므로 경우의 수가 1개라고 생각하자.
	money.assign(k+1, 0);
	money[0] = 1;
	for (int i = 0; i < n; i++) {
		cin >> coin;
		coins.push_back(coin);
	}

	for (int j = 0; j < coins.size(); j++)
		for (int i = 0; i < k + 1; i++)
			if (i - coins[j] >= 0)
				money[i] += money[i - coins[j]];
	
	
	cout << money[k];

	return 0;
}