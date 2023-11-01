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
#define N 505
#define ll long long
#define endl "\n"
#define MID(a,b) (a+b)/2

using namespace std;


int visit[N];
vector<int> edge[N];

bool isTree(int node) {
	int tree = 1;
	int num_edges = 0;
	int num_vertexs = 1;
	queue<int> q; 
	q.push(node);
	visit[node] = 1;
	while (q.size()) {
		int now = q.front();
		q.pop();
		for (auto iter : edge[now]) {
			num_edges++;
			if (!visit[iter]) {
				q.push(iter);
				num_vertexs++;
				visit[iter] = 1;
			}
		}
	}
	if (num_edges == 2 * (num_vertexs - 1)) {
		tree = 1;
	}
	else {
		tree = 0;
	}
	return tree;
}

void Solution(int n, int T) {
	int num_trees = 0;
	memset(visit, 0, sizeof(visit));

	for (int i = 1; i <= n; i++) {
		if (!visit[i])
			num_trees += isTree(i);
	}
	if (num_trees == 0) {
		cout << "Case "<<T<<": No trees." << endl;
	}
	else if(num_trees==1) {
		cout << "Case " << T << ": There is one tree." << endl;

	}
	else {
		cout << "Case " << T << ": A forest of "<<num_trees<<" trees." << endl;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j; //for문 변수 -> longlong필요한지 확인
	int T = 1;
	while ( 1) {
		for (int i = 1; i < N; i++) {
			edge[i].clear();
		}
		int n, m; cin >> n >> m;
		if (n + m == 0) break;
		for (int i = 0; i < m; i++) {
			int a, b; cin >> a >> b;
			edge[a].push_back(b);
			edge[b].push_back(a);
		}
		Solution(n, T);
		T++;
	}

	return 0;
}