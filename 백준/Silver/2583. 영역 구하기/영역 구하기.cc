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
int m, n,k;
int monun[105][105];
int visit[105][105];
int xx[4] = { 0,1,0,-1 };
int yy[4] = { 1,0,-1,0 };
bool ok(int x, int y) {
	if (x<0 || x>=n || y<0 || y>=m || visit[y][x] || !monun[y][x]) return 0;
	return 1;
}
int com;
vector<int>v;
int cnt;

void dfs(int x, int y) {
	visit[y][x] = 1;
	//cout << x << " " << y << endl;
	for (int h = 0; h < 4; h++) {
		if (ok(x + xx[h], y + yy[h])) {
			cnt+=monun[y][x];
			dfs(x + xx[h], y+ yy[h]);
		}
	}

}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int i, j;//for문변수-->가끔식 long으로
	scanf("%d %d %d", &m, &n, &k);//m ==y n==x
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			monun[i][j] = 1;
		}
	}
	for (i = 0; i < k; i++) {
		int x1, y1, x2, y2;
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		//scanf("%d %d", &x2, &y2);
		for (int q = y1; q < y2; q++) {
			for (j = x1; j < x2; j++)
				monun[q][j]=0;
		}
	}
	//cout << "!";
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			if (!visit[i][j] && monun[i][j]) {
				cnt = 1;
				dfs(j, i);
				v.push_back(cnt);
				com++;
			}
		}
	}
	//cout << "!";
	sort(v.begin(), v.end());
	printf("%d\n", com);
	for (auto it = v.begin(); it != v.end(); it++) printf("%d ", *it);
	return 0;
}