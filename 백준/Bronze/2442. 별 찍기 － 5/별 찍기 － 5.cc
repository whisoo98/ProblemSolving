#include<stdio.h>

int main() {

	int i, j,k;
	int n;
	scanf("%d", &n);
	int count=0;
	int chk;
	for (k = n; k >= 1; k--) {
		chk = 0;
		for (i = k; i <= n+count; i++) {
			for (j = i-1; j >= 1; j--) {
				if (chk!=0) break;
				printf(" ");
			}
			printf("*");
			chk++;
		}
		printf("\n");
		count++;
	}
	return 0;
}
