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
//int level[15];
int c, r;
vector<int>v[10005];
//bool visit[10005];
vector<int>level[10005];
int arr[10005];
int cnt;
int in[10005];
void dfs(int x,int lv) {
	level[lv].push_back(x);
	/*if (v[x].size()==1) {
		dfs(v[x][0], lv + 1);
		cnt++;
		arr[x] = cnt;
	}
	else if (v[x].size() == 2) {
		dfs(v[x][0], lv + 1);
		cnt++;
		arr[x] = cnt;
		dfs(v[x][1], lv + 1);

	}
	else {
		cnt++;
		arr[x] = cnt;
	}*/
	if (v[x][0] != -1) {
		if (v[x][1] != -1) {
			dfs(v[x][0], lv + 1);
			cnt++;
			arr[x] = cnt;
			dfs(v[x][1], lv + 1);
		}
		else {
			dfs(v[x][0], lv + 1);
			cnt++;
			arr[x] = cnt;
		}
	}
	else {
		if (v[x][1] != -1) {
			cnt++;
			arr[x] = cnt;
			dfs(v[x][1], lv + 1);

		}
		else {
			cnt++;
			arr[x] = cnt;
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int i, j;//for문변수-->가끔식 long으로
	scanf("%d", &c);
	for (i = 1; i <= c; i++) {
		int a, b, x;
		scanf("%d %d %d", &a, &b, &x);
		v[a].push_back(b);
		v[a].push_back(x);
		if (b != -1)in[b]++;
		if (x != -1)in[x]++;
	}
	for (i = 1; i <= c; i++) {
		if (!in[i]) {
			dfs(i,1);
			break;
		}
	}
	//cout << "start\n";
	//for (i = 1; i <= c; i++) cout <<i<<" "<< arr[i] << endl;
	/*for (i = 1; i < 20; i++) {
		if (!level[i].empty()) {
			cout << i;
			for (j = 0; j < level[i].size(); j++) cout << " " << level[i][j];
		}
		cout << endl;
	}*/
	pair<int, int> p;
	int max = 0;
//	p = { 1,1 };
	for (i = 1; i < 10005; i++) {
		if (!level[i].empty()) {
				int f = level[i].front(), t = level[i].back();
				if (arr[t] - arr[f] + 1 > max) {
					max = arr[t] - arr[f] + 1;
					p = { i,max };
				}
		}
	}
	printf("%d %d", p.first, p.second);
	return 0;
}