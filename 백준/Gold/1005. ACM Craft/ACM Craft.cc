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

using namespace std;

int arr[1005];
vector<int> edge[1005];
int in[1005];
int visit[1005];
queue<int> q;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j; //for문 변수 -> longlong필요한지 확인
	int T; cin >> T;
	while (T--) {
		int V, E; cin >> V >> E;
		for (i = 1; i <= V; i++) {
			cin >> arr[i];
		}
		for (i = 1; i <= E; i++) {
			int a, b; cin >> a >> b;
			edge[a].push_back(b);
			in[b]++;
		}
		int st; cin >> st;
		for (i = 1; i <= V; i++) {
			if (in[i] == 0) {
				q.push(i);
				visit[i] = arr[i];
			}
		}
		while (!q.empty()) {
			int now = q.front(); q.pop();
			for (auto it : edge[now]) {
				in[it]--;
				visit[it] = max(visit[it], visit[now]);
				if (in[it] == 0) {
					q.push(it);
					visit[it] += arr[it];
				}
			}
		}
		cout << visit[st] << "\n";
		for (i = 1; i <= V; i++) {
			edge[i].clear();
			visit[i] = 0;
			in[i] = 0;
			arr[i] = 0;
		}
	}

	return 0;
}