#include <stdio.h>

/*첫째 줄에 N과 X가 주어진다. (1 ≤ N, X ≤ 10,000)

둘째 줄에 수열 A를 이루는 정수 N개가 주어진다. 주어지는 정수는 모두 1보다 크거나 같고, 10,000보다 작거나 같은 정수이다.*/
//X보다 작은 수를 입력받은 순서대로 공백으로 구분해 출력한다. X보다 작은 수는 적어도 하나 존재한다.

int main()
{
	int n, x;//문제 조건
	int i, j;//for 변수
	int temp;//받을거
	scanf("%d %d", &n, &x);
	for ( i = 0; i < n; i++ )
	{
		scanf("%d", &temp);
		if ( temp < x ) printf("%d ", temp);
	}
	return 0;
}