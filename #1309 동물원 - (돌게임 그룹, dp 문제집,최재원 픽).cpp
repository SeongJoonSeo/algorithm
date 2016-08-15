#include <iostream>
#include <vector>

//1309 동물원 - (돌게임 그룹, dp 문제집,최재원 픽)
//2016.8.15 서성준

using namespace std;

int main(){
	int n,sum=0;
	cin >> n;
	int dp[1001][10] = {0,};
	for(int i=0;i<10;i++){
		dp[1][i]=1;
		dp[2][i]=i+1;
	}
	for(int i=3;i<1001;i++){
		for(int j=0;j<10;j++){
			if(j==0)
				dp[i][j]=1;
			sum=0;
			for(int k=1;k<i;k++)
				sum+=dp[k][j-1];
			dp[i][j]=sum+1;
		}
	}
	int result=0;
	for(int i=0;i<10;i++){
		result+=dp[n][i];
	}
	cout << result%10007;
	return 0;
}