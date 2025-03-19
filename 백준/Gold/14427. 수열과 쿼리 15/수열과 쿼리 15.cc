#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <math.h>
#include <string.h>
#include <limits.h>
using namespace std;

struct num {
	int index;		//인덱스
	int num;	//값
};
struct cmp {
	bool operator()(num a, num b) {
		if (a.num == b.num)
			return a.index > b.index;
		else return a.num > b.num;
	}
};
int main(){
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n;
	priority_queue<num, vector<num>, cmp> pq;
	vector<num> origin(n+1);

	for (int i = 1; i <= n; i++) {	//수열 초기화
		cin >> origin[i].num;
		origin[i].index = i;
		pq.push(origin[i]);
	}

	//for (int i = 1; i <= n; i++) {
	//	cout << pq.top().index << '/' << pq.top().num << '\n';
	//	pq.pop();
	//}


	int q;
	cin >> q;
	while (q--) {
		int cmd;
		cin >> cmd;
		if (cmd == 1) {
			int a, b;
			cin >> a >> b;	//a: 인덱스, b: 바꿀 수
			origin[a].num = b;
			pq.push(origin[a]);
		}
		else {
			checkpoint:
			if (pq.top().num != origin[pq.top().index].num) {
				pq.pop();
				goto checkpoint;
			}
			else {
				cout  /* << "정답!!! "*/ << pq.top().index << '\n';
				
			}
		}
	}
}