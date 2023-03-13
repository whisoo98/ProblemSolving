#include <stdio.h>

int gcd(int a, int b)
{
	if ( a%b == 0 ) return b;
	return gcd(b, a%b);
}
int arr[105];
int main()
{
	int n, m;
	int i, j;
	long long sum;
	scanf("%d", &n);
	for ( i = 0; i < n; i++ )
	{
		sum = 0;
		scanf("%d", &m);

		for ( j = 0; j < m; j++ )
		{
			scanf("%d", &arr[j]);
		}
		for ( int k = 0; k < m; k++ )
		{
			for ( int h = k + 1; h < m; h++ )
			{
				sum=sum+gcd(arr[k],arr[h]);
			}
		}
		printf("%lld\n", sum);
	}

	return 0;
}