#include<stdio.h>

int main() {

	struct Square {

		int n=0;
	};
	typedef Square S;
	S q1, q2, q3, q4, axis;

	int i, m;
	int x, y;
	scanf("%d", &m);
	for (i = 1; i <= m; i++) {
		scanf("%d %d", &x, &y);
		if (x == 0 || y == 0) axis.n++;
		else if (x > 0 && y > 0) q1.n++;
		else if (x > 0 && y < 0) q4.n++;
		else if (x < 0 && y > 0) q2.n++;
		else if (x < 0 && y < 0) q3.n++;
	}
	printf("Q1: %d\n", q1.n);
	printf("Q2: %d\n", q2.n);
	printf("Q3: %d\n", q3.n);
	printf("Q4: %d\n", q4.n);
	printf("AXIS: %d", axis.n);




	return 0;
}