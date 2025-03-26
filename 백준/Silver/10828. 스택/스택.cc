#include <stdio.h>
#include <string.h>

int stack[10000];
int tap = -1;
void push(int);
int pop();
int top();
int empty();
int size();
int main() {
	int n;
	scanf("%d", &n);
	while (n--) {
		char cmd[10];
		scanf("%s", cmd);
		if (!strcmp(cmd, "push")) {
			int temp;
			scanf("%d", &temp);
			push(temp);
		}
		else if (!strcmp(cmd, "pop")) {
			printf("%d\n", pop());
		}
		else if (!strcmp(cmd, "top")) {
			printf("%d\n", top());
		}
		else if (!strcmp(cmd, "size")) {
			printf("%d\n", size());
		}
		else if (!strcmp(cmd, "empty")) {
			printf("%d\n", empty());
		}
	}
}
//push, pop, top, size, empty
void push(int n) {
	stack[++tap] = n;
}

int pop() {
	if (tap == -1) {
		return -1;
	}
	return stack[tap--];
}

int top() {
	if (tap >= 0)
		return stack[tap];
	else 
		return -1;
}

int size() {
	return tap + 1;
}

int empty() {
	if (tap == -1)
		return 1;
	else
		return 0;
}