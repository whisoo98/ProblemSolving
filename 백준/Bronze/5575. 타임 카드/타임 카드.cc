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
	for (i = 1; i <= 3; i++) {
		int h, m, s; cin >> h >> m >> s;
		//int tot = h * 3600 + m * 60 + s;
		int tot=0;
		int temp; cin >> temp;
		tot += (temp - h)*3600;
		cin >> temp;
		tot += (temp - m)*60;
		cin >> temp;
		tot += (temp - s);
		h = tot / 3600;
		tot %= 3600;
		m = tot / 60;
		s = tot % 60;
		cout << h << " " << m << " " << s << endl;
	}


	return 0;
}