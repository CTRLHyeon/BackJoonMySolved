#include <iostream>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>

using namespace std;

int upcmp(int* a, int* b);					//퀵소트 오름차
int downcmp(int* a, int* b);				//퀵소트 내림차
void inttojari(int num, int jarisu[]);		//자릿수 배열에 저장하는거
typedef long long intt;						//롱롱 ->인뜨

//--------------------------------------------------------------------------------------------------------

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, x, set[21]={0};
	cin >> n;
	string word;
	for (int a = 0; a < n; a++) {
		//printf("\n\na: %d\n\n", a);
		cin >> word;
		//printf("go\n");
		if (word == "add") {
			cin >> x;
			set[x] = 1;
		}
		else if (word == "remove") {
			cin >> x;
			set[x] = 0;
		}
		else if (word == "toggle") {
			cin >> x;
			set[x] = (set[x] == 1) ? 0 : 1;
		}
		else if (word == "all")
			for (int i = 1; i <= 20; i++)
				set[i] = 1;
		else if (word == "empty")
			for (int i = 1; i <= 20; i++)
				set[i] = 0;
		else if (word == "check") {
			cin >> x;
			if (set[x] == 1)
				cout << "1\n";
			else
				cout << "0\n";
		}
	}
}

//--------------------------------------------------------------------------------------------------------
int upcmp(int* a, int* b) {
	return (*a - *b);
}
int downcmp(int* a, int* b) {
	return (*b - *a);
}
void inttojari(int num, int jarisu[]) {
	int jari = 0;
	int temp = num;
	for (int i = 0; pow(10, i) <= num; i++)
		jari++;
	for (int i = jari; i > 0; i--) {
		jarisu[jari-i] = temp / (int)pow(10, i - 1);
		temp -= temp / (int)pow(10, i - 1) * (int)pow(10, i - 1);
	}
}
