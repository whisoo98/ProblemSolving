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
#define N 100'005
#define ll long long
#define endl "\n"
#define MID(a,b) (a+b)/2

using namespace std;


vector<pair<int, int>> edge[N];
int visit[N];
int dp[N];
int dfs(int node) {
	if (visit[node]!=-1) return visit[node];
	visit[node] = 0;
	//int left = dfs(edge[node]);
	int left=0, right = 0;
	int len = edge[node].size();
	int ret;
	if (len == 0) {
		//return 0;
		ret = 0;
	}
	else if (len == 1) {
		int next = edge[node][0].first;
		if (visit[next] == -1) {
			left = dfs(next);
			left += edge[node][0].second;
		}
		else {
			left = dfs(next);
		}
		visit[node] = left;
		ret = left;
		//return left;
	}
	else {
		int next = edge[node][0].first;
		if (visit[next] == -1) {
			left = dfs(next);
			left += edge[node][0].second;
		}
		else {
			left = dfs(next);
		}
		vector<int>tmp(3,0);
		tmp[0] = left;
		//visit[node] = left;
		for (int i = 1; i < len;i++) {
			next = edge[node][i].first;
			int temp = 0;
			if (visit[next] == -1) {
				temp = dfs(next);
				temp += edge[node][i].second;
			}
			else {
				temp = dfs(next);
			}
			tmp[2] = temp;
			//right = max(right, dfs(edge[node][i].first)+ edge[node][i].second);
			sort(tmp.begin(), tmp.end(), greater<int>());
			//right = max(right, temp);
		}
		visit[node] = tmp[0] + tmp[1];
		ret = max(tmp[0], tmp[1]);
		//return max(left, right);
	}
	//cout << node << " " << ret << endl;
	return ret;
}

void Solution(int n) {
	dfs(1);
	int m = -1;
	for (int i = 1; i <= n; i++) {
		m = max(m, visit[i]);
		//cout << visit[i] << endl;
	}
	cout << m;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j; //for문 변수 -> longlong필요한지 확인
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		visit[i + 1] = -1;
		int v; cin >> v;
		while (1) {
			int ed, weight;
			cin >> ed;
			if (ed == -1) break;
			cin >> weight;
			edge[v].push_back({ ed,weight });
			//edge[ed].push_back({ v,weight });
		}
	}
	Solution(n);
	return 0;
}