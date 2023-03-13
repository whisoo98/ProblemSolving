#include<stdio.h>

int main() {

	int ham[3];
	int drink[2];
	int min_set=4000;
	int sum[3][2];
	scanf("%d %d %d %d %d", &ham[0],&ham[1],&ham[2],&drink[0],&drink[1]);

	for (int i = 0; i <= 2; i++) {
		for (int j = 0; j <= 1; j++) {
			sum[i][j] = ham[i] + drink[j];
			if (min_set > sum[i][j]) min_set = sum[i][j];
		}
	}
	printf("%d", min_set-50);




	return 0;
}