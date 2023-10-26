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

int ans;
int n;
vector<int> v;


void bruteForce() {
	for (int i = 0; i < n; i++) {
		int continueous = 0;
		for (int j = i; j < n && j <= i + 4; j++) {
			if (v[j] - v[i] <= 4) {
				continueous++;
			}
			else {
				break;
			}
		}
		ans = max(ans, continueous);
	}
	ans = min(ans, 5);
}


void Solution() {
	bruteForce();
	cout << 5 - ans << endl;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j; //for문 변수 -> longlong필요한지 확인
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		v.push_back(a);
	}
	sort(v.begin(), v.end());
	Solution();
	return 0;
}