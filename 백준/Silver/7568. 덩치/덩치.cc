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
#define N 55
#define ll long long
#define endl "\n"
#define MID(a,b) (a+b)/2

using namespace std;

pair<int, int> p[N];
int arr[N];
//int brr[N];
vector<int> v;
int ranking[10005];
int cnt[10005];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j; //for문 변수 -> longlong필요한지 확인
	int n; cin >> n;
	for (i = 1; i <= n; i++) {
		arr[i] = 1;
		int a, b; cin >> a >> b;
		p[i] = { a,b };
	}
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			if (i == j) continue;
			if (p[j].first > p[i].first && p[j].second > p[i].second) {
				ranking[i]++;
			}
		}
	}
	for (i = 1; i <= n; i++) {
		cout << ranking[i]+1 << " ";
	}
	return 0;
}