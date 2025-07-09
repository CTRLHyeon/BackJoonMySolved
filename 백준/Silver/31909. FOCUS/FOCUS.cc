#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <string>
using namespace std;
vector<int> result(8);
void swap(int, int);

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n;
	cin >> n;

	for (int i = 0; i < 8; i++) result[i] = i;

	while (n--) {	//n번 수행
		int cmd;
		cin >> cmd;	//숫자를 입력받아서
		vector<int> keys;

		for (int i = 0; i < 8; i++) {	//비트마스?킹 해서 1들을 모두 벡터에 푸쉬백
			if (cmd % 2)
				keys.push_back(i);
			cmd = cmd >> 1;
		}

		if (keys.size() != 2) continue;	//유효한 숫자가 아니면 컷
		else swap(keys[0], keys[1]);
	}

	int m;
	cin >> m;
	cout << result[m];
}

void swap(int x, int y) {
	int temp = result[x];
	result[x] = result[y];
	result[y] = temp;
}