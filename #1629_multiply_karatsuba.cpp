#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;
//num 의 자리수 올림을 처리한다.
void normalize(vector<int>& num) {
	int n = num.size();
	num.push_back(0);
	for (int i = 0; i<n; i++) {
		if (num[i]<0) {
			int borrow = (abs(num[i]) + 9) / 10;
			num[i + 1] -= borrow;
			num[i] += borrow * 10;
		}
		else {
			num[i + 1] += num[i] / 10;
			num[i] %= 10;
		}
	}
	while (num.size() > 1 && num.back() == 0) num.pop_back();
}

vector<int> multiply(const vector<int>& a, const vector<int>& b) {
	std::vector<int> c(a.size() + b.size() + 1, 0);
	for (int i = 0; i<a.size(); i++) {
		for (int j = 0; j<b.size(); j++) {
			c[i + j] += a[i] * b[j];
		}
	}
	normalize(c);
	return c;
}


// 10 의 거듭제곱을 shifting 해 준다.
// a = a+b*(10^k) 구현한다.
void addTo(vector<int>& a, vector<int>& b, int k) {
	for (int i = 0; i<k; i++)
		b.insert(b.begin(), 0);
	std::vector<int> c(max<int>(a.size(), b.size()) + 1, 0);
	for (int i = 0; i<c.size(); i++) {
		if (i<a.size() && i<b.size())
			c[i] = a[i] + b[i];
		else if (i >= a.size() && i<b.size())
			c[i] = b[i];
		else if (i<a.size() && i >= b.size())
			c[i] = a[i];
	}
	normalize(c);
	a = c;
}

// a>=b 라고 가정했을 때 a-=b 를 구현한다.
void subFrom(vector<int>& a, vector<int>& b) {
	std::vector<int> c(max<int>(a.size(), b.size()) + 1, 0);
	for (int i = 0; i<c.size(); i++) {
		if (i<a.size() && i<b.size())
			c[i] = a[i] - b[i];
		else if (i<a.size() && i >= b.size())
			c[i] = a[i];
	}
	normalize(c);
	a = c;
}

vector<int> karatsuba(vector<int>& a, vector<int>& b) {
	int an = a.size(); int bn = b.size();

	if (an<bn) return karatsuba(b, a);// b,a를 바꿔준다.
	if (an == 0 || bn == 0) return vector<int>();
	if (an <= 50) return multiply(a, b);
	int half = an / 2;
	std::vector<int> a0(a.begin(), a.begin() + half);
	std::vector<int> a1(a.begin() + half, a.end());
	std::vector<int> b0(b.begin(), b.begin() + min<int>(b.size(), half));
	std::vector<int> b1(b.begin() + min<int>(b.size(), half), b.end());

	std::vector<int> z2 = karatsuba(a1, b1);
	std::vector<int> z0 = karatsuba(a0, b0);
	addTo(a0, a1, 0); addTo(b0, b1, 0);
	std::vector<int> z1 = karatsuba(a0, b0);
	subFrom(z1, z0);
	subFrom(z1, z2);
	std::vector<int> ret;
	addTo(ret, z0, 0);
	addTo(ret, z1, half);
	addTo(ret, z2, half + half);
	return ret;
}

void printVector(vector<int>& v) {
	for (std::vector<int>::reverse_iterator it = v.rbegin(); it != v.rend(); it++) {
		cout << *it;
	}
	cout << endl;
}
int main() {
	int a, b, c;
	cin >> a >> b >> c;
	for (int i = 0; i < b; i++) {

	}
	return 0;
}