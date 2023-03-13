#include <stdio.h>

/*같은 눈이 4개가 나오면 50,000원+(같은 눈)*5,000원의 상금을 받게 된다. 
같은 눈이 3개만 나오면 10,000원+(3개가 나온 눈)*1,000원의 상금을 받게 된다. 
같은 눈이 2개씩 두 쌍이 나오는 경우에는 2,000원+(2개가 나온 눈)*500원+(또 다른 2개가 나온 눈)*500원의 상금을 받게 된다.
같은 눈이 2개만 나오는 경우에는 1,000원+(같은 눈)*100원의 상금을 받게 된다. 
모두 다른 눈이 나오는 경우에는 (그 중 가장 큰 눈)*100원의 상금을 받게 된다.  */
int arr[4];
int main()
{
	int n, i, j;
	int max = 0;
	int sum = 0;
	scanf("%d", &n);
	for ( i = 1; i <= n; i++ )
	{
		scanf("%d %d %d %d", &arr[0], &arr[1], &arr[2], &arr[3]);
		if ( arr[0] == arr[1] && arr[0] == arr[2] && arr[0] == arr[3] ) sum = 50000 + arr[0] * 5000;
		else if ( arr[0] == arr[1] && arr[0] == arr[2] && arr[0] != arr[3] || arr[0] == arr[1] && arr[0] != arr[2] && arr[0] == arr[3] || arr[0] != arr[1] && arr[0] == arr[2] && arr[0] == arr[3] ) sum = arr[0] * 1000 + 10000;
		else if ( arr[1] != arr[0] && arr[1] == arr[2] && arr[1] == arr[3] ) sum = arr[1] * 1000 + 10000;
		else if ( arr[0] == arr[1] && arr[2] == arr[3] || arr[0] == arr[2] && arr[1] == arr[3] ) sum = (arr[0] + arr[3]) * 500 + 2000;
		else if ( arr[0] == arr[3] && arr[2] == arr[1] )sum = (arr[0] + arr[2]) * 500 + 2000;
		else if ( arr[0] == arr[1] || arr[0] == arr[2] || arr[0] == arr[3] ) sum = 1000 + arr[0] * 100;
		else if ( arr[1] == arr[2] || arr[1] == arr[3] ) sum = 1000 + arr[1] * 100;
		else if ( arr[2] == arr[3] ) sum = 1000 + arr[2] * 100;
		else if ( arr[0] > arr[1] && arr[0] > arr[2] && arr[0] > arr[3] ) sum = arr[0] * 100;
		else if ( arr[1] > arr[0] && arr[1] > arr[2] && arr[1] > arr[3] ) sum = arr[1] * 100;
		else if ( arr[2] > arr[1] && arr[2] > arr[0] && arr[2] > arr[3] ) sum = arr[2] * 100;
		else sum = arr[3] * 100;
		if ( sum > max ) max = sum;

	}
	printf("%d", max);
	return 0;
}