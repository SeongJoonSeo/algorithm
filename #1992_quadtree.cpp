#include <iostream>
#include <vector>
#include <cmath>
#include <string>

using namespace std;

//리펙터링 전. 성능 개선을 위해 모두 같음을 알 수 있는 방법은, 함수를 두개로 쪼개는 것이다. 하나는 모두 0인지 알아보는 것이고, 다른 하나는 모두 1인지 알아보는 함수이다.
//그에 대한 구현은 bitmask를 이용하여 할 수 있다.
bool allSame(vector<string>& v, unsigned int start, unsigned int end, unsigned int a, unsigned int b) {
	bool ret = true;
	char c = v[start][a];
	for (unsigned int it = start; it != end; it++) 
		for (int i = a; i < b; i++) 
			if (v[it][i] != c)
				ret = false;
	return ret;
}

void solve(vector<string>& v, unsigned int start, unsigned int end, unsigned int a, unsigned int b) {
	//만약 영상이 섞여있지 않다면
	if (allSame(v, start, end, a, b) || start+1 == end) {
		cout << v[start][a];
		return;
	}//만약 섞여있다면 () 를 출력해주고 다시 Divide&Conquer
	else {
		cout << "(";
		solve(v, start , start + (end-start)/2, a, a + (b - a) / 2);
		solve(v, start , start + (end-start)/2, a + (b - a) / 2, b);
		solve(v, start + (end-start)/2, end, a, a + (b - a) / 2);
		solve(v, start + (end-start)/2, end, a + (b - a) / 2, b);
		cout << ")";				
	}
}

int main() {
	int n;
	string input;
	vector<string> v;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> input;
		v.push_back(input);
	}
	solve(v, 0, n, 0, n);
	
	return 0;
}