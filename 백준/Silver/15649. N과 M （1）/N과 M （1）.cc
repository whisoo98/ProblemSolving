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
int n, m;
int arr[N];
int check[N];
int brr[N];

void backtracking(int lv) {
	if (lv == m) {
		for (int i = 1; i <= m; i++) {
			cout << brr[i] << " ";
		}
		cout << endl;
		return;
	}	
	for (int i = 1; i <= n; i++) {
		if (check[i] == 0) {
			brr[lv + 1] = arr[i];
			check[i] = 1;
			backtracking(lv + 1);
			check[i] = 0;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j; //for문 변수 -> longlong필요한지 확인
	cin >> n >> m;
	for (i = 1; i <= n; i++) {
		arr[i] = i;
	}
	
		backtracking(0);
	
	return 0;
}