#include<cstdio>

int answer[10];
int main() {

	int n;
	scanf("%d", &n);
	int i, j;
	for (i = 0; i<10; i++) answer[i] = i % 5 + 1;
	for (i = 1; i <= n; i++) {
		int chk = 0;
		for (j = 0; j<10; j++) {
			int temp;
			scanf("%d", &temp);
			if (temp == answer[j]) chk++;
		}
		if (chk == 10) printf("%d\n",i);
	}
	return 0;
}