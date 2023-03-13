#include<stdio.h>

void eut(int a, int b, int c, int d) {
	int sum = a + b + c + d;
	if (sum == 0) printf("D\n");
	else if (sum == 1) printf("C\n");
	else if (sum == 2) printf("B\n");
	else if (sum == 3) printf("A\n");
	else printf("E\n");
}
int main() {
	int i;
	int a[3], b[3], c[3], d[3];
	for (i = 0; i<3; i++) {
		scanf("%d %d %d %d", &a[i], &b[i], &c[i], &d[i]);
	//	eut(a[i], b[i], c[i], d[i]);
	}
	for (i = 0; i<3; i++) {
		//scanf("%d %d %d %d", &a[i], &b[i], &c[i], &d[i]);
		eut(a[i], b[i], c[i], d[i]);
	}

	return 0;
}