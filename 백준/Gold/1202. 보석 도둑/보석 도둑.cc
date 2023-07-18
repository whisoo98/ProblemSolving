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
#define N 300'005
#define M 100'000'005
#define ll long long
#define endl "\n"
#define MID(a,b) (a+b)/2

using namespace std;


//int knapsack[N];
map<ll, int> knapsack;
//set<ll> knapsack;
vector <pair<ll, ll>> jewerly;
ll bag[N];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j; //for문 변수 -> longlong필요한지 확인
	int n, k; cin >> n >> k;
	ll ans = 0;
	for (int i = 1; i <= n; i++) {
		ll a, b; cin >> a >> b;
		jewerly.push_back({ b,a });
	}
	for (int i = 1; i <= k; i++) {
		ll a; cin >> a;
		if (knapsack.count(a))
			knapsack[a]++;
		else
			knapsack[a] = 1;
		//knapsack.insert(a);
	}
	sort(jewerly.begin(), jewerly.end(), greater<pair<ll, ll>>());
	//sort(knapsack.begin(), knapsack.end());
	for (auto jwl : jewerly) {
		ll gram = jwl.second;
		ll value = jwl.first;
		
		//auto iter = lower_bound(knapsack.begin(), knapsack.end(), gram);
		auto iter = knapsack.lower_bound(gram);
		//int idx = lower_bound(knapsack.begin(), knapsack.end(), gram) - knapsack.begin();
		//if (idx >= (ll)knapsack.size()) continue;
		if (iter == knapsack.end()) continue;
		ans += value;
		(*iter).second--;
		if ((*iter).second == 0)
			knapsack.erase(iter);
		//knapsack[idx] = -1;
		//knapsack.erase(iter);
	}
	cout << ans << endl;
	return 0;
}