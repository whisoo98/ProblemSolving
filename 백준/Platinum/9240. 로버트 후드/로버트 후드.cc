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

pos makepos(pos p, pos q) {
	pos r = { q.first - p.first,q.second - p.second };
	return r;
}

ll dist(pos p, pos q) {
	return (p.first - q.first)*(p.first - q.first) + (p.second - q.second)*(p.second - q.second);
}

ll ccw(pos p, pos q) {
	ll c = (p.first)*(q.second) - (p.second)*(q.first);
	if (c > 0) return 1;
	else if (c < 0) return -1;
	return 0;
}

/*ll ccw(pos p, pos q, pos r) {
	pos t = makepos(p, q);
	pos tt = makepos(p, r);
	return ccw(t, tt);
}*/
ll ccw(pos p, pos q, pos r) {
	ll c = (q.first - p.first)*(r.second - p.second)
		- (q.second - p.second)*(r.first - p.first);
	if (c > 0) return 1;
	else if (c < 0) return -1;
	return 0;
}

void getCH(deque<pos>& v) {
	swap(v[0], *min_element(v.begin(), v.end()));
	
	sort(v.begin() + 1, v.end(), [&](pos p, pos q) {
		ll c = ccw(v[0], p, q);
		if (c) return c > 0;
		return dist(v[0], p) < dist(v[0], q);
	});

	deque<pos> res;
	for (auto it : v) {
		while (res.size() >= 2 && ccw(*(res.end() - 2), res.back(), it) <= 0) res.pop_back();
		res.push_back(it);
	}

	v = res;
}

void rotating_calipers(deque<pos>& v, ll* ans) {
	getCH(v);
	int i, j = 1;
	pos p, q;
	int size = v.size();
	
	ll dst = 0;
	for (i = 0; i < size; i++) {
		int ni = (i + 1) % size;
		pos tp, tq;
		while (1) {
			int nj = (j + 1) % size;
			tp = makepos(v[i], v[ni]);
			tq = makepos(v[j], v[nj]);
			if (ccw(tp, tq) > 0) j = nj;
			else break;
		}
		if (dst < dist(v[i], v[j])) {
			dst = dist(v[i], v[j]);
			p = v[i];
			q = v[j];
		}
	}
	*ans = dst;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//cout.tie(NULL);

	int i, j; //for문 변수 -> longlong필요한지 확인
	int n; cin >> n;
	deque<pos> v;
	
	if (n == 2) {
		for (i = 0; i < n; i++) {
			ll a, b; cin >> a >> b;
			v.push_back({ a,b });
		}
		//cout << sqrt(dist(v[0], v[1]));
		printf("%.10lf", sqrt(dist(v[0], v[1])));
		return 0;
	}
	ll ans;
	for (i = 0; i < n; i++) {
		ll a, b; cin >> a >> b;
		v.push_back({ a,b });
	}
	rotating_calipers(v, &ans);
	

	printf("%.10lf", sqrt(ans));
	return 0;
}