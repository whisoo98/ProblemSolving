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
#define N 10
#define ll long long
#define endl "\n"
#define MID(a,b) (a+b)/2

using namespace std;

int arr[N];
int brr[N];
int check[N];
int n, m;

void backtracking(int now, int lv) {
	if (lv == m) {
		for (int i = 1; i <= m; i++) {
			cout << brr[i] << " ";
		}
		cout << endl;
		return;
	}
//	if (n - now + 1 < m) return;

	for (int i = now; i <= n; i++) {
		brr[lv + 1] = arr[i];
		backtracking(i + 1, lv + 1);
	}
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j; //for문 변수 -> longlong필요한지 확인
	cin >> n >> m;
	for (i = 1; i <= n; i++) arr[i] = i;
	backtracking(1,0);

	return 0;
}