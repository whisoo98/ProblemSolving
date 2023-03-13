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
#include <climits>
#include <cstring>
#include <cmath>
#include <sstream>


using namespace std;

/*struct type_name {

}srt;*/

//vector <type> vec;
//stack <type> stk;
//queue <type> q;
//string str;
//map <key_type,value_type> m;
int y, x;
char map[55][55];
int visit[55][55];
queue<pair<int, int>> water;
queue<pair<int, int>> bieber;
queue<int>vis;
bool ok(int ty, int tx) {
	if (ty < 0 || tx < 0 || ty >= y || tx >= x) return false;
	return true;
}
int yy[] = { 0,1,0,-1 };
int xx[] = { 1,0,-1,0 };
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int i, j;//for문변수-->가끔식 long으로
	scanf("%d %d", &y, &x);
	for (i = 0; i < y; i++) {
		scanf("%s", map[i]);
	}
	int destx, desty;
	//for(i=0;i<n;i++) {}
	for (i = 0; i < y; i++) {
		for (j = 0; j < x; j++) {
			if (map[i][j] == 'S') {
				bieber.push({ i,j });
				vis.push(1);
				visit[i][j] = 1;
			}
			else if (map[i][j] == '*') {
				water.push({ i,j });
				visit[i][j] = 987654321;
			}
			else if (map[i][j] == 'D') {
				//visit[i][j] = -2;
				destx = j;
				desty = i;
			}
			else if (map[i][j] == 'X') visit[i][j] = -1;
		}
	}
	while (!bieber.empty()) {
		int size = water.size();
		for (i = 0; i < size; i++) {
			int dy = water.front().first, dx = water.front().second;
			//cout <<"water "<< dy << " " << dx << " " << visit[dy][dx] << endl;
			water.pop();
			for (j = 0; j < 4; j++) {
				int temp_dy = dy + yy[j], temp_dx = dx + xx[j];
				if (ok(temp_dy, temp_dx) && map[temp_dy][temp_dx] != 'X' && visit[temp_dy][temp_dx] != 987654321 && map[temp_dy][temp_dx]!='D') {
					//if (temp_dy == desty && temp_dx == destx) continue;
					//cout << temp_dy << " " << temp_dx << endl;
					visit[temp_dy][temp_dx] = 987654321;
					water.push({ temp_dy,temp_dx });
				}
			}
		}
		size = bieber.size();
		for (i = 0; i < size; i++) {
			int dy = bieber.front().first, dx = bieber.front().second;
			int dist = vis.front();
			vis.pop();
			//cout <<"bieber "<< dy << " " << dx << " " <<visit[dy][dx]<< endl;
			bieber.pop();
			for (j = 0; j < 4; j++) {
				int temp_dy = dy + yy[j], temp_dx = dx + xx[j];
				if (ok(temp_dy, temp_dx) && visit[temp_dy][temp_dx] == 0 ) {
					visit[temp_dy][temp_dx] = dist + 1;
					vis.push(dist + 1);
					bieber.push({ temp_dy,temp_dx });
				}
			}
		}
	}
	if (visit[desty][destx] == 0) printf("KAKTUS\n");
	else printf("%d\n", visit[desty][destx] - 1);
	return 0;
}