#include<stdio.h>

// a_n = a_n-1 + 2*a_n-2 + 4 * a_n-3
long long int arr[95];
int main()
{
	int n,m;
	scanf("%d", &n);
	arr[1] = 1;
	arr[2] = 2;
	arr[3] = 4;
	//초기값
	int i;
	while ( n > 0 )
	{
		scanf("%d", &m);
		for ( i = 4; i <= m; i++ )
		{
			arr[i] = arr[i - 1] + arr[i - 2] +  arr[i - 3];
		}
		printf("%lld\n", arr[m]);
		n--;
	}
	return 0;
}