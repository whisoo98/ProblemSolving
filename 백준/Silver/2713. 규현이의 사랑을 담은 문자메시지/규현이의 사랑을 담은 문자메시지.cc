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
#include<sstream>

using namespace std;

/*struct type_name {

}srt;*/

//vector <type> vec;
//stack <type> stk;
//queue <type> q;
//string str;
//map <key_type,value_type> m;
int arr[30];
int mat[300][300];
int r, c;
string temp;
bool ok(int ty, int tx) {
	if (mat[ty][tx] != -1 || ty < 0 || ty >= r || tx < 0 || tx >= c) return false;
	return true;
}
int cp[5000];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
void dfs() {
	int L = 0,len=temp.length();
	//cout << len << endl;
	int x = -1, y = 0, sub = 1;
	int flag = 0;
	while (L<len) {
		//cout << L;
		int C;
		if (temp[L] == ' ') {
			C = arr[0];
		}
		else {
			C = arr[temp[L] - 'A' + 1];
		}

		for (int j = 4 + L * 5; j >= 0 + L * 5; j--) {
			cp[j] = C % 2;
			C = C / 2;
		}
		L++;
	}

	/*for (int i = 0; i < 5; i++) {

		//cout << "cp" << cp << endl;
		if (ok(y, x)) {
			mat[y][x] = cp[i];
			cout << y << " " << x << endl;
			y = y + dy[flag % 4];
			x = x + dx[flag % 4];
		}
		else {
			y = y - dy[flag % 4];
			x = x - dx[flag % 4];
			flag++;
			i--;
			cout << "!";
		}
	}*/
	int cnt = 0;
	while (cnt<len*5) {
		for (int i = 0; i < c; i++) {
			x += sub;
			mat[y][x] = cp[cnt];
			cnt++;
			if (cnt >= len * 5) break;
		}
		r--;
		if (r <= 0)break;
		for (int i = 0; i < r; i++) {
			y += sub;
			mat[y][x] = cp[cnt];
			cnt++;
			if (cnt >= len * 5) break;
		}
		c--;
		if (c <= 0) break;
		sub = -sub;
	}
	
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int i, j;//for문변수-->가끔식 long으로
	int n; cin >> n;
	cin.ignore(32767, '\n');
	for (i = 1; i <= 26; i++) {
		arr[i] = i;
	}
	//;
	for (i = 0; i < n; i++) {
		//scanf("%d %d %s", &r, &c, temp);
		getline(cin, temp);
		size_t sz;
		int r1 = r = stoi(temp, &sz);
		temp = temp.substr(sz + 1);
		//cout << temp.substr(sz) << endl
		int c1 = c = stoi(temp, &sz);
		//cout<<temp.substr()
		temp = temp.substr(sz + 1);
		for (j = 0; j < r; j++) {
			for (int k = 0; k < c; k++) mat[j][k] = -1;
		}
		//cout << 1;
		dfs();
		for (j = 0; j < r1; j++) {
			for (int k = 0; k < c1; k++) {
				if (mat[j][k] == -1) cout << 0;
				else cout << mat[j][k];
			}
		}
		cout << "\n";
	}




	//for(i=0;i<n;i++) {}
	//for(i=0;i<n;i++) { for(j=0;j<n;j++) { } }

	return 0;
}