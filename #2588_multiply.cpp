#include <iostream>

using namespace std;

int main(){
	int a,b,c;
	cin >> a >> b;
	c = b;
	cout << a * (b%10) << endl;
	b=b/10;
	cout << a * (b%10) << endl;
	b=b/10;
	cout << a * (b%10) << endl;
	cout << a * c << endl;

	return 0;
}