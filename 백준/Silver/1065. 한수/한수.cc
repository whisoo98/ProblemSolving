#include <stdio.h>


int arr[4];
int main()
{
	int i=0, j;
	int n;
	int chk=0;
	int cnt = 0;
	int cha;
	int temp = 0;
	int count = 0;
	scanf("%d", &n);
	if ( n < 100 )
	{
		printf("%d", n);
		return 0;
	}
	int N;
	while ( n>=100 )
	{
		i = 0;
		N = n;
		chk = 0;
		cnt = 0;
		temp = 0;
		while ( N )
		{
			arr[i] = N % 10;
			N = N / 10;
			i++;
			chk++;
		}
		cha = arr[0] - arr[1];
		for ( i = 2; i < chk; i++ )// 0 - 2 , 3 ,4 ,5 ...
		{
			if ( cha*i == arr[0] - arr[i] ) temp++;
		}
		if ( temp == chk - 2 ) count++;
		n--;
	}
	printf("%d", count + 99);
	return 0;
}