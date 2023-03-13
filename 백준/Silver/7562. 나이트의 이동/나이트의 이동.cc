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
int arr[305][305];
int xx[] = { -2,-1,1,2,2,1,-1,-2 };
int yy[] = { -1,-2,-2,-1,1,2,2,1 };
int n;

bool ok(int y, int x) {
	if (y < 0 || y >= n || x < 0 || x >= n || arr[y][x] != 1e9) return false;
	return true;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int i, j;//for문변수-->가끔식 long으로
	int T;
	cin >> T;
	while (T--) {
		queue<int>qx, qy;
		cin >> n;
		int start_x, start_y, end_x, end_y;
		cin >> start_x >> start_y >> end_x >> end_y;
		for (i = 0; i < n; i++) for (j = 0; j < n; j++) arr[i][j] = 1e9;
		arr[start_y][start_x] = 0;
		qx.push(start_x); qy.push(start_y);
		while (!qx.empty()) {
			int nowx = qx.front(), nowy = qy.front();
			qx.pop(); qy.pop();
			if (nowx == end_x && nowy == end_y) {
				cout << arr[end_y][end_x] << "\n";
				break;
			}
			for (int k = 0; k < 8; k++) {
				int tx = nowx + xx[k], ty = nowy + yy[k];
				if (ok(ty, tx) && arr[ty][tx] > arr[nowy][nowx] + 1) {
					arr[ty][tx] = arr[nowy][nowx] + 1;
					qx.push(tx); qy.push(ty);
				}
			}
		}
		for (i = 0; i < n; i++)	for (j = 0; j < n; j++) arr[i][j] = 0;
	}

	return 0;
}