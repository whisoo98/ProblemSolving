#include<stdio.h>

int main() {

	int i, j;
	int sum[5] = { 0 };
	int score[4];
	int max = 0;
	int num = 0;
	for (i = 0; i <= 4; i++) {

		for (j = 0; j <= 3; j++) {
			scanf("%d", &score[j]);
			sum[i] = sum[i] + score[j];
		}
		if (max < sum[i]) {
			max = sum[i];
			num = i;
		}
	}
	printf("%d %d",num+1, max);





	return 0;
}