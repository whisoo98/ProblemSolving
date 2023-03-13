#include <stdio.h>

int arr[1000005];
int main()
{
	int a;
	long long i, j;

	for ( i = 3; i <= 999997; i=i+2 ) arr[i] = i;
	for ( i = 3; i <= 999997; i=i+2 )
	{
		if ( arr[i] != 0 )
		{
			for ( j = i * i; j <= 999997; j = j + i )
			{
				arr[j] = 0;
			}
		}
	}

	while ( 1 )
	{
		scanf("%d", &a);
		if ( a == 0 ) return 0;
		int chk = 0;
		for ( i = 3; i <= a/2; i = i + 2 )
		{
			if ( arr[i] != 0 && arr[a-i] != 0)
				{
					printf("%d = %lld + %lld\n", a, i, a-i);
					chk = 1;
					break;
				}
			
			
			if ( chk == 1 ) break;
		}
	}
	


	return 0;
}