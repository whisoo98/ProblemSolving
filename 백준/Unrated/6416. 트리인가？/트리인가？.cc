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
#define N 1000005
#define ll long long
#define endl "\n"
#define MID(a,b) (a+b)/2

using namespace std;

int in[N];
int cnt[N];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j; //for문 변수 -> longlong필요한지 확인
	int chk = 0;
	int k = 0;
	while (1) {
		int check = 0;
		k++;
		for (i = 1; i <= N; i++) {
			in[i] = 0;
			cnt[i] = 0;
		}

		while (1) {
			int a, b; cin >> a >> b;
			if (a + b == 0) break;
			if (a < 0 && b < 0) {
				chk++; break;
			}
			in[b]++;
			cnt[a]++;
			cnt[b]++;
		}
		if (chk) break;
		int cnt1 = 0;
		int count = 0;
		for (i = 1; i <= N; i++) {
			if (cnt[i]) {
				cnt1++;
				if (in[i] == 0) count++;
				if (in[i] > 1) check++;
			}
		}
		if (cnt1 && count != 1) check++;
		else if (cnt1 == 0) check = 0;

		if (check) cout << "Case " << k << " is not a tree." << endl;
		else cout << "Case " << k << " is a tree." << endl;
	}

	return 0;
}