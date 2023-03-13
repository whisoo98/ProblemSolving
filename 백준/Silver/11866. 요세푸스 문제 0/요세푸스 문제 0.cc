#include<stdio.h>
#include<queue>
using namespace std;
queue<int> q;

int main() {

	int m, n;
	int i;
	int chk;
	scanf("%d %d", &n, &m);
	for (i = 0; i < n; i++) {
		q.push(i+1);
	}
	printf("<");
	while (0 == 0) {
		chk = 1;
		if (q.size() == 1) {
			printf("%d>", q.front());
			break;
		}
		while (0 == 0) {
			if (chk == m) {
				printf("%d, ", q.front());
				q.pop();
				break;
			}
			else {
				q.push(q.front());
				q.pop();
				chk++;
			}
		}


	}
	return 0;
}