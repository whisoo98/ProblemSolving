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


int rocks[N];
int visit[N];
int mul[2] = { 1,-1 };

bool isOk(int now, int n) {
	if (now<1 || now > n) return false;
	return true;
}

int visitRocks(int n, int st) {
	int count_visited = 0;
	queue<int> q;
	q.push(st);
	visit[st] = 1;
	while (q.size()) {
		int now = q.front(); q.pop();
		count_visited++;
		for (int i = 0; i < 2; i++) {
			int next = now + mul[i] * rocks[now];
			if (isOk(next, n) && !visit[next]) {
				visit[next] = 1;
				q.push(next);
			}
		}
	}

	return count_visited;
}

void Solution(int n, int st) {
	int ans;
	ans = visitRocks(n, st);
	cout << ans << endl;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j; //for문 변수 -> longlong필요한지 확인
	int n; cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> rocks[i];
	}
	int st; cin >> st;
	Solution(n, st);
	return 0;
}