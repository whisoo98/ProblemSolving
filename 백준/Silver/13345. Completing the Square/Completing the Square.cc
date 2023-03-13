#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <functional>
#include <stdlib.h>
#include <string>
#include <queue>
#include <stack>
#include <map>
#include <climits>
#include <cstring>
#include<cmath>

using namespace std;

/*struct type_name {

}srt;*/

//vector <type> vec;
//stack <type> stk;
//queue <type> q;
//string str;
//map <key_type,value_type> m;
vector<pair<int, int>> v;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int i, j;//for문변수-->가끔식 long으로
	for (i = 0; i < 3; i++) {
		int a, b; cin >> a >> b;
		v.push_back({ a,b });
	}
	double m = -987654321;
	int x1, x2, y1, y2;
	int x, y;
	for (i = 0; i < 3; i++) {
		double temp = m;
		m = max(m, pow(v[i % 3].first - v[(i + 1) % 3].first, 2) + pow(v[i % 3].second - v[(i + 1) % 3].second, 2));
		if (temp != m) {
			x1 = v[i % 3].first; y1 = v[i % 3].second;
			x2 = v[(i + 1) % 3].first; y2 = v[(i + 1) % 3].second;
			x = v[(i + 2) % 3].first; y = v[(i + 2) % 3].second;
		}
	}
	cout << x1 + x2 - x << " " << y1 + y2 - y;
	
	//for(i=0;i<n;i++) {}
	//for(i=0;i<n;i++) { for(j=0;j<n;j++) { } }

	return 0;
}