#include <stdio.h>

int arr[35];
int main()
{
	for ( int i = 1; i <= 28; i++ )
	{
		int a;
		scanf("%d", &a);
		arr[a]++;
	}
	for ( int i = 1; i <= 30; i++ )
	{
		if ( arr[i] == 0 ) printf("%d\n", i);
	}
	return 0;
}