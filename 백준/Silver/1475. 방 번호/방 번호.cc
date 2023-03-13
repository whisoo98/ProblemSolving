#include <stdio.h>

//6+9/2
int arr[10];

int main()
{
	int N;
	int n;
	int max = 0;
	int i;
	scanf("%d", &N);
	if ( N == 0 )
	{
		printf("1");
		return 0;
	}
	while ( N )
	{
		n = N % 10;
		arr[n]++;
		N = N / 10;
	}
	arr[6] = (arr[6] + arr[9] + 1) / 2;
	arr[9] = 0;
	for ( i = 0; i <= 9; i++ )
	{
		if ( arr[i] > max ) max = arr[i];
	}
	printf("%d", max);
	return 0;
}