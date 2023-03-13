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


int V, E;
vector<int>edge[128];
int visit_pre[128];
int visit_in[128];
int visit_pose[128];

void pre(char x) {
	if (x == '.') return;
	cout << x;
	pre(edge[x][0]);
	pre(edge[x][1]);
}
void in(char x) {
	if (x == '.') return;
	in(edge[x][0]);
	cout << x;
	in(edge[x][1]);
}
void post(char x) {
	if (x == '.') return;
	post(edge[x][0]);
	post(edge[x][1]);
	cout << x;
}



int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int i, j;//for문변수-->가끔식 long으로
	

	//for(i=0;i<n;i++) {}
	//for(i=0;i<n;i++) { for(j=0;j<n;j++) { } }
	// from now cut into main
	//scanf("%d", &E);
	cin >> E;
	int start;//시작에 대한 선언

	for (i = 0; i < E; i++) {
		char a; cin >> a;
		for (j = 0; j < 2; j++) {
			char b; cin >> b;
			//if (b == '.') continue;
			edge[a].push_back(b);
		}
	}
	pre('A'); cout << "\n";
	in('A'); cout << "\n";
	post('A');
	return 0;
}