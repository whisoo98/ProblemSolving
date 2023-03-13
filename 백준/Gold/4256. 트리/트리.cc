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

int pre[1005];
int in[1005];
stack<int> stk;
void tree(int st1, int ed1, int st2, int ed2) {
	if (st1 > ed1)return;
	int root=pre[st1];
	stk.push(root);
	if (st1 == ed1)return;
	
	int pos = find(in + st2, in + ed2 + 1, root) - (in);
	tree(ed1-(ed2-pos)+1, ed1, pos + 1, ed2);
	tree(st1 + 1, st1+(pos-st2), st2, pos-1);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int i, j;//for문변수-->가끔식 long으로
	int T; cin >> T;
	while (T--) {
		int n; cin >> n;
		for (i = 1; i <= n; i++) {
			cin >> pre[i];
		}
		for (i = 1; i <= n; i++) {
			cin >> in[i];
		}
		tree(1, n, 1, n);
		for (i = 1; i <= n; i++) {
			pre[i] = 0;
			in[i] = 0;
		}
		while (!stk.empty()) {
			cout << stk.top() << " ";
			stk.pop();
		}
		cout << "\n";
	}
	
	//for(i=0;i<n;i++) {}
	//for(i=0;i<n;i++) { for(j=0;j<n;j++) { } }

	return 0;
}