#include<stdio.h>

int main() {

	int a,b,c;
	scanf("%d", &a);
	scanf("%d", &b);
	scanf("%d", &c);

	if (a + b + c != 180) printf("Error");
	else if (a == b && b == c) printf("Equilateral");
	else if (a == b || b == c || a==c) printf("Isosceles");
	else printf("Scalene");



	return 0;
}