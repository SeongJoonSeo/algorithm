/*
2016.8.9
서성준
알고리즘 연습문제 - dp
#1043 거짓말 - (돌게임 그룹,재밌는거 문제집, 최재원 픽)
*/


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int> > people;
vector<int> party;
vector<bool> knows;
vector<int> trueParty;

void solve(int idx) {
	vector<int>::iterator it;
	for (int i = 0; i < people.size(); i++) {
		it = find(people[i].begin(), people[i].end(), idx);
		//번호가idx인 사람이 참가하는 party를 찾았다. 그 파티번호는 i이다.
		if (it != people[i].end()) {
			//만약 그 파티에 진실이 이미 퍼졌으면 return.
			if (find(trueParty.begin(), trueParty.end(), i) != trueParty.end())
				continue;
			//지금 파티는 이제 진실이 퍼진 파티.
			trueParty.push_back(i);
			for (int j = 0; j < people[i].size(); j++) {
				if (people[i][j] != idx) {
					//사람들에게 진실을 알리고, 그 사람에 대해서 다시 재귀호출.
					knows[people[i][j]] = true;
					solve(people[i][j]);
				}
			}
		}
	}
}

int main() {
	//n명의 사람, m개의 파티
	int n, m, result;
	cin >> n >> m;
	result = m;
	//knowTruth 만큼 진실을 안다.
	int knowTruth,who;
	cin >> knowTruth;
	
	knows.assign(n+1, false);
	for (int i = 0; i < knowTruth; i++) {
		cin >> who;
		knows[who] = true;
	}
	//m개의 파티 각각에 오는 사람들을 받는다.각각 q명씩 온다.
	int q, k;
	for (int i = 0; i < m; i++) {
		//한 파티에 오는 사람의 수.
		cin >> q;
		party.clear();
		party.assign(q, 0);
		for (int j = 0; j < q; j++) {
			cin >> k;
			//1. 각 파티에 어느 사람이 왔는지 저장해놓는다.
			party[j] = k;
		}
		people.push_back(party);
	}

	//2. 진실을 아는 사람들은, 진실을 퍼트린다.
	for (int i = 0; i < people.size(); i++)
		for (int j = 0; j < people[i].size(); j++)
			if (knows[people[i][j]])
				solve(people[i][j]);			

	//3. 각 파티에 진실을 아는 사람이 있으면 과장된 이야기를 할 수 없다.
	for (int i = 0; i < people.size(); i++)
		for (int j = 0; j < people[i].size(); j++)
			if (knows[people[i][j]]) {
				result--;
				break;
			}

	cout << result;
}