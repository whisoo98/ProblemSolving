#include <stdio.h>
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <functional>
#include <stdlib.h>
#include <string>
#include <queue>
#include <stack>
#include <map>
#include<cmath>

using namespace std;

/*struct type_name {

}srt;*/

//vector <type> vec;
//stack <type> stk;
//queue <type> q;
//string str;
//map <key_type,value_type> m;
int arr[1000005] = { 1, 1, };

/*void era() {
	int i,j;
	for (i = 2; i <= 1000000; i++) {
		if (arr[i] == 1) continue;
		for (j = i+i; j <= sqrt(i); j=j+i) {
			arr[j] = 1;			
		}
	}
}*/

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int i, j;//for문변수-->가끔식 long으로
	int n;
	long long ominsik = 1;
	long long multy;
	cin >> n;
	{
		for (i = 2; i <= 1000000; i++) {
			if (arr[i] == 1) continue;
			for (j = i + i; j <= 1000000; j = j + i) {
				arr[j] = 1;
			}
		}
	}
	for (i = 2; i <= n; i++) {
		if (arr[i] == 1) continue;
		multy = 1;
		for (j = 1; j <= 100000; j++) {
			if (multy == n) break;
			if (multy > n) {
				multy = multy / i;
				break;
			}
			multy *= i;
		}
		ominsik = (ominsik % 987654321) * multy ;
	}
	cout << ominsik%987654321;
	return 0;
}