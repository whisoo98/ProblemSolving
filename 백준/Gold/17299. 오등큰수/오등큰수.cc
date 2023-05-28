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
int cnt[N];
int ngf[N];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j; //for문 변수 -> longlong필요한지 확인
	int n; cin >> n;
	stack<int> stk;
	stack<int> idx;
	priority_queue<pair<int, int>> pq;
	int M = -1;
	for (int i = 1; i <= n; i++) {
		int a; cin >> a;
		arr[i] = a;
		cnt[a]++;
	}
	stk.push(cnt[arr[1]]);
	idx.push(1);
	for (int i = 2; i <= n; i++) {
		while (1) {
			if (stk.empty()) {
				stk.push(cnt[arr[i]]);
				idx.push(i);
				break;
			}
			if (stk.top() < cnt[arr[i]]) {
				stk.pop();
				int index = idx.top();
				idx.pop();
				ngf[index] = arr[i];
			}
			else {
				stk.push(cnt[arr[i]]);
				idx.push(i);
				break;
			}
		}
	}
	while (stk.size()) {
		int index = idx.top();
		stk.pop();
		idx.pop();
		ngf[index] = -1;
	}
	for (int i = 1; i <= n; i++) {
		cout << ngf[i] << " ";
	}
	cout << endl;
	return 0;
}