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




int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j; //for문 변수 -> longlong필요한지 확인
	int n; cin >> n;
	vector<int> v;
	for (int i = 1; i <= n; i++) {
		v.push_back(i);
	}
	while (1) {
		for (auto it : v) {
			cout << it << " ";
		}
		cout << endl;
		if (!next_permutation(v.begin(), v.end())) {
			break;
		}
	}
	return 0;
}