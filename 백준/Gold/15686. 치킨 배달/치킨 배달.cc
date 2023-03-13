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
#define N 55
#define ll long long
#define endl "\n"
#define MID(a,b) (a+b)/2
#define INF 987654321
using namespace std;

int Dist(int y1, int x1, int y2, int x2) {
	return abs(y1 - y2) + abs(x1 - x2);
}

int arr[N][N];
vector<pair<int, int>> house;
vector<pair<int, int>> chiken;
int visit[N];
int ans = INF;
void dfs(int lev, int cnt, int m, int max_lv) {
	if (lev >= max_lv) {
		if (cnt == m) {
			int len = 0;
			for (auto it : house) {
				int y = it.first;
				int x = it.second;
				int dist = INF;
				for (int i = 0; i < max_lv; i++) {
					if (visit[i]) {
						//len += Dist(y, x, chiken[i].first, chiken[i].second);
						dist = min(dist, Dist(y, x, chiken[i].first, chiken[i].second));
					}
				}
				len += dist;
			}
			ans = min(len, ans);
			return;
		}
		else return;
	}

	visit[lev] = 1;
	dfs(lev + 1, cnt + 1, m, max_lv);

	visit[lev] = 0;
	dfs(lev + 1, cnt, m, max_lv);
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j; //for문 변수 -> longlong필요한지 확인
	int n, m; cin >> n >> m;
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 2) {
				chiken.push_back({ i,j });
			}
			else if (arr[i][j] == 1) {
				house.push_back({ i,j });
			}
		}
	}
	dfs(0, 0, m, chiken.size());
	cout << ans;

	return 0;
}