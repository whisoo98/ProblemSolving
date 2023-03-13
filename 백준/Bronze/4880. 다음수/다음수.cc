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
	while (1) {
		int a, b, c; cin >> a >> b >> c;
		if (a == 0 && b == 0 && c == 0) break;
		if (a == b && b == c) {
			cout << "GP " << a << endl;
			continue;
		}
		if (2 * b == (a + c)) {
			cout << "AP " << 2 * c - b<<endl;
		}
		else cout << "GP " << c * c / b<<endl;
	}

	return 0;
}