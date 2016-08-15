/*
2016.8.15
서성준
#10845 큐 - STL + algorithm 헤더 파일 (문제집,김강산 픽)
*/

#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main(){
	queue<int> q;
	int n;
	cin >> n;
	string str;
	int input;
	for(int i=0;i<n;i++){
		cin >> str;
		if(str == "push"){
			cin >> input;
			q.push(input);
		}
		else if(str == "front"){
			if(!q.empty())
				cout << q.front() << endl;
			else
				cout << -1 << endl;
		}
		else if(str == "back"){
			if(!q.empty())
				cout << q.back() << endl;
			else
				cout << -1 << endl;
		}
		else if(str == "size"){
			cout << q.size() << endl;
		}
		else if(str == "empty"){		
			if(q.empty())
				cout << 1 << endl;
			else
				cout << 0 << endl;
		}
		else if(str == "pop"){
			if(!q.empty()){
				cout << q.front() << endl;
				q.pop();
			}
			else
				cout << -1 << endl;
		}
	}
	return 0;
}