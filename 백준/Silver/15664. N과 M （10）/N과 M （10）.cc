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
#define N 
#define ll long long
#define endl "\n"
#define MID(a,b) (a+b)/2

using namespace std;

map<vector<int>, int> used;


void dfs(int st, int lv, int n, int m, vector<int>& comb, vector<int>& arr) {
	if (lv == m) {
		if (used[comb]==0) {
			for (auto it : comb) {
				cout << it << " ";
			}
			cout << endl;
			used[comb] = 1;
		}
		return;
	}
	for (int i = st; i < n; i++) {
		comb.push_back(arr[i]);
		dfs(i + 1, lv + 1, n, m, comb, arr);
		comb.pop_back();
	}
}

void Solution(int n, int m, vector<int>& arr) {
	vector<int> comb;
	dfs(0, 0, n, m, comb, arr);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j; //for문 변수 -> longlong필요한지 확인
	int n, m; cin >> n >> m;
	vector<int> arr;
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		arr.push_back(a);
	}
	sort(arr.begin(), arr.end());
	Solution(n, m, arr);
	return 0;
}