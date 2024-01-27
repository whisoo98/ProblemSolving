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
#define N 1'000'005
#define ll long long
#define endl "\n"
#define MID(a,b) (a+b)/2

using namespace std;


int arr[N];
int brr[N];



void Solution(int n, int m) {
	sort(brr, brr + m);
	ll ans = 0;
	for (int i = 0; i < n; i++) {
		int idx = lower_bound(brr, brr + m, arr[i]) - brr;
		int target;
		if (idx == m) {
			target = brr[idx-1];
		}
		else {
			if (idx == 0) {
				target = brr[idx];
			}
			else {

				int diff1 = abs(arr[i] - brr[idx]);
				int diff2 = abs(arr[i] - brr[idx - 1]);
				if (diff1 < diff2) {
					target = brr[idx];
				}
				else {
					target = brr[idx - 1];
				}
			}
		}
		ans += target;
	}
	cout << ans << endl;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j; //for문 변수 -> longlong필요한지 확인
	int T; cin >> T;
	while (T--) {
		int n, m; cin >> n >> m;
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}
		for (int i = 0; i < m; i++) {
			cin >> brr[i];
		}
		Solution(n, m);
	}
	return 0;
}
