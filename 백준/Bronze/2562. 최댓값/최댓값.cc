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

using namespace std;




int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j; //for문 변수 -> longlong필요한지 확인
	int m = -1, pos;
	for (i = 0; i < 9; i++) {
		int a; cin >> a;
		if (a > m) {
			m = a;
			pos = i + 1;
		}
	}
	cout << m << "\n" << pos;
	
	
	
	
	return 0;
}