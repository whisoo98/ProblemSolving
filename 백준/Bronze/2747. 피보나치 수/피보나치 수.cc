#include<stdio.h>
int arr[45] = { 0, 1, };
int main() {
	int i;
	int num;
	scanf("%d", &num);
	for (i = 0; i < 45; i++) {
		arr[i + 2] = arr[i + 1] + arr[i];
	}
	printf("%d", arr[num]);




	return 0;
}