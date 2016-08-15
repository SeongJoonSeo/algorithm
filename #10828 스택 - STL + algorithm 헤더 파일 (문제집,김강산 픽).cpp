/*
2016.8.15
서성준
#10828 스택 - STL + algorithm 헤더 파일 (문제집,김강산 픽)
*/

#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(){
	stack<int> s;
	int n;
	cin >> n;
	string str;
	int input;
	for(int i=0;i<n;i++){
		cin >> str;
		if(str == "push"){
			cin >> input;
			s.push(input);
		}
		else if(str == "top"){
			if(!s.empty())
				cout << s.top() << endl;
			else
				cout << -1 << endl;
		}
		else if(str == "size"){
			cout << s.size() << endl;
		}
		else if(str == "empty"){		
			if(s.empty())
				cout << 1 << endl;
			else
				cout << 0 << endl;
		}
		else if(str == "pop"){
			if(!s.empty()){
				cout << s.top() << endl;
				s.pop();
			}
			else
				cout << -1 << endl;
		}
	}
	return 0;
}