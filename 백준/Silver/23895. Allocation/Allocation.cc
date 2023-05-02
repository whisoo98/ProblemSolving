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

	int T; cin >> T;
	for (int t = 1; t <= T; t++) {
		int n, b; cin >> n >> b;
		vector<int> houses;
		for (int i = 0; i < n; i++) {
			int a; cin >> a;
			houses.push_back(a);
		}
		int cnt = 0;
		sort(houses.begin(), houses.end());
		for (auto house : houses) {
			if (house <= b) {
				b -= house;
				cnt++;
			}
			else {
				break;
			}
		}
		cout << "Case #" << t << ": " << cnt << endl;
	}

	return 0;
}