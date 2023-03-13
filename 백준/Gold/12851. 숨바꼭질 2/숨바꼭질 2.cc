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
int cnt[N];

void setDist(int n, int st) {
	for (int i = 0; i < N; i++) {
		dist[i] = INF;
	}
	dist[st] = 0;
	cnt[st] = 1;
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
			if (dist[temp] >= dist[now] + 1) {
				if (dist[temp] > dist[now] + 1) {
					dist[temp] = dist[now] + 1;
					cnt[temp] = 1;
				}
				else{
					cnt[temp]++;
				}
				q.push(temp);
			}
		}
		temp = now - 1;
		if (ok(temp)) {
			if (dist[temp] >= dist[now] + 1) {
				if (dist[temp] > dist[now] + 1) {
					dist[temp] = dist[now] + 1;
					cnt[temp] = 1;
				}
				else {
					cnt[temp]++;
				}
				q.push(temp);
			}
		}
		temp = now * 2;
		if (ok(temp)) {
			if (dist[temp] >= dist[now] + 1) {
				if (dist[temp] > dist[now] + 1) {
					dist[temp] = dist[now] + 1;
					cnt[temp] = 1;
				}
				else {
					cnt[temp]++;
				}
				q.push(temp);
			}
		}
	}
}
void Solution(int n, int st, int ed) {
	setDist(n,st);
	doSeekAndHide(n, st, ed);
	cout << dist[ed] << endl;
	cout << cnt[ed] << endl;
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