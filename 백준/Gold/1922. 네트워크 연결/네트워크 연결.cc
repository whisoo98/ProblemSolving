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
bool Find(int x, int y) {
	if (Find(x) == Find(y)) return true;
	return false;
}
void Union(int x, int y) {
	if (Find(x, y)) return;
	else parent[Find(x)] = Find(y);
}
int n, m;
int C;
priority_queue<tuple<int,int,int>> pq;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int i, j;//for문변수-->가끔식 long으로
	cin >> n >> m;
	for (i = 1; i <= n; i++) parent[i] = i;
	for (i = 0; i < m; i++) {
		int a, b, cost;
		cin >> a >> b >> cost;
		pq.push({ -cost,a,b });
	}
	while (!pq.empty()) {
		int cost = -get<0>(pq.top());
		int a = get<1>(pq.top());
		int b = get<2>(pq.top());
		pq.pop();
		if (!Find(a, b)) {
			Union(a, b);
			C += cost;
		}
	}
	cout << C;
	//for(i=0;i<n;i++) {}
	//for(i=0;i<n;i++) { for(j=0;j<n;j++) { } }

	return 0;
}