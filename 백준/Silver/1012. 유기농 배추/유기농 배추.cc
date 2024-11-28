#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

int dy[4] = {-1,1,0,0};
int dx[4] = { 0,0,-1,1 };
int n, m, cnt;
vector<vector<int>> map(50, vector<int>(50, 0));
vector<vector<int>>visited(50, vector<int>(50, 0));

void dfs(int a, int b);

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int cnt = 0;
        int bechu;
        cin >> m >> n >> bechu;
        map= vector<vector<int>>(50, vector<int>(50, 0));
        visited = vector<vector<int>>(50, vector<int>(50, 0));
        for (int i = 0; i < bechu; i++) {
            int x, y;
            cin >> x >> y;
            map[y][x] = 1;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                //cout << "와일" << i << j << '\n';
                if (map[i][j] && !visited[i][j]) {
                    dfs(i, j);
                    cnt++;
                }
            }
        }
        cout << cnt << '\n';
    }
}

void dfs(int a, int b) {
    visited[a][b] = 1;
    for (int i = 0; i < 4; i++) {
        int ny = a + dy[i], nx = b + dx[i];
        if (ny < 0 || nx < 0 || ny >= n || nx >= m) //범위 벗어나면 컨티뉴
            continue;
        if (!map[ny][nx])   //배추 안 심어져있으면
            continue;
        if (visited[ny][nx])    //방문했으면
            continue;
        //cout << "디애프애스" << ny << nx << '\n';
        dfs(ny, nx);
    }
}