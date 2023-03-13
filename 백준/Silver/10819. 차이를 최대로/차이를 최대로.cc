#include <stdio.h>
#include<algorithm>
#include<iostream>
#include<cstdlib>
#include<functional>
#include<cmath>
using namespace std;

int arr[10];
int temp[10];
int main()
{
	int n;
	scanf("%d", &n);//배열의 끝번호 n-1
	int sum = 0;
	int i, j;
	int fac = 1;
	int max = -1;
	/*int swt;
	if ( n % 2 == 0 )swt = 1;
	else swt = -1;*/
	for (i = 1; i <= n; i++) {
		scanf("%d", &arr[i - 1]);
		fac *= i;
	}
	sort(arr, arr + n,less<int>());
	for (i = 0; i < fac; i++) {
		sum = 0;
		for (j = 0; j < n-1; j++) {
			sum += abs(arr[j] - arr[j + 1]);
		}
		if (sum > max) max = sum;
		next_permutation(arr, arr + n);
	}
	cout << max;
	return 0;
}