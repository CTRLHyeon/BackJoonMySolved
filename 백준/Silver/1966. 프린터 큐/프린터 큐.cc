#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <math.h>
#include <string.h>
#include <limits.h>
using namespace std;

struct doc {
	int index;
	int val;
};

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin >> T;
	while (T--) {
		int n, m, target;
		cin >> n >> m;	//n: 인덱스의 갯수, m: 원하는 인덱스
		queue<doc> q;
		vector<int> cnt(10, 0);	//계수정렬
		for (int i = 0; i < n; i++) {
			int imp;
			cin >> imp;
			if (i == m) {
				target = imp;
			}
			q.push({ i,imp });
			cnt[imp]++;
		}	//입력 끝
		int result = 0;
		while (1) {

			int important = 0;	//중요도가 더 높은 문서의 갯수
			for (int i = q.front().val+1; i < 10;i++) {	//중요도가 더 높은 문서의 갯수 구하기
				important += cnt[i];
			}
			//cout << "현재 important: " << important << ", " ;
			if (q.front().index == m) {	//프론트가 m 문서이면
				//cout << "현재 인덱스는 m이구요 ";
				if (important != 0) {	//중요도가 더 높은 문서가 존재하면
					doc temp = q.front();	
					q.pop();		//원래꺼 빼고 다시 넣음
					q.push(temp);
					//cout << temp.index << ',' << temp.val << "빼고 다시 넣었어요\n";
				}
				else {					//중요도가 더 높은 문서가 존재하지 않으면
					result++;
					cout << result << '\n';
					break;
				}
			}
			else {			//원하는 문서가 아니면
				//cout << "현재 인덱스는 m이 아니구요 ";
				if (important == 0) {		//중요도가 가장 높으면
					//cout << "중요도가 가장 높아서 뺐어요\n";
					cnt[q.front().val]--;
					q.pop();
					result++;
					
				}
				else {						//가장 높지 않으면
					//cout << "가장 높지 않아서 빼고 다시 넣을게요\n";
					doc temp = q.front();
					q.pop();
					q.push(temp);
				}
				//cout << "현재 front: [" << q.front().index << q.front().val << "], back: [" << q.back().index << q.back().val << "\n\n";
			}

		}
	}
}
