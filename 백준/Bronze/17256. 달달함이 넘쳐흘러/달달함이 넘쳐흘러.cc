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
	int a1, a2, a3; cin >> a1 >> a2 >> a3;
	int c1, c2, c3; cin >> c1 >> c2 >> c3;
	cout << c1 - a3 << " " << c2 / a2 << " " << c3 - a1;
	
	
	return 0;
}