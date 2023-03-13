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

using namespace std;

long long x, y;
long long z;
long long ans = INT_MAX;

long long PS(long long left, long long right){
	if (left <= right) {
		long long mid = (left + right) / 2;
		long long tmp = ((y + mid) * 100) / (x + mid);
		if (tmp > z) {
			ans = min(ans, mid);
			return PS(left, mid - 1);
		}
		else if (tmp < z) {
			return PS(mid + 1, right);
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
	cin >> x >> y;
	
	z = (y * 100) / x;
	PS(1, INT_MAX);
	if (ans == INT_MAX) cout << -1;
	else cout << ans;
	return 0;
}