#include <stdio.h>
#include <string.h>
#include<stdlib.h>
#include<string>
#include<iostream>

using namespace std;
//int arr[1000005];
int a[4] = { 0,1,2,4 };
/*int main()
{
	int n;
	scanf("%d", &n);
	int i;
	int j = 0;
	int chk=1;
	while(n>0 ){
		int temp = n % 10;
		if ( chk == 4 ) chk = 1;
		arr[j / 3] = arr[j/3] + a[chk] * temp;
		j++;
		n = n / 10;
		chk++;
	}
	for ( int k = (j - 1) / 3; k >= 0; k-- ) printf("%d", arr[k]);
	return 0;
}*/
int arr[1000005];
int ans[1000005];
int main()
{
	string s;
	int j = 0;
	cin >> s;
	for ( int i = 0; i < s.size() % 3; i++ ) s = '0' + s; 
	for ( int i = 0; i < s.size(); i++)
	{
		if ( s[i] == '0' ) arr[i] = 0;
		else if (s[i] == '1') arr[i] = 1;
	}
	for ( int i = 0; i < s.size(); i = i + 3 )
	{
		cout << (arr[i] * 4 + arr[i + 1] * 2 + arr[i + 2]);
	}



	return 0;
}