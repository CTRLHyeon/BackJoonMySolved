#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;
bool cmp(int a, int b) { return a < b; };
int dy[4] = {-1,1,0,0};
int dx[4] = { 0,0,-1,1 };
int n, m;
vector<int>cnt;
vector<string> map(25);
vector<vector<int>>visited(25, vector<int>(25, 0));

void dfs(int a, int b);

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> map[i];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (map[i][j]=='1' && !visited[i][j]) {
                //cout << "포문" << i << j << '\n';
                cnt.push_back(0);
                dfs(i, j);
            }
        }
    }

    /*for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << visited[i][j]<<' ';
        }
        cout << '\n';
    }*/
    sort(cnt.begin(), cnt.end(), cmp);

    cout << cnt.size() << '\n';
    for (int i = 0; i < cnt.size(); i++) {
        cout << cnt[i] << '\n';
    }

}

void dfs(int a, int b) {
    visited[a][b] = cnt.size();
    cnt[cnt.size()-1]++;
    for (int i = 0; i < 4; i++) {
        int nx = b + dx[i], ny = a + dy[i];

        if (nx < 0 || ny < 0 || nx >= n || ny >= n)continue;

        if (map[ny][nx]!='1') continue;

        if (visited[ny][nx]) continue;

        //cout << "디애프애스" << a << b << '\n';
        dfs(ny, nx);
    }
}