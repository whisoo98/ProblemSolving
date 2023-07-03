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


vector<pair<int, double>> candies;

int knapsack(int n, double money) {
	vector<int> dp(10005, 0);
	int int_money = (int)(money * 100 + 0.1);
	for (int i = 0; i < n; i++) {
		int price = (int)(candies[i].second*100 + 0.1);
		int cal = candies[i].first;
		for (int j = price; j <= int_money; j++) {
			dp[j] = max(dp[j], dp[j - price] + cal);
		}
	}
	return *max_element(dp.begin(), dp.end());
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j; //for문 변수 -> longlong필요한지 확인
	//cin.precision(2);
	while (1) {
		int n; cin >> n;
		double money; cin >> money;
		if (n == 0) break;
		for (int i = 0; i < n; i++) {
			int cal;
			double price;
			cin >> cal >> price;
			candies.push_back({ cal,price });
		}
		cout << knapsack(n, money) << endl;
		candies.clear();
	}
	return 0;
}
