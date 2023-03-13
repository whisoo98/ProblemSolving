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
#define INF 987654321
using namespace std;

int dist[N];
int track[N];
stack<int>trace;

void setDist(int n, int st) {
	for (int i = 0; i < N; i++) {
		dist[i] = INF;
	}
	dist[st] = 0;
}
bool ok(int x) {
	if (x < 0 || x>100'000) return false;
	return true;
}
void doSeekAndHide(int n, int st, int ed) {
	queue<int> q;
	q.push(st);
	while (q.size()) {
		int now = q.front();
		q.pop();
		int temp = now + 1;
		if (ok(temp)) {
			if (dist[temp] > dist[now] + 1) {
				dist[temp] = dist[now] + 1;
				track[temp] = now;
				q.push(temp);
			}
		}
		temp = now - 1;
		if (ok(temp)) {
			if (dist[temp] > dist[now] + 1) {
				dist[temp] = dist[now] + 1;
				track[temp] = now;

				q.push(temp);
			}
		}
		temp = now * 2;
		if (ok(temp)) {
			if (dist[temp] > dist[now]+1) {
				dist[temp] = dist[now]+1;
				track[temp] = now;

				q.push(temp);
			}
		}
	}
}
void tracking(int st, int ed) {
	int now = ed;
	while (now != st) {
		trace.push(now);
		now = track[now];
	}
	trace.push(now);
}
void Solution(int n, int st, int ed) {
	setDist(n,st);
	doSeekAndHide(n, st, ed);
	cout << dist[ed] << endl;
	tracking(st, ed);
	while (trace.size()) {
		int now = trace.top();
		cout << now << " ";
		trace.pop();
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j; //for문 변수 -> longlong필요한지 확인
	int n, k; cin >> n >> k;
	Solution(n, n, k);

	return 0;
}