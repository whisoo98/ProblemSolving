#include<stdio.h>
/*첫째 줄에는 별 1개, 둘째 줄에는 별 2개, N번째 줄에는 별 N개를 찍는 문제  */
int main() {

	int i, j,N;
	scanf("%d", &N);
	
	for (i = 1; i <= N; i++) {
		for (j = 1; j <= i; j++)
			printf("*");
		printf("\n");
	}




	return 0;
}