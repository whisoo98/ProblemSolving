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
#define N 1005
#define ll long long
#define endl "\n"
#define MID(a,b) (a+b)/2

using namespace std;


vector<int> cards[N];
vector<int> sums[N];
vector<pair<int,int>> M;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j; //for문 변수 -> longlong필요한지 확인
	int n; cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < 5; j++) {
			int a; cin >> a;
			cards[i].push_back(a);
		}
	}
	for (int i = 1; i <= n; i++) {
		sums[i].push_back((cards[i][0] + cards[i][1] + cards[i][2])%10);
		sums[i].push_back((cards[i][0] + cards[i][1] + cards[i][3]) % 10);
		sums[i].push_back((cards[i][0] + cards[i][1] + cards[i][4]) % 10);
		sums[i].push_back((cards[i][0] + cards[i][2] + cards[i][3]) % 10);
		sums[i].push_back((cards[i][0] + cards[i][2] + cards[i][4]) % 10);
		sums[i].push_back((cards[i][0] + cards[i][3] + cards[i][4]) % 10);
		sums[i].push_back((cards[i][1] + cards[i][2] + cards[i][3]) % 10);
		sums[i].push_back((cards[i][1] + cards[i][2] + cards[i][4]) % 10);
		sums[i].push_back((cards[i][1] + cards[i][3] + cards[i][4]) % 10);
		sums[i].push_back((cards[i][2] + cards[i][3] + cards[i][4]) % 10);
		sort(sums[i].begin(), sums[i].end(), greater<int>());
		M.push_back({ sums[i][0],i });
	}
	sort(M.begin(), M.end(),greater<pair<int,int>>());
	cout << M[0].second << endl;
	return 0;
}