#include <stdio.h>

char arr[105];
char s[6] = {"aeiou"};
int asc[128];
int main()
{
	int i, j;
	int ans = 0;
	for ( i = 0; i < 6; i++ ) asc[s[i]]++;
	scanf("%s", arr);
	for ( i = 0; arr[i]; i++ ){
		ans = ans + asc[arr[i]];
	}
	printf("%d", ans);
	return 0;
}