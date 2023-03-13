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

vector<int> edge[505];
int arr[505];
int visit[505];
int in[505];


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j; //for문 변수 -> longlong필요한지 확인
	int n; cin >> n;
	for (i = 1; i <= n; i++) {
		cin >> arr[i];
		while (1) {
			int a; cin >> a;
			if (a == -1) break;
			//edge[i].push_back(a);
			edge[a].push_back(i);
			in[i]++;
		}
	}
	queue<int> q;
	for (i = 1; i <= n; i++) {
		if (in[i] == 0) {
			q.push(i);
			//visit[i] = arr[i];
		}
	}
	while(1){
		queue<int> q2;
		
		while (!q.empty()) {
			int now = q.front(); q.pop();
			visit[now] += arr[now];
			for (auto it : edge[now]) {
				in[it]--;
				visit[it] = max(visit[it], visit[now]);
				if (in[it] == 0) {
					q2.push(it);
				}
			}
		}
		q = q2;
		if (q.empty()) break;
	}
	for (i = 1; i <= n; i++) {
		cout << visit[i] << "\n";
	}
	return 0;
}