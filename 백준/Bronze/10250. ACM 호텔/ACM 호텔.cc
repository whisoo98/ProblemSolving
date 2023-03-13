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
	int T; cin >> T;
	while (T--) {
		int height, width, num; cin >> height >> width >> num;
		int mok = num / height;
		int rest = num % height;
		mok++;
		if (rest == 0) {
			rest = height;
			mok--;
		}
		
		cout << rest;
		if (mok < 10) {
			cout << 0 << mok;
		}
		else cout << mok;
		cout << "\n";
	}
	
	
	
	return 0;
}