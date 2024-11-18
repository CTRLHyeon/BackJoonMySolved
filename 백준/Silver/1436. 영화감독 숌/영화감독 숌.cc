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
int sixcount(int n);
bool cmp(int a, int b) { return a > b; };
int MAX(int a, int b) { return (a < b) ? b : a; }
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n;
	int count = 0;

	int i = 666; 
	while (count < n) {
		if (sixcount(i)==1) {
			count++;
			//printf("현재 수: %d\n", i);
		}
		i++;

	}
	printf("%d", --i);
}

int sixcount(int n) {

	int six = 0;
	int jari = 1;

	while (pow(10, jari) <= n)
		jari++;

	int temp = n;
	int arr[100] = { 0 };

	int j = 0;
	for (int i = jari - 1; i >= 0; i--) {
		arr[j] = temp / pow(10, i);
		temp -= arr[j] * pow(10, i);
		j++;
	}

	

	for (int i = 0; i < jari; i++) {
		if (arr[i] == 6 && arr[i + 1] == 6 && arr[i + 2] == 6) {
			six = 1;
			break;
		}
	}

	return six;
}