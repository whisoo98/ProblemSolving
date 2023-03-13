#include<stdio.h>
int i, j;//for 변수
	int a, b;//상근이가 주는 수
	int temp_a;//상수가 읽는 수 ㅄ새끼
	int temp_b;//상수가 읽는 수 ㅄ새끼
int main() {
	
	scanf("%d %d", &a, &b);
	temp_a = temp_a + (a % 10) * 100;
	a = a / 10;
	temp_a = temp_a + (a % 10) * 10;
	a = a / 10;
	temp_a = temp_a + a;

	temp_b = temp_b + (b % 10) * 100;
	b = b / 10;
	temp_b = temp_b + (b % 10) * 10;
	b = b / 10;
	temp_b = temp_b + b;
	
	if (temp_a > temp_b) printf("%d", temp_a);
	else printf("%d", temp_b);





	return 0;
}