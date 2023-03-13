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
int y, x;
vector<char> v;
int xx[] = { 0,1,0,-1 };
int yy[] = { 1,0,-1,0 };
char arr[25][25];
int visit[25][25][4]; //visit 배열을 어덯게 써야하나
int asc[30];

bool ok(int ty, int tx) {
	if (ty < 0 || ty >= y || tx < 0 || tx >= x || asc[arr[ty][tx] - 'A']) return false;
	return true;
}
vector<int>Size;
int m;
//'다른 경로이면 간다' - 다른경로 -> 알파뱃서순
void dfs(int ty, int tx, int level) {
	//asc[arr[ty][tx] - 'A'] = 1;
	m = max(m, level);

	for (int i = 0; i < 4; i++) {
		int TX = tx + xx[i], TY = ty + yy[i];
		if (ok(TY, TX)) {
			asc[arr[TY][TX] - 'A'] = 1;
			//visit[TY][TX][i] = level;
			dfs(TY, TX, level + 1);
			asc[arr[TY][TX] - 'A'] = 0;
		}
		//	else if (ok(TY,TX)&& visit[TY][TX][i] && visit[TY][TX] )
	}
	//return m = max(m, level);
//	asc[arr[ty][tx] - 'A'] = 0;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int i, j;//for문변수-->가끔식 long으로
			 //cin >> y >> x;
	scanf("%d %d", &y, &x);
	for (i = 0; i < y; i++) scanf("%s", arr[i]);
	
	asc[arr[0][0] - 'A'] = 1;
	dfs(0, 0, 1);
	printf("%d", m);

	
	return 0;
}	
