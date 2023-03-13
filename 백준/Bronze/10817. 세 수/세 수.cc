#include <stdio.h>

//세 정수 A, B, C가 주어진다. 이 때, 두 번째로 큰 정수를 출력하는 프로그램을 작성하시오. 
int arr[3];
int main()
{
	int a, b, c;
	int i;
	scanf("%d %d %d", &a, &b, &c);
	arr[0] = a - b;//양수면 a>b 음수면 b<a
	arr[1] = b - c;//양수면 b>c 음수면 b<c
	arr[2] = c - a;//양수면 c>a 음수면 c<a
	if ( arr[0] > 0 )//a>b
	{
		if ( arr[1] > 0 )//b>c 
			printf("%d", b);
		else //c>b
		{
			if ( arr[2] > 0 )//c>a
				printf("%d", a);
			else printf("%d", c);
		}
	}
	else//a<b
	{
		if ( arr[1] > 0 )//b>c
		{
			if ( arr[2] > 0 ) printf("%d", c);
			else printf("%d", a);
		}
		else//b<c
		{
			printf("%d", b);
		}
	}
	return 0;
}