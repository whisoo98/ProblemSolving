#include<stdio.h>

// a_n+2=a_n + a_n+1
int arr[1005];
int main()
{
	int n;
	scanf("%d", &n);
	arr[1] = 1;
	arr[2] = 3;
	int i;

	//초기값 설정
	for ( i = 3; i <= n; i++ )
	{
		arr[i] = (2*arr[i - 2] + arr[i - 1])%10007;
	}
	printf("%d", arr[n]);


	return 0;
}