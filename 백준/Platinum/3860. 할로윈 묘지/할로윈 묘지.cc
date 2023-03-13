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
#define N 35
#define ll long long
#define endl "\n"
#define MID(a,b) (a+b)/2
#define INF INT_MAX
using namespace std;

ll grave[N][N];
bool visit[N][N];

vector < tuple<int, int, ll>> hole[N][N];
int dy[] = { 0,0,1,-1 };
int dx[] = { 1,-1,0,0 };
string printed[2] = { "Impossible","Never" };
vector<pair<int, int>> NegVertexes;
void resetWhile(int y, int x) {
	for (int i = 0; i < y; i++) {
		for (int j = 0; j < x; j++) {
			grave[i][j] = INF;
			visit[i][j] = 0;
			hole[i][j].clear();
		}
	}
	NegVertexes.clear();
}

bool ok(int ty, int tx, int y, int x) {
	if (ty < 0 || ty >= y || tx < 0 || tx >= x || grave[ty][tx] == -INF) return false;
	return true;
}

void BellmanFord(int y, int x, int num_rip, int num_hole) {
	int V = y * x;
	grave[0][0] = 0;
	for (int bellman = 0; bellman < V - 1; bellman++) {
		for (int itery = 0; itery < y; itery++) {
			for (int iterx = 0; iterx < x; iterx++) {
				if (itery == y - 1 && iterx == x - 1) continue;
				if (grave[itery][iterx] == INF || grave[itery][iterx] == -INF)
					continue; // Cant go
				
				if (hole[itery][iterx].size() == 1) {
					int ty = get<0>(hole[itery][iterx][0]);
					int tx = get<1>(hole[itery][iterx][0]);
					ll times = get<2>(hole[itery][iterx][0]);
					if (grave[ty][tx] > grave[itery][iterx] + times) {
						grave[ty][tx] = grave[itery][iterx] + times;
					}
				}
				else {
					for (int dir = 0; dir < 4; dir++) {
						int ty = itery + dy[dir];
						int tx = iterx + dx[dir];
						if (ok(ty, tx, y, x)) {
							if (grave[ty][tx] > grave[itery][iterx] + 1) {
								grave[ty][tx] = grave[itery][iterx] + 1;
							}
						}
					}
				}
			}
		}
	}
}

int isNegCycle(int y,int x) {
	int NegCycle = 0;
	for (int itery = 0; itery < y; itery++) {
		for (int iterx = 0; iterx < x; iterx++) {
			if (itery == y - 1 && iterx == x - 1) continue;
			if (grave[itery][iterx] == INF || grave[itery][iterx] == -INF)
				continue; // Cant go

			if (hole[itery][iterx].size() == 1) {
				int ty = get<0>(hole[itery][iterx][0]);
				int tx = get<1>(hole[itery][iterx][0]);
				ll times = get<2>(hole[itery][iterx][0]);
				if (grave[ty][tx] > grave[itery][iterx] + times) {
					grave[ty][tx] = grave[itery][iterx] + times;
					NegCycle = 1;
					NegVertexes.push_back({ ty,tx });
				}
			}
			else {
				for (int dir = 0; dir < 4; dir++) {
					int ty = itery + dy[dir];
					int tx = iterx + dx[dir];
					if (ok(ty, tx, y, x)) {
						if (grave[ty][tx] > grave[itery][iterx] + 1) {
							grave[ty][tx] = grave[itery][iterx] + 1;
							NegCycle = 1;
							NegVertexes.push_back({ ty,tx });
						}
					}
				}
			}
		}
	}
	return NegCycle;
}
void checkToEnd(int y,int x, int nowy,int nowx) {
	visit[nowy][nowx] = true;
	if (visit[y - 1][x - 1]) return;
	if (hole[nowy][nowx].size() == 1) {
		int ty = get<0>(hole[nowy][nowx][0]);
		int tx = get<1>(hole[nowy][nowx][0]);
		ll times = get<2>(hole[nowy][nowx][0]);
		if (visit[ty][tx] == false && 
			grave[ty][tx] > grave[nowy][nowx] + times) {
			checkToEnd(y, x, ty, tx);
		}
	}
	else {
		for (int dir = 0; dir < 4; dir++) {
			int ty = nowy + dy[dir];
			int tx = nowy + dx[dir];
			if (ok(ty, tx, y, x)) {
				if (visit[ty][tx] == false && 
					grave[ty][tx] > grave[nowy][nowx] + 1) {
					checkToEnd(y, x, ty, tx);
				}
			}
		}
	}
}

void Solution(int y, int x, int num_rip, int num_hole) {
	BellmanFord(y, x, num_rip, num_hole);
	int edy = y - 1, edx = x - 1;
	int ans;
	int NegCycle = isNegCycle(y, x);
	if (NegCycle) {
		//checkToEnd(y,x,);
		for (auto NegVertex : NegVertexes) {
			int ty = NegVertex.first;
			int tx = NegVertex.second;
			checkToEnd(y, x, ty, tx);
		}
		ans = 1;
		cout << printed[ans] << endl;
		//if (visit[edy][edx]) {
		//	ans = 1; // NEVER
		//	cout << printed[ans] << endl;
		//}
		//else if (grave[edy][edx] == INF) {
		//	ans = 0; // IMPOSSIBLE
		//	cout << printed[ans] << endl;
		//}
		//else {
		//	cout << grave[edy][edx] << endl;
		//}
	}
	else {
		if (grave[edy][edx] == INF) {
			ans = 0; // IMPOSSIBLE
			cout << printed[ans] << endl;
		}
		else {
			cout << grave[edy][edx] << endl;
		}
	}
}





int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j; //for문 변수 -> longlong필요한지 확인
	while (1) {
		int x, y; cin >> x >> y;
		resetWhile(y, x);
		if (x + y == 0) break;
		int num_rip; cin >> num_rip;
		for (int i = 0; i < num_rip; i++) {
			int gx, gy; cin >> gx >> gy;
			//rip.push_back({ gy,gx });
			grave[gy][gx] = -INF;
		}
		int num_hole; cin >> num_hole;
		for (int i = 0; i < num_hole; i++) {
			int inx, iny, outx, outy; ll times;
			cin >> inx >> iny >> outx >> outy >> times;
			//hole.push_back({ inx,iny,outx,outy,times });
			hole[iny][inx].push_back({ outy,outx,times });
		}
		Solution(y, x, num_rip, num_hole);
	}
	return 0;
}