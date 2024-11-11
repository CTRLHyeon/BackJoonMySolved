#include <ctype.h>
#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

//bool cmp(int a, int b) {
    //return a < b;   //오름차순
//    return a > b;   //내림차순
//}


//--------------------------------------------------------------------------------------------------------–--------
//-----------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------
 struct map {
     int x;
     int y;
};
bool cmp(map a, map b) {
    if (a.y == b.y) {
        return a.x < b.x;
    }
    else return a.y < b.y;
}
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;
    vector<map>coord(n);
    for (int i = 0; i < n; i++) {
        cin >> coord[i].x >> coord[i].y;
    }
    sort(coord.begin(), coord.end(), cmp);
    for (int i = 0; i < n; i++) {
        cout << coord[i].x << ' ' << coord[i].y << '\n';
    }

    
}