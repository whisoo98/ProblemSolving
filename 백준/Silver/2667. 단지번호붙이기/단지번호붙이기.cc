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
int arr[30][30];
bool visit[30][30];
int xx[] = { 0,1,0,-1 };
int yy[] = { 1,0,-1,0 };
vector<int>v;
bool ok(int y, int x) {
	if (y<1 || y>n || x<1 || x>n || !arr[y][x] || visit[y][x]) return false;
	return true;
}
int cnt;
void dfs(int y, int x) {
	cnt++;
	visit[y][x] = 1;
	for (int i = 0; i < 4; i++) {
		if (ok(y + yy[i], x + xx[i])) dfs(y + yy[i], x + xx[i]);
	}
}
int main()
{
	int count = 0;

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int i, j;//for문변수-->가끔식 long으로
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			scanf("%1d", &arr[i][j]);
		}
	}

	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			if (arr[i][j] && !visit[i][j]) {
				cnt = 0;
				count++;
				dfs(i, j);
				v.push_back(cnt);
			}
		}
	}
	printf("%d\n", count);
	sort(v.begin(), v.end());
	for (i = 0; i < v.size(); i++) printf("%d\n", v[i]);
	return 0;
}