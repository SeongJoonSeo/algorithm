//#2293번 동전1 (Dynamic Programming) 문제집 - 돌게임,최재원
//2016.8.2
//서성준

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//구하고 싶은 값에 해당하는 경우의 수를 저장해 놓는 dp array.
vector<int> coins;

//동전의 종류를 저장해 놓는다.
vector<int> price;

//구하고 싶은 값의 경우의 수를 dp array 에 저장하는 함수이다.
//재귀 호출된다. return 값으로 경우의 수를 반환한다.
int solve(int n,int sum) {
	//만약 구하고자 하는 값이 가장 낮은 단위의 동전보다 적으면 경우의 수가 0이다.
	//또는 음수면 0 -> 기저조건.
	if (n != 0 && (n < 0 || n < price.front()))
		return 0;
	if (n == 0)
		return 1;
	int& ret = coins[n];
	//이미 구해놓은 값이면 계산하지 않고 바로 반환.
	if (ret != -1)
		return 0;
	ret = 0;
	//구해놓지 않았다면 이제 계산한다.
	for (int i = 0; i < price.size(); i++) {
		ret += solve(n - price[i], sum);
	}
	return ret;
}

int main() {
	int n,k,amount;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> amount;
		price.push_back(amount);
	}
	//동전의 종류를 정렬해 놓는다. 가장 낮은 단위의 동전을 알 수 있다.
	sort(price.begin(), price.end());

	//1~10000원 까지 들어올 수 있다.
	//-1로 되어있다면 아직 초기화 되지 않은 것.
	//특별히 coins[0]=1로 초기화 해 놓는다. 해당 동전의 경우의 수는 1이기 때문이다.
	coins.assign(10001, -1);
	coins[0] = 1;

	cout << solve(k, 0);
	
	return 0;
}