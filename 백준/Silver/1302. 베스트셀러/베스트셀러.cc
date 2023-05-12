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


map<string, int> m;
vector<string>v;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j; //for문 변수 -> longlong필요한지 확인
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		if (m.count(s) == 0) {
			m.insert({ s,1 });
		}
		else {
			m[s] = m[s] + 1;
		}
	}
	int M = -1;
	for (auto it : m) {
		if (it.second > M) {
			v.clear();
			v.push_back(it.first);
			M = it.second;
		}
		else if (it.second == M) {
			v.push_back(it.first);
		}
	}
	sort(v.begin(), v.end());
	cout << v[0] << endl;
	return 0;
}