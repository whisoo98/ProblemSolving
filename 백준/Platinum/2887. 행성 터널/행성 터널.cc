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
#define N 100005
using namespace std;

int parent[N];
tuple<int, int, int, int> tp[N];
priority_queue<tuple<int, int, int>>pq;
bool cmpx(tuple<int, int, int, int> &t1, tuple<int, int, int, int> &t2) {
	if (get<0>(t1) > get<0>(t2)) {
		return true;
	}
	else if (get<0>(t1) == get<0>(t2)) {
		if (get<1>(t1) > get<1>(t2)) {
			return true;
		}
		else if (get<1>(t1) == get<1>(t2)) {
if (get<2>(t1) >= get<2>(t2)) {
	return true;
}
else return false;
		}
		else return false;
	}
	else return false;
}

bool cmpy(tuple<int, int, int, int> &t1, tuple<int, int, int, int> &t2) {
	if (get<1>(t1) > get<1>(t2)) {
		return true;
	}
	else if (get<1>(t1) == get<1>(t2)) {
		if (get<2>(t1) > get<2>(t2)) {
			return true;
		}
		else if (get<2>(t1) == get<2>(t2)) {
			if (get<0>(t1) >= get<0>(t2)) {
				return true;
			}
			else return false;
		}
		else return false;
	}
	else return false;
}

bool cmpz(tuple<int, int, int, int> &t1, tuple<int, int, int, int> &t2) {
	if (get<2>(t1) > get<2>(t2)) {
		return true;
	}
	else if (get<2>(t1) == get<2>(t2)) {
		if (get<0>(t1) > get<0>(t2)) {
			return true;
		}
		else if (get<0>(t1) == get<0>(t2)) {
			if (get<1>(t1) >= get<1>(t2)) {
				return true;
			}
			else return false;
		}
		else return false;
	}
	else return false;
}

int Find(int x) {
	if (parent[x] == x) return x;
	return parent[x] = Find(parent[x]);
}

void Union(int x, int y) {
	int X = Find(x);
	int Y = Find(y);
	if (X != Y) {
		parent[X] = Y;
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j; //for문 변수 -> longlong필요한지 확인
	int n; cin >> n;
	for (i = 1; i <= n; i++) {
		int a, b, c; cin >> a >> b >> c;
		tp[i] = { a,b,c,i };
		parent[i] = i;
	}
	sort(tp + 1, tp + 1 + n, cmpx);
	for (i = 1; i < n; i++) {
		int a = get<3>(tp[i]);
		int b = get<3>(tp[i + 1]);
		int c = abs(get<0>(tp[i]) - get<0>(tp[i + 1]));
		pq.push({ -c,a,b });
	}
	sort(tp + 1, tp + 1 + n, cmpy);
	for (i = 1; i < n; i++) {
		int a = get<3>(tp[i]);
		int b = get<3>(tp[i + 1]);
		int c = abs(get<1>(tp[i]) - get<1>(tp[i + 1]));
		pq.push({ -c,a,b });
	}
	sort(tp + 1, tp + 1 + n, cmpz);
	for (i = 1; i < n; i++) {
		int a = get<3>(tp[i]);
		int b = get<3>(tp[i + 1]);
		int c = abs(get<2>(tp[i]) - get<2>(tp[i + 1]));
		pq.push({ -c,a,b });
	}
	int cnt = 1;
	int sum = 0;
	while (cnt < n) {
		int val = -get<0>(pq.top());
		int a = get<1>(pq.top());
		int b = get<2>(pq.top());
		pq.pop();
		if (Find(a) != Find(b)) {
			Union(a, b);
			cnt++;
			sum += val;
		}
	}
	cout << sum;
	return 0;
}