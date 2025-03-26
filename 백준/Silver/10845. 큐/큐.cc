#include <stdio.h>
#include <string.h>

int q[10000];
int front = -1;
int back = -1;
void push(int);
int pop();
int size();
int empty();
int fronts();
int backs();

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
		else if (!strcmp(cmd, "size")) {
			printf("%d\n", size());
		}
		else if (!strcmp(cmd, "empty")) {
			printf("%d\n", empty());
		}
		else if (!strcmp(cmd, "front")) {
			printf("%d\n", fronts());
		}
		else if (!strcmp(cmd, "back")) {
			printf("%d\n",backs());
		}

	}
}

void push(int n) {
	q[++back] = n;
	if (back == 0) {	//처음 넣은 경우
		front = 0;
	}
}
int pop() {
	if ((front == -1 && back == -1) || front > back)
		return -1;
	return q[front++];
}
int size() {
	if ((front == -1 && back == -1))
		return 0;
	else
		return back - front + 1;
}
int empty() {	//업슬 조건 : 둘다 -1이거나(아무것도 안넣음), 프론트가 더 크거나
	if ((front == -1 && back == -1) || front > back)
		return 1;
	else return 0;
}
int fronts() {
	if ((front == -1 && back == -1) || front > back)
		return -1;
	else return q[front];
}
int backs() {
	if ((front == -1 && back == -1) || front > back)
		return -1;
	else return q[back];
}