#include <stdio.h>
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


using namespace std;

/*struct type_name {

}srt;*/

//vector <type> vec;
//stack <type> stk;
//queue <type> q;
//string str;
//map <key_type,value_type> m;

vector<int> v[200005];
int parent[200005];
int tree[200005];

int Find(int x,int origin) {
	if (parent[x] == x) return x;
	else return parent[x]=Find(parent[x],origin);		
}
void dfs(int x,int origin) {
	int size = v[x].size();
	for (int i = 0; i < size; i++) {
		parent[v[x][i]] = origin;
		dfs(v[x][i],origin);
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int i, j;//for문변수-->가끔식 long으로
	int V, Q;
	
	//scanf("%d %d", &V, &Q);
	cin >> V >> Q;
	parent[1] = 1;
	tree[1] = 1;
	for (i = 2; i <= V; i++) {	
		//scanf("%d", &parent[i + 1]);
		//cin >> parent[i + 1];
		int a; cin >> a;
		parent[i] = a;
		tree[i] = a;
		v[a].push_back(i);
		//parent[i + 1] = tree[i + 1];
	}
	int cnt = 0;
	while(cnt<Q){

		int command;
		//scanf("%d", &command);
		cin >> command;
		if (command) {	
			int a, b;//질문
			//scanf("%d %d", &a, &b);
			cin >> a >> b;
			cnt++;
			if (Find(a,a) == Find(b,b)) cout << "YES\n";
			else cout << "NO\n";
		}
		else {
			int a; //cut
			//scanf("%d", &a);
			cin >> a;
			auto it = find(v[tree[a]].begin(), v[tree[a]].end(), a);
			if (it != v[tree[a]].end()) {
				v[tree[a]].erase(it);
				dfs(a,a);
				parent[a] = a;
				tree[a] = a;
			}
		
		}
	}
	return 0;
}
