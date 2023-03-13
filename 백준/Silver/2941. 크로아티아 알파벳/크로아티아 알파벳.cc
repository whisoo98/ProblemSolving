#include <stdio.h>
#include <string.h>

char arr[105];
int main()
{
	scanf("%s", arr);
	int i;
	int chk = strlen(arr);
	for ( i = 0; i < strlen(arr); i++ )
	{
		if ( arr[i] == 'c' )
		{
			if ( arr[i + 1] == '=' || arr[i + 1] == '-' ) chk--;
		}
		else if ( arr[i] == 'd' )
		{
			if ( arr[i + 1] == '-' ) chk--;
			else if ( arr[i + 1] == 'z'&&arr[i + 2] == '=' ) chk=chk-2;
		}
		else if ( arr[i] == 'l' )
		{
			if ( arr[i + 1] == 'j' ) chk--;
		}
		else if ( arr[i] == 'n' )
		{
			if ( arr[i + 1] == 'j' ) chk--;
		}
		else if ( arr[i] == 's' )
		{
			if ( arr[i + 1] == '=' ) chk--;
		}
		else if ( arr[i] == 'z' )
		{
			if ( arr[i + 1] == '=' && arr[i - 1] != 'd' ) chk--;
		}
	}
	printf("%d", chk);
	return 0;
}