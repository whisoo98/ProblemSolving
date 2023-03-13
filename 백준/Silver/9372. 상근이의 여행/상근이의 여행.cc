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

int parent[1005];


int Find(int x) {
	if (parent[x] == x) return x;
	else return parent[x] = Find(parent[x]);
}

void Union(int x, int y) {
	if (Find(x) == Find(y)) return;
	parent[Find(x)] = Find(y);
}
int visit[1005];
vector<int>v[1005];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int i, j;//for문변수-->가끔식 long으로
	int T; cin >> T;
	while (T--) {
		int n, m; cin >> n >> m;
		for (i = 1; i <= n; i++) parent[i] = i;

		for (i = 0; i < m; i++) {
			int a, b; cin >> a >> b;
			Union(a, b);
			v[parent[b]].push_back(a);
		}
		cout << n - 1 << "\n";
		
		
	}
	
	//for(i=0;i<n;i++) {}
	//for(i=0;i<n;i++) { for(j=0;j<n;j++) { } }

	return 0;
}