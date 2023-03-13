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
int cnt=1;
vector<int> v;
int colatz(int a) {
	v.push_back(a);

	if (a == 1) return cnt;
	cnt++;
	if (a % 2 == 0) {
		return colatz(a / 2);
	}
	else {
		return colatz(3 * a + 1);
	}
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j; //for문 변수 -> longlong필요한지 확인
	int n; cin >> n;
	colatz(n);
	for (auto it : v) {
		cout << it << " ";
	}
	return 0;
}