#include<stdio.h>

int main() {

	int a,b,i,temp,max,min,j;
	scanf("%d %d", &a, &b);
	//최대 공약수
	if (a >= b) max = a;
	else max = b;
	for (i = 1; i <= max; i++)
		if (a%i == 0 && b%i == 0) temp = i;
	printf("%d\n",temp);

	//최소 공배수
	min = 1;
	a = a / temp;
	b = b / temp;
	min = temp * a*b;
	printf("%d", min);
	return 0;
}