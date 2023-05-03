#include <iostream>
#include <algorithm>
#include <functional>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <string>
#include <queue>
#include <stack>
#include <map>
#include <vector>
#include <set>
#include <sstream>
#include <ctime>
#include <climits>
#include <tuple>
#define N 105
#define ll long long
#define endl "\n"
#define MID(a,b) (a+b)/2

using namespace std;

int board[N][N];
int visit[N][N];
int dy[] = { 0,0,1,-1 };
int dx[] = { 1,-1,0,0 };
int parent[10];
int y, x; 
int land;
vector<tuple<int, int, int>> bridge_cand;


int Find(int x) {
	if (x == parent[x]) return x;
	return parent[x] = Find(parent[x]);
}

int Union(int x, int y) {
	x = Find(x);
	y = Find(y);
	if (x != y) {
		parent[y] = x;
		return 1;
	}
	return 0;
}

bool isOk(int ty, int tx) {
	if (ty<1 || ty>y || tx<1 || tx>x || !board[ty][tx]) return false;
	return true;
}

void flood_fill() {
	int cnt = 1;
	for (int i = 1; i <= y; i++) {
		for (int j = 1; j <= x; j++) {
			if (board[i][j] && !visit[i][j]) {
				queue<int> qy;
				queue<int> qx;
				qy.push(i);
				qx.push(j);
				visit[i][j] = 1;
				while (qy.size()) {
					int nowy = qy.front(); qy.pop();
					int nowx = qx.front(); qx.pop();
					board[nowy][nowx] = cnt;
					for (int k = 0; k < 4; k++) {
						int ty = nowy + dy[k];
						int tx = nowx + dx[k];
						if (isOk(ty, tx) && !visit[ty][tx]) {
							qy.push(ty);
							qx.push(tx);
							visit[ty][tx] = 1;
						}
					}
				}
				cnt++;
			}
		}
	}
	land = cnt-1;
	for (int i = 1; i < cnt; i++) {
		parent[i] = i;
	}
}

void search_vert() {
	for (int j = 1; j <= x; j++) {
		int flag = 0;
		int distance = 0;
		int lands = 0;
		for (int i = 1; i <= y; i++) {
			if (board[i][j] == 0) {
				if (flag == 0) {
					continue;
				}
				else {
					distance++;
				}
			}
			else if (flag != board[i][j]) {
				lands++;
				if (flag == 0) {
					flag = board[i][j];
				}
				else {
					if (distance > 1) {
						bridge_cand.push_back({ distance,flag,board[i][j] });
					}
					distance = 0;
					flag = board[i][j];
				}
			}
			else {
				if (distance > 0) {
					distance = 0;
				}
			}
		}
	}
}

void search_hori() {
	for (int i = 1; i <= y; i++) {
		int flag = 0;
		int distance = 0;
		int lands = 0;
		for (int j = 1; j <= x; j++) {
			if (board[i][j] == 0) {
				if (flag == 0) {
					continue;
				}
				else {
					distance++;
				}
			}
			else if (flag != board[i][j]) {
				lands++;
				if (flag == 0) {
					flag = board[i][j];
				}
				else {
					if (distance > 1) {
						bridge_cand.push_back({ distance,flag,board[i][j] });
					}
					distance = 0;
					flag = board[i][j];
				}
			}
			else {
				if (distance > 0) {
					distance = 0;
				}
			}
		}
	}
}

void Solution() {
	flood_fill();
	search_vert();
	search_hori();
	int ans = 0;
	sort(bridge_cand.begin(), bridge_cand.end());
	for (auto it : bridge_cand) {
		int cost = get<0>(it);
		int a = get<1>(it);
		int b = get<2>(it);
		//cout << cost << " " << a << " " << b << endl;
		if (Union(a, b)) {
			ans += cost;
		}
	}
	int basis = Find(1);
	for (int i = 2; i <= land; i++) {
		if (Find(i) != basis) {
			ans = -1;
			break;
		}
	}
	cout << ans << endl;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j; //for문 변수 -> longlong필요한지 확인
	cin >> y >> x;
	for (int i = 1; i <= y; i++) {
		for (int j = 1; j <= x; j++) {
			cin >> board[i][j];
		}
	}
	Solution();
	return 0;
}