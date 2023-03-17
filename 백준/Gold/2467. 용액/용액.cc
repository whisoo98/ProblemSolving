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
#define N 100'005
#define ll long long
#define endl "\n"
#define MID(a,b) (a+b)/2

using namespace std;

vector<int> acid;
vector<int> alkali;
int ans = INT_MAX;
int ans_acid;
int ans_alkali;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j; //for문 변수 -> longlong필요한지 확인
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		if (a > 0) acid.push_back(a);
		else alkali.push_back(-a);
	}
	sort(acid.begin(), acid.end());
	sort(alkali.begin(), alkali.end());
	if (acid.size() == 0) {
		cout << -alkali[1] << " " << -alkali[0] << endl;
		return 0;
	}
	if (alkali.size() == 0) {
		cout << acid[0] << " " << acid[1] << endl;
		return 0;
	}

	for (auto Acid : acid) {
		int chk0 = 0;
		int chk1 = 0;

		int idx0 = lower_bound(alkali.begin(), alkali.end(), Acid) - alkali.begin();
		int idx1 = upper_bound(alkali.begin(), alkali.end(), Acid) - alkali.begin();
		int idx2 = idx0 > 0 ? idx0 - 1 : 0;
		if (idx0 == alkali.size()) {
			idx0--;
		}
		if (idx1 == alkali.size()) {
			idx1--;
		}

		int temp0 = abs(Acid - alkali[idx0]);
		if (ans > temp0) {
			ans = temp0;
			ans_acid = Acid;
			ans_alkali = -alkali[idx0];
		}


		int temp1 = abs(Acid - alkali[idx1]);

		if (ans > temp1) {
			ans = temp1;
			ans_acid = Acid;
			ans_alkali = -alkali[idx1];
		}
		int temp2 = abs(Acid - alkali[idx2]);

		if (ans > temp2) {
			ans = temp2;
			ans_acid = Acid;
			ans_alkali = -alkali[idx2];
		}
	}

	int temp0 = INT_MAX;
	int temp1 = INT_MAX;
	if (acid.size() >= 2) {
		temp0 = acid[0] + acid[1];
	}
	if (alkali.size() >= 2) {
		temp1 = alkali[0] + alkali[1];
	}
	if (ans > temp0) {
		ans = temp0;
		ans_acid = acid[1];
		ans_alkali = acid[0];
	}
	if (ans > temp1) {
		ans = temp1;
		ans_acid = -alkali[0];
		ans_alkali = -alkali[1];
	}
	cout << ans_alkali << " " << ans_acid << endl;
	return 0;
}