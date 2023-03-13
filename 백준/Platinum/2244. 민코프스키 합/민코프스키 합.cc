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
#define N 
#define ll long long
#define endl "\n"
#define MID(a,b) (a+b)/2
#define pi pair<ll,ll>
#define pos pi
#define line pair<pos,pos>

using namespace std;

ll dist(pos p, pos q) {
	return (p.first - q.first)*(p.first - q.first) + (p.second - q.second)*(p.second - q.second);
}

ll ccw(pos p, pos q, pos r) {
	ll t = (q.first - p.first)*(r.second - p.second)
		-(q.second - p.second)*(r.first - p.first);
	if (t > 0) return 1;
	else if (t < 0) return -1;
	else return 0;
}

void getCH(vector<pos>& v) {
	swap(v[0], *min_element(v.begin(), v.end()));
	sort(v.begin() + 1, v.end(), [&](const pos& p,const pos& q) {
		ll cw = ccw(v[0], p, q);
		if (cw) return cw > 0;
		return dist(v[0], p) < dist(v[0], q);
	});

	vector<pos> ret;
	for (auto it : v) {
		while (ret.size() >= 2 && ccw(ret[ret.size() - 2], ret.back(), it) <= 0) ret.pop_back();
		ret.push_back(it);
	}
	v = ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j; //for문 변수 -> longlong필요한지 확인
	//int n; cin >> n;
	int n, m; cin >> n >> m;
	vector<pos> P1;
	vector<pos> P2;
	vector<pos> points;
	for (i = 0; i < n; i++) {
		ll a, b; cin >> a >> b;
		P1.push_back({ a,b });
	}
	for (i = 0; i < m; i++) {
		ll a, b; cin >> a >> b;
		P2.push_back({ a,b });
	}
	
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			points.push_back({ P1[i].first + P2[j].first,P1[i].second + P2[j].second });
		}
	}
	
	getCH(points);
	cout << points.size() << endl;
	for (auto it : points) {
		cout << it.first << " " << it.second << endl;
	}
	return 0;
}