#include<stdio.h>
//약수의 개수가 짝수면 걍 다곱하는데???미침??? 홀수면 가운데거를 2번곱해야해


int main() {
	int N, i, j;
	int num;
	int arr[50];
	scanf("%d", &num);
	for (i = 0; i < num; i++) {
		scanf("%d", &arr[i]);
	}

	N = 1;
	int max = 1;
	int min = 1000000;
	for (i = 0; i < num; i++) {
		if (max < arr[i]) max = arr[i];
		if (min > arr[i]) min = arr[i];
	}
	printf("%d", max*min);

	/*if (num % 2 == 0) {
		for (i = 0; i < num; i++)
			N = N * arr[i];
		printf("%d", N);
	}
	else {
		for (i = 0; i < num; i++)
			N = N * arr[i];
		N = N * arr[num / 2];
		printf("%d", N);
	}
	*/
	return 0;

}