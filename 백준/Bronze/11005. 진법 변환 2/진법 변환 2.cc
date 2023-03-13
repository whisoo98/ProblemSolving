#include <stdio.h>
#include<string>
#include<iostream>
/*A: 10, B: 11, ..., F: 15, ..., Y: 34, Z: 35*/
//A 65 Z90 0-48 9 - 57
using namespace std;
int arr[1000005];
int main()
{
	int n, b;
	scanf("%d %d", &n, &b);
	int i = 0;
	int j;
	while ( n )
	{
		int temp = n % b;
		if ( temp >= 10 ) temp = temp + 55;
		else temp = temp + 48;
		arr[i] = temp;

		i++;
		n = n / b;
	}
	for ( j=i - 1; j >= 0; j-- ) printf("%c", arr[j]);
	return 0;
}