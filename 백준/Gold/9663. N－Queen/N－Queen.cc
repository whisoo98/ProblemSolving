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
int n;
int visit[20][20];
bool ok(int y, int x) {
	if (visit[y][x]) return false;
	return true;
}
int cnt;
void dfs(int y, int x) {
	if (ok(y, x)) {
		if (y == n) {
			cnt++;
			return;
			/*for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= n; j++) {
					cout << visit[i][j];
				}
				cout << endl;
			}*/
		}
		else {
			for (int i = y+1; i <= n; i++) {
				//if (visit[i][x]) continue;
				visit[i][x]++;
			}
			int hap = y + x, cha = (x - y);
			for (int i = 1; i <= n; i++) {
				if ((hap - i) <= n && hap - i > 0) {
					//if (visit[i][hap - i]) continue;
					visit[i][hap - i]++;
				}
			}
			for (int i = 1; i <= n; i++) {
				if (i + cha > 0 && i + cha <= n) {
					//if (visit[i][i + cha]) continue;
					visit[i][i + cha]++;
				}
			}
			for (int i = 1; i <= n; i++) {
				dfs(y + 1, i);
			}
		}
		int hap = y + x, cha = (x - y);
		for (int i = y+1; i <= n; i++) {
			visit[i][x]--;
		}
		for (int i = 1; i <= n; i++) {
			if ((hap - i) <= n && hap - i > 0) {
				visit[i][hap - i]--;
			}
		}
		for (int i = 1; i <= n; i++) {
			if (i + cha > 0 && i+cha<=n) {
				visit[i][i + cha]--;
			}
		}
		return;
	}
	else return;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int i, j;//for문변수-->가끔식 long으로
	cin >> n;
	for (i = 1; i <= n; i++) {
		dfs(1, i);
	}
	cout << cnt;




	return 0;
}