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
#define N 1005
#define ll long long
#define endl "\n"
#define MID(a,b) (a+b)/2

using namespace std;


vector<int> edge[N];
priority_queue<tuple<int, int, int>> pq;
priority_queue<tuple<int, int, int>> temp;
char arr[N][N];

int parent[N];

int Find(int x) {
	if (parent[x] == x) return x;
	return parent[x] = Find(parent[x]);
}
void Union(int x, int y) {
	//parent[x] = y;
	x = Find(x);
	y = Find(y);
	parent[x] = y;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j; //for문 변수 -> longlong필요한지 확인
	int n, m; cin >> n >> m;
	for (int i = 0; i < n; i++) {
		parent[i] = i;
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = i+1; j < n; j++) {
			//cin >> arr[i][j];
			if (arr[i][j] == 'Y') {
				pq.push({-(i*n+j),i,j });
			}
		}
	}
	if (pq.size() < m) {
		//cout << "pq.size()" << endl;

		cout << -1 << endl;
		return 0;
	}
	int cnt = 0;
	while (pq.size()) {
		int cost = get<0>(pq.top());
		int from = get<1>(pq.top());
		int to   = get<2>(pq.top());
		pq.pop();
		if (Find(from) != Find(to)) {
			Union(from, to);
			edge[from].push_back(to);
			edge[to].push_back(from);
			cnt++;
		}
		else {
			temp.push({ cost,from,to });

		}
	}
	while (temp.size()&&cnt<m) {
		int cost = get<0>(temp.top());
		int from = get<1>(temp.top());
		int to = get<2>(temp.top());
		temp.pop();
		edge[from].push_back(to);
		edge[to].push_back(from);
		cnt++;
		//cout << from << " " << to << endl;

	}
	vector<int> ans;
	int chk = 0;
	int base = Find(0);
	for (int i = 0; i < n; i++) {
		if(chk==0)
			chk = base != Find(i) ? 1 : 0;
		ans.push_back(edge[i].size());
		//cout << Find(i) << endl;
	}
	if (chk) {
		//cout << "chk" << endl;
		cout << -1 << endl;
		return 0;
	}
	for (int i = 0; i < n; i++) {
		cout << ans[i] << " ";
	}
	return 0;
}