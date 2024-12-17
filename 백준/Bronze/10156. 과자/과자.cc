#include <iostream>
using namespace std;
int main(){
    int a,b,c;
    cin >>a>>b>>c;
    if (a*b < c){
        cout << '0';
            return 0;
    }
    else cout <<a*b-c;
}