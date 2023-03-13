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
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
int n;
int bamboo[505][505];
int arr[505][505];
bool ok(int tx, int ty) {
	if (tx<1 || tx>n || ty<1 || ty>n) return false;
	return true;
}
int M = -1;
int Panda(int y, int x) {
	if (bamboo[y][x] != -1) return bamboo[y][x];
	bamboo[y][x] = 0;
	int temp = 0;
	for (int i = 0; i < 4; i++) {
		int ty = y + dy[i];
		int tx = x + dx[i];
		
		if (ok(tx, ty) && arr[y][x]<arr[ty][tx]) {
			temp = max(temp, Panda(ty,tx));
		}
	}
	bamboo[y][x] = temp + 1;
	return bamboo[y][x];
	
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int i, j;//for문변수-->가끔식 long으로
	cin >> n;
	for (i = 1; i <= n; i++)
		for (j = 1; j <= n; j++) cin >> arr[i][j];
	for (i = 0; i <= n; i++)
		for (j = 0; j <= n; j++) bamboo[i][j] = -1;
	for (i = 1; i <= n; i++)
		for (j = 1; j <= n; j++) M = max(M, Panda(i, j));
	cout << M;
	//for(i=0;i<n;i++) {}
	//for(i=0;i<n;i++) { for(j=0;j<n;j++) { } }

	return 0;
}