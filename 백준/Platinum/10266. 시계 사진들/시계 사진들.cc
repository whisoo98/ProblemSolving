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

#define N 200'005
#define ll long long
#define endl "\n"
#define MID(a,b) (a+b)/2
#define MOD 360'000

using namespace std;

int brr[N];
int arr[N];
int tmp[2*N];
int tmp2[N];

int pi[N];

void getPi(int n) {
	int mat = 0;
	for (int i = 1; i < n; i++) {
		if (tmp2[i] == tmp2[mat]) {
			pi[i] = ++mat;
		}
		else if (mat) {
			i--;
			mat = pi[mat - 1];
		}
	}
}

int kmp(int n) {
	int mat = 0;
	int ret = 0;
	for (int i = 0; i < 2*n-1; i++) {
		if (tmp[i] == tmp2[mat]) {
			++mat;
			if (mat == n) {
				ret++;
				mat = pi[mat - 1];

			}
		}
		else if(mat){
			i--;
			mat = pi[mat - 1];
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
	int n; cin >> n;
	int a, b;
	int chk = 0;

	for (i = 0; i < n; i++) {
		cin >> arr[i];
	}
	for (i = 0; i < n; i++) {
		cin >> brr[i];
	}
	sort(arr, arr + n);
	sort(brr, brr + n);

	for (i = 0; i < n - 1; i++) {
		tmp[i] = arr[i + 1] - arr[i];
		tmp2[i] = brr[i + 1] - brr[i];
	}

	tmp[n - 1] = (arr[0] + MOD - arr[n - 1]) % MOD;
	tmp2[n - 1] = (brr[0] + MOD - brr[n - 1]) % MOD;

	for (i = n; i < 2 * (n); i++) {
		tmp[i] = tmp[i - (n)];
	}
	getPi(n);
	int cnt = kmp(n);
	if (cnt) cout << "possible";
	else cout << "impossible";
	return 0;
}