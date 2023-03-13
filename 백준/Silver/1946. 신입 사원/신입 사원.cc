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
vector<pair<int, int>> v;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int i, j;//for문변수-->가끔식 long으로
	int T; scanf("%d", &T);
	while (T--) {
		int n; scanf("%d", &n);

		for (i = 0; i < n; i++) {
			int a, b; scanf("%d %d", &a, &b); v.push_back({ a,b });
		}
		sort(v.begin(), v.end());
		int start = v[0].first, end = v[0].second, cnt = 1;
		
		for (i = 1; i < n; i++) {
			if (v[i].second < end) {
				start = v[i].first;
				end = v[i].second;
				cnt++;
			}
		}
		printf("%d\n", cnt);
		v.clear();
	}
	return 0;
}