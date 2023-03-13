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
	int T; cin >> T;
	while (T--) {
		int x1, y1, r1, x2, y2, r2;
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
		if (x1 == x2 && y1 == y2) {
			if (r1 == r2) {
				cout << -1 << endl;
				continue;
			}
			else {
				cout << 0 << endl;
				continue;
			}
		}
		double dist = sqrt(pow(abs(x1 - x2), 2) + pow(abs(y1 - y2), 2));
		
		if (dist == r1 + r2) {
			cout << 1 << endl;
		}
		else if (dist > r1 + r2) {
			cout << 0 << endl;
		}
		else if (dist == abs(r1 - r2)) {
			cout << 1 << endl;
		}
		else if (dist < abs(r1 - r2)) {
			cout << 0 << endl;
		}
		else cout << 2 << endl;
	}

	return 0;
}