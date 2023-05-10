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
#define N 1505
#define ll long long
#define endl "\n"
#define MID(a,b) (a+b)/2

using namespace std;


int mizu[N][N];
pair<int, int> swan[2];
int cnt = 0;
int visit[N][N];
int melted[N][N];
int dy[] = { 0,0,1,-1 };
int dx[] = { 1,-1,0,0 };
bool isOk(int ty, int tx, int y, int x) {
	if (ty<1 || ty>y || tx<1 || tx>x) return false;
	return true;
}
void floodfill(int y,int x) {
	queue<int> qy;
	queue<int> qx;
	/*for (int i = 0; i < 4; i++) {
		int ty = swan[0].first + dy[i];
		int tx = swan[0].second + dx[i];
		if (isOk(ty, tx, y, x) && mizu[ty][tx] == '.' && visit[ty][tx] != 1) {
			visit[ty][tx] = 1;
			mizu[ty][tx] = '1';
			qy.push(ty);
			qx.push(tx);
		}
	}*/
	qy.push(swan[0].first);
	qx.push(swan[0].second);
	visit[swan[0].first][swan[0].second] = 1;
	while (qy.size()) {
		int nowy = qy.front();
		int nowx = qx.front();
		qy.pop(); qx.pop();
		for (int d = 0; d < 4; d++) {
			int ty = nowy + dy[d];
			int tx = nowx + dx[d];
			if (isOk(ty, tx, y, x) && mizu[ty][tx] == '.' && visit[ty][tx]!=1) {
				visit[ty][tx] = 1;
				mizu[ty][tx] = '1';
				qy.push(ty);
				qx.push(tx);
			}
		}
	}

	/*for (int i = 0; i < 4; i++) {
		int ty = swan[1].first + dy[i];
		int tx = swan[1].second + dx[i];
		if (isOk(ty, tx, y, x) && mizu[ty][tx] == '.' && visit[ty][tx] != 2) {
			visit[ty][tx] = 2;
			mizu[ty][tx] = '2';
			qy.push(ty);
			qx.push(tx);
		}
	}*/
	qy.push(swan[1].first);
	qx.push(swan[1].second);
	visit[swan[1].first][swan[1].second] = 2;
	while (qy.size()) {
		int nowy = qy.front();
		int nowx = qx.front();
		qy.pop(); qx.pop();
		for (int d = 0; d < 4; d++) {
			int ty = nowy + dy[d];
			int tx = nowx + dx[d];
			if (isOk(ty, tx, y, x) && mizu[ty][tx] == '.' && visit[ty][tx]!=2) {
				visit[ty][tx] = 2;
				mizu[ty][tx] = '2';
				qy.push(ty);
				qx.push(tx);
			}
		}
	}
}
int isFistConnect(int y, int x) {
	int connect = 0;
	//queue<int> qy;
	//queue<int> qx;
	
	for (int i = 1; i <= y; i++) {
		for (int j = 1; j <= x; j++) {

			if ((mizu[i][j] == '1' || mizu[i][j] == '2')) {
				int flag = mizu[i][j];
				for (int d = 0; d < 4; d++) {
					int ty = i + dy[d];
					int tx = j + dx[d];
					if (isOk(ty, tx, y, x)) {
						if ((mizu[ty][tx] == '1' && flag == '2') ||
							(mizu[ty][tx] == '2' && flag == '1')) {
							connect = 1;
							//cout << "IN" << endl;
							goto ret;
						}
						else if (mizu[ty][tx] == 'X') {
							
							melted[ty][tx] = flag;
						}

					}
				}
			}
			else if (mizu[i][j] == '.') {
				for (int d = 0; d < 4; d++) {
					int ty = i + dy[d];
					int tx = j + dx[d];
					if (isOk(ty, tx, y, x) && mizu[ty][tx] == 'X') {
						melted[ty][tx] = '.';
						//cout << i << " " << j << endl;
					}
				}
			}
		}
	}
	return connect;
ret:
	return connect;
}

queue<pair<int, int>>  iceMelt(int y, int x) {
	queue<pair<int, int>> q;
	for (int i = 1; i <= y; i++) {
		for (int j = 1; j <= x; j++) {
			if (melted[i][j]) {
				q.push({ i,j });
				mizu[i][j] = melted[i][j];
				melted[i][j] = 0;
				//cout << i << " " << j << endl;
			}
		}
	}
	return q;
}
int isConnect(int y, int x, queue<pair<int, int>>& q) {
	int connect = 0;
	queue<tuple<int, int, int>> meltq;
	while (q.size()) {
		int i = q.front().first;
		int j = q.front().second;
		q.pop();
		int flag = mizu[i][j];
		for (int d = 0; d < 4; d++) {
			int ty = i + dy[d];
			int tx = j + dx[d];
			if (isOk(ty, tx, y, x)) {
				if ((mizu[ty][tx] == '1' && flag == '2') ||
					(mizu[ty][tx] == '2' && flag == '1')) {
					connect = 1;
					//cout << "IN" << endl;
					goto ret;
				}
				else if (mizu[ty][tx] == 'X' && (melted[ty][tx] != '1' && melted[ty][tx] != '2')) {
					melted[ty][tx] = flag;
				}
				else if ((flag == '1' || flag =='2') && mizu[ty][tx] == '.') {
					mizu[ty][tx] = flag;
					q.push({ ty,tx });
				}
			}
		}
	}


	return connect;
ret:
	return connect;
}
void Solution(int y, int x) {
	int connect = 0;
	int day = 0;
	floodfill(y, x);
	/*cout << endl;
	for (int i = 1; i <= y; i++) {
		for (int j = 1; j <= x; j++) {
			cout << (char)mizu[i][j];
		}
		cout << endl;
	}*/
	//memset(visit, 0, sizeof(visit));
	connect = isFistConnect(y, x);
	while (!connect) {
		day++;

		queue<pair<int, int>> q=  iceMelt(y, x);
		q.push(swan[0]);
		q.push(swan[1]);
		connect= isConnect(y, x, q);
		//memset(melted, 0, sizeof(melted));
	}
	
	cout << day << endl;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j; //for문 변수 -> longlong필요한지 확인
	int y, x; cin >> y >> x;
	for (int i = 1; i <= y; i++) {
		string s; cin >> s;
		for (int j = 0; j < x; j++) {
			mizu[i][j + 1] = s[j];
			if (s[j] == 'L') {
				swan[cnt++] = { i,j+1 };
			}
		}
	}
	mizu[swan[0].first][swan[0].second] = '1';
	mizu[swan[1].first][swan[1].second] = '2';
	Solution(y, x);
	return 0;
}