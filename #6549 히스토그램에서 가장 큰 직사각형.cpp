// #6549 히스토그램에서 가장 큰 직사각형

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<long long> histogram;

long long solve(int left, int right) {
	//기저 사례
	if (left == right) {
		return histogram[left];
	}
	//가운데를 나눈 다음에
	int mid = (right + left) / 2;
	//분할정복
	long long ret = max(solve(left, mid), solve(mid + 1, right));
	//가운데에 걸친 답이 나올 경우를 계산한다.
	//lo는 가운데 선의 왼쪽, hi는 오른쪽. 가운데에 걸친 사각형은 이 두 사각형을 모두 포함한다.
	//이때 넓이를 계산하려면 어쩔수 없이 낮은 사각형을 골라야 한다.
	int lo = mid, hi = mid + 1;
	long long height = min(histogram[lo], histogram[hi]);
	//너비 2인 사각형과 분할정복한 사각형 중 최대를 고른다.
	ret = max(ret, height * 2);
	//너비를 넓혀간다.
	while (left < lo || hi < right) {
		//항상 높이가 높은걸 골라가며 확장한다.
		//lo==left를 먼저 검사하기 때문에 만약에 lo==left이라면 histogram[lo-1]은 검사하지 않는다.
		//그렇기 때문에 out of index error는 피할 수 있다.
		//만약 lo!=left 이면 오른쪽이 더 클때 오른쪽으로 확장시킨다.
		if (hi < right && (lo == left || histogram[lo - 1] < histogram[hi + 1])) {
			++hi;
			height = min(height, histogram[hi]);
		}
		else {
			--lo;
			height = min(height, histogram[lo]);
		}
		//확장 후의 사각형 넓이는
		ret = max(ret, height*(hi - lo + 1));
	}
	return ret;
}

int main() {
	int input,temp;
	cin >> input;
	while (input != 0) {
		for (int i = 0; i < input; i++) {
			cin >> temp;
			histogram.push_back(temp);
		}		
		cout << solve(0, histogram.size() - 1) << endl;
		histogram.clear();
		cin >> input;
	}
	return 0;
}