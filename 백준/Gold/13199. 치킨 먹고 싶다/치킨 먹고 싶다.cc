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



map<tuple<ll, ll, ll>, ll> dp;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j; //for문 변수 -> longlong필요한지 확인
	int T; cin >> T;
	while (T--) {
		ll price, money, F, coupon;
		cin >> price >> money >> F >> coupon;
		tuple<ll, ll, ll> tp = { money / price, F, coupon };
		if (dp.find(tp) != dp.end()) {
			cout << dp[{money / price, F, coupon}] << endl;
			continue;
		}
		ll sang = 0, dou = 0;
		ll Cs=0, Cd=0;
		dou += (money / price);
		sang = dou;

		Cs = Cd = (money / price)*coupon;
		dou += Cd / F;

		if (Cs < F) {
			sang += Cs / F;
			cout << sang - dou << endl;
		}
		else {
			ll del = F - coupon;
			sang += (Cs - F) / del;
			sang++;

			cout << sang - dou << endl;
		}
		dp[{money / price, F, coupon}] = sang - dou;
	
	}

	return 0;
}