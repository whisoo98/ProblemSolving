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


ll gasolin[N];
ll dist[N];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j; //for문 변수 -> longlong필요한지 확인
	int n; cin >> n;
	for (int i = 0; i < n-1; i++) {
		cin >> dist[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> gasolin[i];
	}
	ll min_gasolin = LLONG_MAX;
	ll sum = 0;
	for (int i = 0; i < n - 1;i++) {
		if (gasolin[i] < min_gasolin) {
			min_gasolin = gasolin[i];
		}
		sum += min_gasolin * dist[i];
	}
	cout << sum << endl;
	return 0;
}