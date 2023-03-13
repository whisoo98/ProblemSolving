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
int parent[1000005];
int Find(int x) {
	if (parent[x] == x) return x;
	else return parent[x] = Find(parent[x]);
}

bool Find(int x, int y) {
	if (Find(x) == Find(y)) return true;
	return false;
}

void Union(int x, int y) {
	if (Find(x, y)) return;
	parent[Find(x)] = Find(y);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int i, j;//for문변수-->가끔식 long으로
	int n, m; cin >> n >> m;
	for (i = 0; i <= n; i++) {
		parent[i] = i;
	}
	for (i = 0; i < m; i++) {
		int cmd, a, b;
		cin >> cmd >> a >> b;
		if (cmd) {
			if (Find(a, b)) {
				cout << "YES\n";
			}
			else {
				cout << "NO\n";
			}
		}
		else {
			Union(a, b);
		}
	}

	//for(i=0;i<n;i++) {}
	//for(i=0;i<n;i++) { for(j=0;j<n;j++) { } }

	return 0;
}