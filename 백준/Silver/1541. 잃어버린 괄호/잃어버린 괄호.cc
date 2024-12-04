#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#include <math.h>
#include <string.h>
#include <stdlib.h>

#define MAX(a,b) (a>b)?a:b;
#define MIN(a,b) (a<b)?a:b;
using namespace std;


int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	vector <int> num;
	vector <int> pm;
	char s[51];
	cin >> s;
	int len = strlen(s);
	int change = 0;
	for (int i = 0; i < len; i++) {
		if (s[i] == '-' && !change)
			change = 1;
		else if (s[i]=='+' && change)
				s[i] = '-';
	}
	char cmp[] = "-+";
	for (int i = 0; i < len; i++) {
		if (s[i] == '-')
			pm.push_back(1);
		else if (s[i] == '+')
			pm.push_back(0);
	}
	char *tok = strtok(s, "-+");
	while (tok != NULL) {
		num.push_back(atoi(tok));
		tok = strtok(NULL, "-+");
	}

	int result = num[0];
	for (int i = 0; i < pm.size(); i++) {
		if (pm[i] == 1)
			result -= num[i + 1];
		else
			result += num[i + 1];
	}
	cout << result;
}
