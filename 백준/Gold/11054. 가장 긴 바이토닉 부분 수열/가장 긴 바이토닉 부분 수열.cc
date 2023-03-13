#include <cstdio>
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
#include <climits>
#include <cstring>
#define N 1005

using namespace std;

/*struct type_name {

}srt;*/

//vector <type> vec;
//stack <type> stk;
//queue <type> q;
//string str;
//map <key_type,value_type> m;
int arr[1005];
int brr[1005];
int inc[1005];
int de[1005];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int i, j;//for문변수-->가끔식 long으로
	int n; cin >> n;
	for (i = 1; i <= n; i++) {
		cin >> arr[i];
		brr[n + 1 - i] = arr[i];
	}
	inc[1] = 1;
	de[1] = 1;
	for (i = 2; i <= n; i++) {
		inc[i] = 1;
		for (j = 1; j < i; j++) {
			if (arr[i] > arr[j]) {
				inc[i] = max(inc[i], inc[j] + 1);
			}
		}
	}
	for (i = 2; i <= n; i++) {
		de[i] = 1;
		for (j = 1; j < i; j++) {
			if (brr[i] > brr[j]) {
				de[i] = max(de[i], de[j] + 1);
			}
		}
	}
	int m = -1;
	for (i = 1; i <= n; i++) {
		//cout << inc[i] << " " << de[i] << endl;
		m = max(m, inc[i] + de[n + 1 - i] - 1);
	}
	cout << m;
	//for(i=0;i<n;i++) {}
	//for(i=0;i<n;i++) { for(j=0;j<n;j++) { } }

	return 0;
}