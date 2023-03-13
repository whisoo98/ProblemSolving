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
int arr[105][105];
int visit[105][105];
vector<int>count;
queue<int>qx, qy;
int xx[] = { 0,1,0,-1 };
int yy[] = { 1,0,-1,0 };
bool ok(int y, int x) {
	if (x<1 || x>n || y<1 || y>n) return false;
	return true;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int i, j;//for문변수-->가끔식 long으로
	int m = -1, M = -1;
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			scanf("%d", &arr[i][j]);
			//m = min(m, arr[i][j]);
			M = max(arr[i][j], M);
		}
	}
	//cout << M << endl;
	for (int k = 0; k <= M; k++) {
		int cnt = 0;
		//k = 4;
		for (i = 1; i <= n; i++) {
			for (j = 1; j <= n; j++) {
				if ((arr[i][j] - k) > 0 && visit[i][j] != k + 1) {
					cnt++;
					qx.push(j); qy.push(i);
					visit[i][j] = k + 1;
					while (!qx.empty()) {
						int ty = qy.front(), tx = qx.front();
						qx.pop(); qy.pop();

						for (int p = 0; p < 4; p++) {
							if (ok(ty + yy[p], tx + xx[p]) && (arr[ty+yy[p]][tx+xx[p]] - k) > 0 && visit[ty + yy[p]][tx + xx[p]] != k + 1) {
								visit[ty + yy[p]][tx + xx[p]] = k + 1;
								qx.push(tx + xx[p]); qy.push(ty + yy[p]);
							}
						}
					}
				}
			}
		}
		m = max(m, cnt);
		//cout << m;
	}
	printf("%d", m);
	return 0;
}	