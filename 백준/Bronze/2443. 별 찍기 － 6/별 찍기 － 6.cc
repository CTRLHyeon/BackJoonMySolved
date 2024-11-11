#include <iostream>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>
using namespace std;



int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    for (int i=0; i<n; i++){
        for(int j=0; j<i; j++)
            cout << ' ';
        for (int j=2*i; j<2*n-1; j++)
            cout << '*';
            cout << "\n";
        
    }
}