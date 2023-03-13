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
#define N 10005
#define ll long long
#define MID(a,b) (a+b)/2
#define MAXY 30000
using namespace std;

vector<tuple<int,int,int,ll>> line;
vector<int> Y;
ll arr[N];
ll tree[4 * MAXY];
ll ysum[4 * N];
ll cnt[4 * MAXY];

void update(int start, int end, int node, int idx, ll diff) {
	if (idx<start || idx>end) return;
	tree[node] += diff;
	if (start == end) return;
	int mid = MID(start, end);
	update(start, mid, node * 2, idx, diff);
	update(mid + 1, end, node * 2 + 1, idx, diff);
}


void update_range(int start, int end, int node, int left, int right, ll diff) {
	if (start > right || end < left) return;
	
	if (left <= start && end <= right) {
		cnt[node] += diff;
		//tree[node] += (end - start + 1)*diff;
		//return;
	}
	else {
		int mid = MID(start, end);
		update_range(start, mid, node * 2, left, right, diff);
		update_range(mid + 1, end, node * 2 + 1, left, right, diff);
	}
	if (cnt[node]) {
		tree[node] = end - start + 1;
	}
	else {
		if (start == end) tree[node] = 0;
		else tree[node] = tree[node * 2] + tree[node * 2 + 1];
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
		int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
		Y.push_back(y1);
		Y.push_back(y2);
		line.push_back({ x1,y1,y2 - 1,1 });
		line.push_back({ x2,y1,y2 - 1,-1 });
	}
	Y.erase(unique(Y.begin(), Y.end()), Y.end());
	sort(line.begin(), line.end());
	ll ans = 0;
	int last;
	for (i = 0; i < 2 * n; i++) {
		if (i) {
			int dx = get<0>(line[i]) - last;
			ans += dx * tree[1];
			//cout << tree[1] << endl;
		}
		update_range(0, MAXY, 1, get<1>(line[i]), get<2>(line[i]), get<3>(line[i]));
		last = get<0>(line[i]);
	}
	cout << ans;


	return 0;
}