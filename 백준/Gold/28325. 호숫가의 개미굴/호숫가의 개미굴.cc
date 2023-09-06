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
#define N 250'005
#define ll long long
#define endl "\n"
#define MID(a,b) (a+b)/2

using namespace std;

int arr[N];
int chk[N];
int chk_arr[N];
int ans;


void Solution(int n) {
	for (int i = 0; i < n; i++) {
		if (!chk[(i + n - 1) % n] && !chk[(i + 1) % n] && !chk_arr[i]) {
			ans += 1;
			chk[i] = 1;
		}
	}
	cout << ans << endl;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j; //for문 변수 -> longlong필요한지 확인
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		ans += arr[i];
		if (arr[i]) chk_arr[i] = 1;
	}
	Solution(n);
	return 0;
}