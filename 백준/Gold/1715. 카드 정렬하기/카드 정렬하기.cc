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

ll cards[N];
priority_queue<ll> pq;
int n;

void Solution() {
	ll ans = 0;
	for (int i = 0; i < n; i++) {
		pq.push(-cards[i]);
	}
	while (pq.size() > 1) {
		ll left = -pq.top(); pq.pop();
		ll right = -pq.top(); pq.pop();
		ll sum = left + right;
		pq.push(-sum);
		ans += sum;
		//cout << sum << endl;
	}
	cout << ans << endl;

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j; //for문 변수 -> longlong필요한지 확인
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> cards[i];
	}
	Solution();
	return 0;
}