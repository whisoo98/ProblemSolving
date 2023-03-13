#include <cstdio>
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
#include <climits>
#include <cstring>


using namespace std;

/*struct type_name {

}srt;*/


int V, E;//vertex edge
vector<pair<int, int>>edge[3000];
priority_queue<pair<int, int>> q;
int visit[3000][3000];
int cost[3000];
int dp[3000];
void Dijk(int start) {
	visit[start][start] = 0;
	q.push({ -visit[start][start],start });
	while (!q.empty()) {
		int now = q.top().second;
		int distance = -q.top().first;
		q.pop();
		for (auto it = edge[now].begin(); it != edge[now].end(); it++) {
			if (visit[start][it->second] > distance + it->first) {
				visit[start][it->second] = distance + it->first;
				q.push({ -visit[start][it->second],it->second });
			}
		}
	}
}
int Find(int end) {//end까지의 dp를 계산해주는 함수
	if (dp[end] != 987654321) return dp[end];
	//Find x->x까지 가는 최단 코스트 -> 1~k + k~x의 코스트의 min을 구해야함;
	for (int i = 1; i < end; i++) {
		dp[end] = min(dp[end], Find(i)+visit[i][end]*cost[i]);
	}
	/*for (int i = 1; i <= end; i++) {
		for (int j = 1; j <= end; j++) {
			dp[i] = min(dp[i], Find(j) + visit[j][i]);
		}
	}*/
	return dp[end];
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int i, j;//for문변수-->가끔식 long으로
	cin >> V >> E;
	int start=1; //시작지점;
	for (i = 1; i <= V; i++) cin >> cost[i];
	for (i = 1; i <= V; i++) {
		for (j = 1; j <= V; j++) {
			visit[i][j] = 987654321;
		}
		dp[i] = 987654321;
	}
	for (i = 0; i < E; i++) {
		int a, b, c; cin >> a >> b >> c;
		edge[a].push_back({ c,b });
		edge[b].push_back({ c,a });//양방향 그래프
	}
	for (i = 1; i <= V; i++) Dijk(i);
	//Find(1, V);
	dp[1] = 0;
	//for (i = 1; i <= V; i++) cout << visit[2][i] << endl;
	cout << Find(V);

	return 0;
}