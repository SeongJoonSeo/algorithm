#include <iostream>

using namespace std;

int main() {
	long long n, f;
	cin >> n >> f;
	long long num = n / 100;
	num *= 100;
	long long m = 987654321;
	for (int i = n; i >= num; i--)
		if (i%f == 0)
			m = i;	
	if (m != 987654321) {
		if (m % 100 < 10)
			cout << 0;
		cout << m % 100;
		return 0;
	}
	num = n / 100;
	num++;
	num *= 100;
	for (int i = n; i < num; i++)
		if (i%f == 0) {
			m = i;
			break;
		}
	if (m % 100 < 10)
		cout << 0;
	cout << m % 100;
	return 0;
}