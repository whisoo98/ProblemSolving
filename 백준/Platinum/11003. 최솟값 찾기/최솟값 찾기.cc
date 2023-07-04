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
#define N 5'000'005
#define ll long long
#define endl "\n"
#define MID(a,b) (a+b)/2

using namespace std;

int n, l;
int arr[N];

void Solution() {
	priority_queue<pair<int, int>> pq;
	for (int i = 0; i < n; i++) {
		pq.push({ -arr[i],-i });
		while (-pq.top().second + l <= i) {
			pq.pop();
		}
		cout << -pq.top().first<<" ";	
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j; //for문 변수 -> longlong필요한지 확인
	cin >> n >> l;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	Solution();
	return 0;
}