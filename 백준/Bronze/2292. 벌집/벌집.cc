#include <stdio.h>

/*
n=1; 1
n=2; 6
n=3; 12
n--> 6(n-1)개
*/
int sum[1000000];
int main()
{
	int n;
	int i, j;
	int chk = 0;
	sum[1] = 1;
	scanf("%d", &n);
	if ( n == 1 )
	{
		printf("1");
		return 0;
	}
	for ( i = 2; i < 500000; i++ )
	{
		sum[i] = sum[i-1] + 6*(i - 1);

	}
	for ( i = 1; i < 500000; i++ )
	{
		if ( n - sum[i] > 0 && n - sum[i + 1] <= 0 )
		{
			printf("%d", i+1);
			return 0;
		}

	}
	return 0;
}