#include <stdio.h>
int arr[1000005];
void era()
{
	arr[2] = 2;
	long long i, j;
	for ( i = 3; i <= 999999; i = i + 2 ) arr[i] = i;
	for ( i = 3; i <= 999999; i = i + 2 )
	{
		for ( j = i * i; j <= 999999; j = j + i )
		{
			if ( arr[i] != 0 )
			{
				arr[j] = 0;
			}
		}
	}
}
int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	era();
	int i, j;
	for ( i = n; i <= m; i++ )
	{
		if ( arr[i] != 0 ) printf("%d\n", arr[i]);
	}

	return 0;
}