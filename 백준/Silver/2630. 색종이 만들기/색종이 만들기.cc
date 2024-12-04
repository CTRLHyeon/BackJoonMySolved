#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#include <math.h>
#define MAX(a,b) (a>b)?a:b;
#define MIN(a,b) (a<b)?a:b;
using namespace std;
int w = 0, b = 0;
void division(int size, int startx, int starty, vector<vector<int>> paper);
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n;
	cin >> n;
	vector <vector<int>> paper(n, vector<int>(n, 0));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> paper[i][j];
	division(n, 0, 0, paper);
	cout << w << '\n' << b << '\n';
}

void division(int size, int startx,int starty, vector<vector<int>> paper) {
	int white = 0, blue = 0;
	//printf("\n\nCURRENT: %d %d %d\n", size, startx, starty);
	int dy[4] = { starty, starty, starty + size / 2, starty + size / 2 };
	int dx[4] = { startx, startx + size / 2 , startx, startx + size / 2 };
	for (int i = starty; i < size + starty; i++) {
		for (int j = startx; j < size + startx; j++) {
			if (paper[i][j]) blue++;
			else white++;
		}
	}
	//printf("w: %d, b: %d\n", white, blue);
	if (white == size * size) {
		w++;
		//printf("@@@w++, %d %d %d \n", size, startx, starty);
	}
	else if (blue == size * size) {
		b++;
		//printf("@@@b++, %d %d %d \n", size, startx, starty);
	}
	else {
		for (int i = 0; i < 4; i++) {
			division(size / 2, dx[i], dy[i], paper);
		}
	}
}