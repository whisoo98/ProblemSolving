#include<stdio.h>
//받아서 배열 정리 한다음에 공약수 나누기 재귀함수
long arr[3];//수 넣을 배열
long min;
int i;
int main() {
	int k;
	scanf("%d", &k);
	for (i = 0; i < k; i++) scanf("%ld", &arr[i]);
	if (arr[2] == 0) {
		if (arr[0] > arr[1]) min = arr[1];
		else min = arr[0];
		for (i = 1; i <= min; i++) if (arr[0] % i == 0 && arr[1] % i == 0) printf("%d\n", i);

	}
	else {
		if (arr[0] <= arr[1] && arr[0] <= arr[2]) min = arr[0];
		else if (arr[1] <= arr[0] && arr[1] <= arr[2]) min = arr[1];
		else if (arr[2] <= arr[1] && arr[2] <= arr[0]) min = arr[2];
		for (i = 1; i <= min; i++) if (arr[0] % i == 0 && arr[1] % i == 0 && arr[2]%i== 0) printf("%d\n", i);
	}


	return 0;
}