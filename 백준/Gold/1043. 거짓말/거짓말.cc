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

int knows[N];
int visit[N];
vector<vector<int>> party;
vector<vector<int>> participant;

void Solution(int n, int m) {
	queue<int> not_fine_party;
	for (int i =0; i < n; i++) {
		if (knows[i]) {
			for (auto iter : participant[i]) {
				if (visit[iter] == 0) {
					not_fine_party.push(iter);
					visit[iter] = 1;
				}
			}
		}
	}
	while (not_fine_party.size()) {
		int now_party = not_fine_party.front();
		not_fine_party.pop();
		for (auto iter : party[now_party]) {
			for (auto party_iter : participant[iter]) {
				if (visit[party_iter] == 0) {
					not_fine_party.push(party_iter);
					visit[party_iter] = 1;
				}
			}
		}
	}
	int ans = m;
	for (int i = 0; i < m; i++) {
		ans -= visit[i];
	}
	cout << ans << endl;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j; //for문 변수 -> longlong필요한지 확인
	int n, m; cin >> n >> m;
	int num_knows; cin >> num_knows;
	for (int i = 0; i < num_knows; i++) {
		int know; cin >> know;
		knows[know - 1] = 1;
	}

	for (int i = 0; i < n; i++) {
		vector<int> v;
		participant.push_back(v);
	}

	for (int i = 1; i <= m; i++) {
		vector<int> v;
		int num_knows_in_party; cin >> num_knows_in_party;
		for (int j = 1; j <= num_knows_in_party; j++) {
			int know; cin >> know;
			participant[know - 1].push_back(i - 1);
			v.push_back(know-1);
		}
		party.push_back(v);
	}
	Solution(n, m);
	return 0;
}