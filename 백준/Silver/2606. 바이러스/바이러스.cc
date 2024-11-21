#include <ctype.h>
#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#include<limits.h>
using namespace std;

//--------------------------------------------------------------------------------------------------------–--------
//-----------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------
// 오름차순 : <
// 내림차순 : >
bool cmp(int a, int b) { return a < b; };
int MIN(int a, int b) { return (a > b) ? b : a; }

void dfs(int a, vector<vector<int>> &matrix, vector<vector<int>> &visited, int size);

int main() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> mat(n + 1, vector<int>(n + 1, 0));
	vector<vector<int>> visited(n + 1, vector<int>(n + 1, 0));
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		mat[a][b] = 1;
		mat[b][a] = 1;
	}

	/*for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << mat[i][j] << ' ';
		}
		cout << '\n';
	}*/
	//cout << "\n\n";

	dfs(1, mat, visited, n);

	/*for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << visited[i][j] << ' ';
		}
		cout << '\n';
	}*/


	int cnt = 0;
	vector<int>sum(n + 1);
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= n; j++)
		{
			if (visited[i][j])
				sum[i] = 1;
		}
	}
	for (int i = 1; i <= n; i++)
		cnt += sum[i];
	cout << cnt;
}
		// 기준 행, 인접 행렬, 방문 조사 행렬, 최대크기
void dfs(int a, vector<vector<int>> &matrix, vector<vector<int>> &visited, int size) {
	for (int i = 1; i <= size; i++) {
		if (visited[a][i] == 0 && matrix[a][i]) {
			visited[i][a] = 1;
			visited[a][i] = 1;
			dfs(i, matrix, visited, size);
		}
	}
}