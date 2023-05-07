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
#define N 105
#define ll long long
#define endl "\n"
#define MID(a,b) (a+b)/2

using namespace std;

int group[N][N];
int grouped;
int not_stable;
vector<vector<int>> stable;
int visit[N];
int check[N];
void isStable(int idx, int n) {
	queue<int> q;
	q.push(idx);
	while (q.size()) {
		int now = q.front();
		q.pop();
		for (int i = 1; i <= n; i++) {
			if (!group[now][i]) {
				if (!group[i][now] && !visit[i]) {
					visit[i] = 1;
					q.push(i);
				}
				else if(group[i][now]){
					not_stable = 1;
					break;
				}
			}
		}
	}
	if (!not_stable) {
		vector<int> temp;
		grouped++;
		for (int i = 1; i <= n; i++) {
			if (visit[i]) {
				check[i]=1;
				visit[i] = 0;
				temp.push_back(i);
			}
		}
		if (temp.size() < 2) {
			not_stable = 1;
		}
		stable.push_back(temp);
	}
}

void Solution(int n) {
	for (int i = 1; i <= n; i++) {
		if (check[i] == 0 && !not_stable) {
			visit[i]=1;
			isStable(i, n);
		}
	}
	if (not_stable) {
		cout << 0 << endl;
	}
	else {
		cout << grouped << endl;
		sort(stable.begin(), stable.end());
		for (int i = 0; i < grouped; i++) {
			for (auto it : stable[i]) {
				cout << it << " ";
			}
			cout << endl;
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j; //for문 변수 -> longlong필요한지 확인
	int n; cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> group[i][j];
		}
	}
	Solution(n);
	return 0;
}