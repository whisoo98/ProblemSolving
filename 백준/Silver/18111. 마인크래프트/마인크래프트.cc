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
#define ll long long
using namespace std;

ll block;
int arr[505][505];
int x, y;
ll ans = LLONG_MAX;
int high;
//block 제거 2초 block넣기 1초

void brute(int height) {
	int i, j;
	ll temp = 0;
	ll B = block;
	for (i = 1; i <= y; i++) {
		for (j = 1; j <= x; j++) {
			if (arr[i][j] > height) {
				temp += (arr[i][j] - height) * 2;
				B += (ll)(arr[i][j] - height);
			}
			else {
				temp += (height - arr[i][j]);
				B -= (ll)(height - arr[i][j]);
			}
		}
	}
	if (B < 0) return;
	if (temp < ans) {
		ans = temp;
		high = height;
	}
	else if (temp == ans) {
		high = max(height, high);
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j; //for문 변수 -> longlong필요한지 확인
	cin >> y >> x >> block;
	for (i = 1; i <= y; i++) {
		for (j = 1; j <= x; j++) {
			cin >> arr[i][j];
		}
	}
	for (i = 0; i <= 256; i++) {
		brute(i);
	}
	cout << ans << " " << high;
	return 0;
}	