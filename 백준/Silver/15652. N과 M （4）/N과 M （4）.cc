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
int n, m;
int arr[10];
void dfs(int x, int level){
	if (level == m ) {
		for (int i = 1; i <= m; i++) {
			cout << arr[i] << " ";
		}
		cout << "\n";

		return;
	}
	for (int i = x; i <= n; i++) {
		arr[level + 1] = i;
		dfs(i, level + 1);
		//		cout << "\n";

	}
	//dfs(x + 1, level);

}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int i, j;//for문변수-->가끔식 long으로
	cin >> n >> m;
	//for (i = 1; i <= n; i++) dfs(i, 1);
	for (i = 1; i <= n; i++) {
		arr[1] = i;
		dfs(i, 1);
	}
	
	return 0;
}