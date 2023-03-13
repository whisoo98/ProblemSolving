#include <stdio.h>
#include<string.h>
char arr[65];

int main()
{
	int n;
	int i, j;
	scanf("%d", &n);
	for ( i = 0; i < n; i++ )
	{
		scanf("%s", arr);
		int len = strlen(arr);
		if ( arr[len - 1] % 2 == 0 ) printf("even\n");
		else printf("odd\n");
	}

	return 0;
}