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
#define N 300005
using namespace std;

long long n, m;
long long arr[N];
long long ans=INT_MAX;
long long PS(long long left, long long right) {
	long long mid;
	if (left <= right) {
		mid = (left + right) / 2;
		//cout << left << " " << mid << " " << right << endl;
		long long tmp = 0;
		int Bool = 0;
		for (int i = 1; i <= m; i++) {
			long long rest = 0;
			long long mok = 0;
			mok = arr[i] / mid;
			rest = arr[i] % mid;
			if (rest) {
				//Bool = 1;
				mok++;
			}
			tmp += mok;
		}
		if (tmp == n) {
			if (Bool) {
				ans = min(mid + 1,ans);
			}
			else {
				ans = min(ans,mid);
			}
			return PS(left, mid - 1);
		}
		else if(tmp < n){
			ans = min(ans, mid);

			return PS(left, mid - 1);
		}
		else {
			return PS(mid + 1, right);
		}
	}
	else return ans;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j; //for문 변수 -> longlong필요한지 확인
	cin >> n >> m;
	for (i = 1; i <= m; i++) {
		cin >> arr[i];
	}
	PS(1, INT_MAX);
	cout << ans;
	return 0;
}