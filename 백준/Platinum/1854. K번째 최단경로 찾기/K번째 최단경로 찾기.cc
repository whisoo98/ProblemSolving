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
#define INF 987654321
using namespace std;

priority_queue<pair<int, int>> pq;
priority_queue<int> heap[N];
vector<pair<int, int>> edge[N];


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j; //for문 변수 -> longlong필요한지 확인
	int n, m, k; cin >> n >> m >> k;
	
	for (i = 1; i <= m; i++) {
		int a, b, c; cin >> a >> b >> c;
		edge[a].push_back({ c,b });
	}
	int st = 1;
	pq.push({ -0,st });
	heap[st].push(0);
	while (!pq.empty()) {
		int now = pq.top().second;
		int cost = -pq.top().first;
		pq.pop();
		for (auto it : edge[now]) {
			int next = it.second;
			int nextCost = it.first;

			if (heap[next].size() < k) {
				pq.push({ -(cost + nextCost), next });
				heap[next].push(cost + nextCost);
			}
			else if (heap[next].top()>cost+nextCost) {
				heap[next].pop();
				heap[next].push(cost + nextCost);
				pq.push({ -(cost + nextCost), next });
			}
		}
	}
	for (i = 1; i <= n; i++) {
		if (heap[i].size() < k) cout << -1 << endl;
		else {
			cout << heap[i].top() << endl;
		}
	}
	return 0;
}