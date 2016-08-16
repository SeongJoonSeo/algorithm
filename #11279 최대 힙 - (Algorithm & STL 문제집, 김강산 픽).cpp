/*
2016.8.16
서성준
알고리즘 연습문제 - Algorithm & STL
#11279 최대 힙 - (Algorithm & STL 문제집, 김강산 픽)
*/


#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;

int main() {
	int n,input;
	//1<=n<=100000
	cin >> n;
	priority_queue<int> v;
	/*make_heap(v.begin(), v.end());*/
	for (int i = 0; i < n; i++) {
		scanf("%d", &input);
		if (input == 0)
		{
			if (v.empty())
				printf("%d\n", 0);
			else {
				printf("%d\n", v.top());
				/*pop_heap(v.begin(), v.end());*/
				v.pop();
			}
		}
		else {
			v.push(input);
			/*push_heap(v.begin(), v.end());*/
		}
	}
	return 0;
}
