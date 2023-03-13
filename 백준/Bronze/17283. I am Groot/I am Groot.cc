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
#include<cmath>

using namespace std;

/*struct type_name {

}srt;*/

//vector <type> vec;
//stack <type> stk;
//queue <type> q;
//string str;
//map <key_type,value_type> m;
int arr[500];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int i, j;//for문변수-->가끔식 long으로
	int n, r; cin >> n >> r;
	double branch = floor(n * r / 100);
	int cnt = 0;
	while (1) {
		cnt++;
		if (branch <= 5) break;
		arr[cnt] = branch;
		branch = floor(branch * r / 100);
	}
	long long sum = 0;
	for (i = 1; i <= cnt; i++) {
		sum += (1 << i)*arr[i];
	}
	cout << sum;
	//for(i=0;i<n;i++) {}
	//for(i=0;i<n;i++) { for(j=0;j<n;j++) { } }

	return 0;
}