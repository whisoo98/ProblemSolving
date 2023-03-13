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
		int n; cin >> n;
		int L = 0, R = 0;
		for (i = 1; i <= n; i++) {
			char l, r; cin >> l >> r;
			//cout << l << " " << r << endl;
			if (l == 'R') {
				if (r == 'R') {
					continue;
				}
				else if (r == 'S') {
					L++;
				}
				else {
					R++;
				}
			}
			else if (l == 'S') {
				if (r == 'R') {
					R++;
				}
				else if (r == 'S') {
					continue;
				}
				else {
					L++;
				}
			}
			else {
				if (r == 'R') {
					L++;
				}
				else if (r == 'S') {
					R++;
				}
				else {
					continue;
				}
			}
		}
		if (L > R) {
			cout << "Player 1" << endl;
		}
		else if (L == R) {
			cout << "TIE" << endl;
		}
		else cout << "Player 2" << endl;
	}

	return 0;
}