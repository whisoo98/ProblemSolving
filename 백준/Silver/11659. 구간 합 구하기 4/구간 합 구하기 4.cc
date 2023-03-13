#include<stdio.h>
int arr[100005];
int sum[100005];

int main()
{
	int n, m, i, j;
	//n 십만 m 십만 i,j구간	
	scanf("%d %d", &n, &m);
	for ( i = 1; i <= n; i++ )
	{
		scanf("%d", &arr[i]);
    	sum[i] = sum[i-1] + arr[i];
	}

	for( m; m>0;m-- )
	{
		scanf("%d %d", &i, &j);
		printf("%d\n", sum[j] - sum[i - 1]);
	}


	return 0;
}