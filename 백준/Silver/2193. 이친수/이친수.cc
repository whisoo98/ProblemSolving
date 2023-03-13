#include<stdio.h>

// a_n+2=a_n + a_n+1
long long int arr[95][2];
int main()
{
	int n;
	scanf("%d", &n);
	arr[1][1] = 1;
	arr[1][0] = 0;
	int i;

	//초기값 설정
	for ( i = 2; i <= n; i++ )
	{
		
		arr[i][0] = arr[i - 1][1] + arr[i - 1][0];
		arr[i][1] = arr[i - 1][0];
		
	}
	printf("%lld", arr[n][0]+arr[n][1]);


	return 0;
}