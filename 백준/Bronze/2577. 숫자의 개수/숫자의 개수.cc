#include<stdio.h>

int chk[10];
int main() {

	int A, B, C;
	int i;
	int p;
	
	scanf("%d %d %d", &A, &B, &C);
	p = A * B*C;
	for (i = 0; i <= 9; i++) {
		if (p % 10 == 0) chk[0]=chk[0]+1;
		else if (p % 10 == 1) chk[1]++;
		else if (p % 10 == 2) chk[2]++;
		else if (p % 10 == 3) chk[3]++;
		else if (p % 10 == 4) chk[4]++;
		else if (p % 10 == 5) chk[5]++;
		else if (p % 10 == 6) chk[6]++;
		else if (p % 10 == 7) chk[7]++;
		else if (p % 10 == 8) chk[8]++;
		else if (p % 10 == 9) chk[9]++;
		p = p / 10;
		if (p == 0) break;
	}
	for (i = 0; i <= 9; i++) {
		printf("%d\n", chk[i]);
	}







	return 0;
}