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
int pi[N];

void getPi(int n) {
	int mat = 0;
	for (int i = 1; i < n; i++) {
		if (arr[i] == arr[mat]) {
			pi[i] = ++mat;
		}
		else if (mat) {
			i--;
			mat = pi[mat - 1];
		}
	}
}

int kmp(int tried,int n) {//k값 출력
	int mat = 0;
	int ret = 0;
	for (int i = 0; i <= tried; i++) {
		if (arr[i] == arr[mat]) {
			mat++;
			if (mat > ret) {
				ret = mat;
				mat = pi[mat - 1];
			}
		}
		else if (mat) {
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
	int m = 0;
	int ans=0;
	for (i = n - 1; i >= 0; i--) {
		cin >> arr[i];
	}
	getPi(n);
	for (i = n-1; i >0 ; i--) {
		//cout << pi[i] << " ";
		if (pi[i] > m) {
			m = pi[i];
			ans = 1;
		}
		else if (pi[i] == m) {
			ans++;
		}
	}
	
	if (m == 0) {
		cout << -1 << endl;
	}
	else cout << m << " " << ans << endl;
	return 0;
}