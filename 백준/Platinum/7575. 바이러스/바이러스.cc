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
#define endl "\n"
#define MID(a,b) (a+b)/2

using namespace std;

int pi[N];
vector<int>v[105];

void getPi(int start, int end, int k) {
	int mat = 0;
	for (int i = start+1; i < end; i++) {
		if (v[1][i] == v[1][mat]) {
			pi[i] = ++mat;
		}
		else if (mat) {
			i--;
			mat = pi[mat - 1];
		}
	}
}



int kmp(int start,int end,int k,int ith) {
	int mat = 0;
	int ret = 0;
	int size = v[ith].size();

	for (int i = 0; i < size; i++) {
		if (v[ith][i] == v[1][start + mat]) {
			mat++;
			if (mat == k) {
				ret++;
				mat = pi[mat - 1];
			}
		}
		else if (mat) {
			mat = pi[mat - 1];
			i--;
		}
	}

	mat = 0;
	for (int i = size-1; i >=0; i--) {
		if (v[ith][i] == v[1][start + mat]) {
			mat++;
			if (mat == k) {
				ret++;
				mat = pi[mat - 1];
			}
		}
		else if (mat) {
			mat = pi[mat - 1];
			i++;
		}
	}
	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j; //for문 변수 -> longlong필요한지 확인
	int n, k; cin >> n >> k; 

	for (i = 1; i <= n; i++) {
		int m; cin >> m;
		//v[i](1005, 0);
		for (j = 1; j <= m; j++) {
			int a; cin >> a;
			//v[i][j] = a;
			v[i].push_back(a);
		}
	}

	int s= v[1].size();
	bool chk = 0;
	int sum = 0;
	for (i = 0; i <= s - k; i++) {
		sum = 0;
		getPi(i, i + k, k);
		int cnt = 0;
		for (j = 2; j <= n; j++) {
			cnt = kmp(i, i + k, k, j);
			if (cnt) sum++;
		}
		if (sum == n - 1) {
			chk++;
			break;
		}

		for (int t = 1; t <= k; t++) {
			pi[t] = 0;
		}
	}
	if (chk) cout << "YES" << endl;
	else cout << "NO" << endl;
	return 0;
}