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
vector<int> v;
int x, y;
bool visit[55][55];
int arr[55][55];
int xx[] = { -1,0,1,-1,1,-1,0,1 };
int yy[] = { -1,-1,-1,0,0,1,1,1 };
bool ok(int dy, int dx) {
	if (dy < 1 || dy>y || dx<1 || dx>x || visit[dy][dx] || !arr[dy][dx]) return false;
	return true;
}


void dfs(int ty, int tx) {
	visit[ty][tx] = 1;
	for (int k = 0; k < 8; k++) {
		if(ok(ty + yy[k], tx + xx[k])) {
			dfs(ty + yy[k], tx + xx[k]);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int i, j;//for문변수-->가끔식 long으로
	while (1) {
//		cin >> x >> y;
		int cnt = 0;
		scanf("%d %d", &x, &y);
		if (!(x + y)) return 0;
		for (i = 1; i <= y; i++) {
			for (j = 1; j <= x; j++) {
				scanf("%d", &arr[i][j]);
			}
		}

		for (i = 1; i <= y; i++) {
			for (j = 1; j <= x; j++) {
				if (arr[i][j] && !visit[i][j]) {
					cnt++;
					dfs(i, j);
				}
			}
		}





		for (i = 1; i <= y; i++) {
			for (j = 1; j <= x; j++) {
				arr[i][j] = 0;
				visit[i][j] = 0;
			}
		}
		printf("%d\n", cnt);
	}

	return 0;
}