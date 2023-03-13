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


using namespace std;

/*struct type_name {

}srt;*/

//vector <type> vec;
//stack <type> stk;
//queue <type> q;
//string str;
//map <key_type,value_type> m;
int n;
vector<pair<int, int>> v;
int friends[55][55];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int i, j;//for문변수-->가끔식 long으로
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			if (i == j) friends[i][j] = 0;
			else friends[i][j] = 987654321;
		}
	}
	while (1) {
		int a, b;
		scanf("%d %d", &a, &b);
		if (a == -1 && b == -1) break;
		friends[a][b] = 1;
		friends[b][a] = 1;		
	}
	for (int k = 1; k <= n; k++) {
		for (i = 1; i <= n; i++) {
			for (j = 1; j <= n; j++) {
				if (friends[i][j] > friends[i][k] + friends[k][j])friends[i][j] = friends[i][k] + friends[k][j];
			}
		}
	}
	for (i = 1; i <= n; i++) {
		int m = 0;
		for (j = 1; j <= n; j++) {
			if (friends[i][j] != 987654321)	m = max(m, friends[i][j]);
		}
		v.push_back({ m,i });
	}
	sort(v.begin(), v.end());
	int base = v.begin()->first;
	vector<int>vv;
	int cnt = 0;
	for (i = 0; i < v.size(); i++) {
		if (v[i].first == base) {
			cnt++;
			vv.push_back(v[i].second);
		}
	}
	sort(vv.begin(), vv.end());
	printf("%d %d\n", base, cnt);
	for (i = 0; i < vv.size(); i++) {
		printf("%d ", vv[i]);
	}
	return 0;
}