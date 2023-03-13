#include<stdio.h>

int main() {

	int i, j;
	int n;
	char arr[100][100] = {0};
	scanf("%d", &n);
	for (i = n-1; i >=0; i--) {
		for (j = n - 1; j >= n - 1 - i; j--) {
			arr[i][j] = '*';


		}
	}
	for (i = 0; i < n; i++) {
		for (j =0; j<n ; j++) {
			if (arr[i][j]==0)
                printf(" ");
            else printf("%c",arr[i][j]);


		}
		printf("\n");
	}

	



	return 0;
}
