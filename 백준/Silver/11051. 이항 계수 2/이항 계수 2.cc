#include <stdio.h>

long long arr[1005][1005];
int main()
{
	arr[0][0] = 1;
	int i, j;
	int n, r;
	scanf("%d %d",&n,&r);
	for ( i = 1; i <= n; i++ )
	{
		arr[i][0] = 1;
		for ( j = 1; j <= i; j++ )
		{
			arr[i][j] = (arr[i - 1][j-1] + arr[i-1][j])%10007;
		}
	}
	printf("%lld",arr[n][r]);
	return 0;
}