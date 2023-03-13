#include<iostream>
#include<queue>
#include<string.h>

using namespace std;
queue<pair<int, int>> q;
int N;
int ans1, ans2;
char junk;
char arr[105][105];
char arr2[105][105];
int visit[105][105];
int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };

bool is_ok(int y, int x, char C, char check_C) {
	if (y < 1 || x < 1 || y >N || x > N || visit[y][x] == 1 || C != check_C)
		return false;
	return true;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	//cin >> N;
	scanf("%d", &N);
	scanf("%c", &junk);

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			scanf("%c", &arr[i][j]);
		}
		scanf("%c", &junk);
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (arr[i][j] == 'G') {
				arr2[i][j] = 'R';
			}
			else arr2[i][j] = arr[i][j];
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (!visit[i][j]) {
				char color = arr[i][j];

				q.push({ i,j });
				visit[i][j] = 1;
				int y, x;
				while (!q.empty())
				{
					y = q.front().first;
					x = q.front().second;
					q.pop();

					for (int t = 0; t < 4; t++) {
						int ty = y + dy[t];
						int tx = x + dx[t];

						if (is_ok(ty, tx, color, arr[ty][tx])) {
							q.push({ ty,tx });
							visit[ty][tx] = 1;
						}
					}
				}
				ans1++;
			}
		}
	}

	memset(visit, 0, sizeof(visit));

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (!visit[i][j]) {
				char color = arr2[i][j];

				q.push({ i,j });
				visit[i][j] = 1;
				int y, x;
				while (!q.empty())
				{
					y = q.front().first;
					x = q.front().second;
					q.pop();

					for (int t = 0; t < 4; t++) {
						int ty = y + dy[t];
						int tx = x + dx[t];

						if (is_ok(ty, tx, color, arr2[ty][tx])) {
							q.push({ ty,tx });
							visit[ty][tx] = 1;
						}
					}
				}
				ans2++;
			}
		}
	}

	cout << ans1 << " " << ans2;
}