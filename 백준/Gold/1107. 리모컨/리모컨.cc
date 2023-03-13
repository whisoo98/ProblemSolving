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
#define N 10'000'000
#define ll long long
#define endl "\n"
#define MID(a,b) (a+b)/2

using namespace std;

bool arr[N];

vector<int> channel(10,0);
int ans = 987654321;
void Solution(int n, int m) {
	for (int i = 1; i <= 2*n+10; i++) {
		int temp = i;
		int cnt = 0;
		while (temp) {
			int a = temp % 10;
			if (channel[a]) {
				cnt = 987654321;
				break;
			}
			temp /= 10;
			cnt++;
		}
		ans = min(ans, abs(i - n) + cnt);
		//cout << i << endl;
	}
	if(!channel[0])
		ans = min(ans, abs(n - 0) + 1);
	cout << min(ans,abs(n-100)) << endl;
}



int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j; //for문 변수 -> longlong필요한지 확인
	int n; cin >> n;
	int m; cin >> m;
	if (n == 100) {
		cout << 0 << endl;
		return 0;
	}
	if (m == 10) {
		cout << abs(n - 100) << endl;
		return 0;
	}
	for (int i = 0; i < m; i++) {
		int a; cin >> a;
		channel[a] = 1;
	}
	//time_t st  = time(0);
	Solution(n,m);
	//time_t ed = time(0);
	//cout << ed - st << endl;
	return 0;
}