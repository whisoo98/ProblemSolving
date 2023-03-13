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
	int a, b, c;
	while (1) {
		cin >> a >> b >> c;// a 초항 bd diff, c가 되게
		if (a==0 && b==0 && c==0) break;
		if (b == 0) {
			if (a == c) {
				cout << 1 << endl;
				continue;
			}
			else {
				cout << "X" << endl;
				continue;
			}
		}
		int res = c - a;
		int mok = res / b;
		int rest = res % b;
		if (rest) {
			cout << 'X' << endl;
		}
		else if (mok >= 0) cout << mok + 1 << endl;
		else cout << 'X' << endl;

	}

	return 0;
}