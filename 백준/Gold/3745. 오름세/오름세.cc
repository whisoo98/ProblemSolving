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

int arr[N];
int dp[N];
vector<int> v;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j; //for문 변수 -> longlong필요한지 확인
	
	while (1) {
		int n; cin >> n;
		if (cin.eof()) break;
		for (i = 1; i <= n; i++) {
			cin >> arr[i];
		}
		for (i = 1; i <= n; i++) {
			int idx = lower_bound(v.begin(), v.end(), arr[i]) - v.begin();
			if (idx == v.size()) {
				v.push_back(arr[i]);
			}
			else v[idx] = arr[i];
		}
		cout << v.size() << "\n";


		for (i = 1; i <= n; i++) {
			arr[i] = 0;
		}
		v.clear();
	}

	return 0;
}