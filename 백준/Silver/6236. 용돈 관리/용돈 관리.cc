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


using namespace std;

/*struct type_name {

}srt;*/

//vector <type> vec;
//stack <type> stk;
//queue <type> q;
//string str;
//map <key_type,value_type> m;
int day[100005];
int n, m;
long long Para(int l, int r) {
	while (l <= r) {
		int mid = (l + r) / 2;
		int temp = mid;
		int chk = 1;
		int cnt = 0;
		for (int i = 1; i <= n; i++) {
			if (mid < day[i]) {
				l = mid + 1;
				cnt++;
				break;
				
			}
			if (day[i] <= temp) temp -= day[i];
			else {
				chk++;
				temp = mid;
                temp-=day[i];
			}
		}
		if (!cnt) {
			if (chk <= m) r = mid - 1;
			else l = mid + 1;
		}
	}
	
	return l;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int i, j;//for문변수-->가끔식 long으로
	 cin >> n >> m;
	 
	for (i = 1; i <= n; i++) {
		cin >> day[i];
	
	}
	cout<<Para(0, INT_MAX);
	//for(i=0;i<n;i++) {}
	//for(i=0;i<n;i++) { for(j=0;j<n;j++) { } }

	return 0;
}