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
#define N 105
#define ll long long
#define endl "\n"
#define MID(a,b) (a+b)/2
#define INF INT_MIN

using namespace std;

vector<tuple<ll,ll, ll>> edge;
vector<ll> con[N];
ll visit[N];
ll arr[N];
int n, st, ed, m;
int chk = 0;
ll temp[N];
void dfs(ll x) {
	temp[x] = 1;
	if (x == ed) chk = 1;
	for (auto it : con[x]) {
		if (temp[it] != 1) {
			dfs(it);
		}
	}
	temp[x] = 0;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j; //for문 변수 -> longlong필요한지 확인
	 cin >> n >> st >> ed >> m;
	st++; ed++;
	for (i = 1; i <= n; i++) {
		visit[i] = INF;
	}
	for (i = 1; i <= m; i++) {
		ll a, b, c; cin >> a >> b >> c;
		a++; b++;
		edge.push_back({ a,b,c });
		con[a].push_back(b);
		//edge[a].push_back({ c,b });
	}
	for (i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	//visit[st] = 0;
	visit[st] = arr[st];
	for (i = 1; i <= n; i++) {
		for (j = 0; j < m; j++) {
			ll start = get<0>(edge[j]);
			ll end = get<1>(edge[j]);
			ll cost = get<2>(edge[j]);//-될값
			if (visit[start] == INF) continue;
			else if (visit[end] < visit[start] - cost + arr[end]) {
				visit[end] = visit[start] - cost + arr[end];
			}
		}
	}
	for (j = 0; j < m; j++) {
		if (chk == 1) break;
		ll start = get<0>(edge[j]);
		ll end = get<1>(edge[j]);
		ll cost = get<2>(edge[j]);//-될값
		if (visit[start] == INF) continue;
		else if (visit[end] < visit[start] - cost + arr[end]) {
			visit[end] = visit[start] - cost + arr[end];
			dfs(start);
			//if (end == ed)	chk++;

		}
	}
	if (visit[ed] == INF) cout << "gg";
	else if (chk == 1) cout << "Gee";
	else cout << visit[ed];
	return 0;
}