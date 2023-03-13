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


using namespace std;

/*struct type_name {

}srt;*/

//vector <type> vec;
//stack <type> stk;
//queue <type> q;
//string str;
//map <key_type,value_type> m;
vector<pair<int, int>>v;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int i, j;//for문변수-->가끔식 long으로
	int n; cin >> n;

	for(i=0;i<n;i++) {
		int a, b; cin >> a >> b;
		v.push_back({ a,b });
	}
	//for(i=0;i<n;i++) { for(j=0;j<n;j++) { } }
	sort(v.begin(), v.end());
	for (i = 0; i < n; i++) {
		cout << v[i].first << " " << v[i].second << "\n";
	}
	return 0;
}