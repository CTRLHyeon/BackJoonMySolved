#include <iostream>
#include <math.h>
using namespace std;
char map[2187][2187];

void recursive(int x, int y, int n);

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n;
	cin >> n;

	for (int i = 0; i < 2187; i++) {	//init
		for (int j = 0; j < 2187; j++) {
			map[i][j] = '*';
		}
	}
	recursive(0, 0, 2187/3);


	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << map[i][j];
		}
		cout << '\n';
	}
}
//0 0 3에선 첫 9x9에 3x3만큼 (0,0) (9,9)
//1 0 3에선 두번쨰 9x9에서 3x3만큼 (9,0) (18,9)

void recursive(int x, int y, int n) {
	
	x += n;
	y += n;
	for (int i = x; i < x + n; i++) {
		for (int j = y; j < y + n; j++) {
			map[i][j] = ' ';
		}
	}
	x -= n;
	y -= n;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 0 + 3; j++) {
			if (n == 1) break;
			recursive(i*n+x, j*n+y, n / 3);
		}
	}
}