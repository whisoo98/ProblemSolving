#include<stdio.h>

int main() {
	int i;
	int sum,min;
	int a[7];
	for(i=0;i<=6;i++)
		scanf("%d", &a[i]);
	sum = 0;
	min = 101;
		for (i = 0; i <= 6; i++) {
			if (a[i] % 2 == 1) {
				sum = sum + a[i];
				if (a[i] < min) min = a[i];
			}

		}
	if (sum == 0)
		printf("-1");
	else {
		printf("%d\n", sum);
		printf("%d", min);
	}

	return 0;
}