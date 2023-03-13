#include <iostream>
#include <algorithm>
#include <functional>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <string>
#include <queue>
#include <stack>
#include <map>
#include <vector>
#include <set>
#include <sstream>
#include <ctime>
#include <climits>
#include <tuple>
#define N 50
#define ll long long
#define endl "\n"
#define MID(a,b) (a+b)/2

using namespace std;

int arr[N][N];
int visit[N][N];
int cnt[N];
int sum;
int big = 2;
int sec;
bool ok(int ty, int tx, int y, int x) {
	if (ty<1 || ty>y || tx<1 || tx>x || visit[ty][tx]) return false;
	return true;
}

void bfs(int y, int x, int sty, int stx,int* rety,int* retx) {
	visit[sty][stx] = 1;
	queue<int> qx, qy;
	vector<tuple<int, int,int>> ans;
	int chk = 0;
	qx.push(stx);
	qy.push(sty);
	int dx[] = { 0,-1,1,0 };
	int dy[] = { -1,0,0,1 };
	while (qx.size()) {
		int nowx = qx.front();
		int nowy = qy.front();
		qx.pop(); qy.pop();
		if (arr[nowy][nowx] > 0 && arr[nowy][nowx] < big) {
			if(!chk) chk = visit[nowy][nowx];
			ans.push_back({ visit[nowy][nowx],nowy,nowx });
			/*
			arr[sty][stx] = 0;
			cnt[arr[nowy][nowx]]--;
			arr[nowy][nowx] = 9;
			sum++;
			if (sum == big) {
				sum = 0;
				big++;
			}
			sec += visit[nowy][nowx] - 1;
			
			return { nowy,nowx };
			break;*/
		}
		for (int i = 0; i < 4; i++) {
			int ty = nowy + dy[i];
			int tx = nowx + dx[i];
			if (ok(ty, tx, y, x) && arr[ty][tx]<=big) {
				visit[ty][tx] = visit[nowy][nowx]+1;
				if (!chk) {
					qx.push(tx);
					qy.push(ty);
				}
			}
		}
	}
	if (!chk) {
		*rety = -1;
		*retx = -1;
		return;
	}
	sort(ans.begin(), ans.end());
	int nowy = get<1>(ans[0]);
	int nowx = get<2>(ans[0]);
	arr[sty][stx] = 0;
	cnt[arr[nowy][nowx]]--;
	arr[nowy][nowx] = 0;
	sum++;
	if (sum == big) {
		sum = 0;
		big++;
	}
	sec += visit[nowy][nowx] - 1;
	*rety = nowy;
	*retx = nowx;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j; //for문 변수 -> longlong필요한지 확인
	int n; cin >> n;
	int sty, stx;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 9) {
				sty = i;
				stx = j;
				arr[i][j] = 0;
			}
			else if(arr[i][j]>0){
				cnt[arr[i][j]]++;
			}
		}
	}
	while (1) {
		int count = 0;
		for (int i = 1; i < big; i++) {
			count += cnt[i];
		}
		if (count == 0) break;
		bfs(n, n, sty, stx,&sty,&stx);
		if (sty == -1 && stx == -1) break;

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				visit[i][j] = 0;
			}
		}
	}
	cout << sec;
	return 0;
}