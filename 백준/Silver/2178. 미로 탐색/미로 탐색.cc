#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;


int arr[101][101];
int visit[101][101];
int N, M;

void bfs(int x,int y) {
   queue<pair<int,int>> q;

   q.push(make_pair(x, y));
   visit[x][y] = 1;
   while (!q.empty()) {
      int x = q.front().first;
      int y = q.front().second;
      q.pop();
         if (x + 1 >= 0 && x + 1 <= N && visit[x + 1][y] == -1 && arr[x+1][y] == 1) {
            visit[x + 1][y] = visit[x][y] + 1;
            q.push(make_pair(x + 1, y));
         }
         if (y+1 >= 0 && y+1 <= M && visit[x][y + 1] == -1 && arr[x][y+1] == 1) {
            visit[x][y + 1] = visit[x][y] + 1;
            q.push(make_pair(x, y+1));
         }

         if (x-1 >= 0 && x-1 <=N && visit[x - 1][y] == -1 && arr[x-1][y] == 1) {
            visit[x - 1][y] = visit[x][y] + 1;
            q.push(make_pair(x - 1, y));
         }

         if (y-1 >= 0 && y-1 <= M &&visit[x][y - 1] == -1&& arr[x][y-1] == 1)  {
            visit[x][y - 1] = visit[x][y] + 1;
            q.push(make_pair(x , y-1));
         }

   }
}

int main(void) {
   cin >> N >> M;
   //memset(visit, -1, 101 * 101);
   for (int i = 0; i < N; i++) {
      for (int j = 0; j < M; j++) {
         scanf("%1d", &arr[i][j]);
          visit[i][j]=-1;
      }
   }

   bfs(0, 0);



   cout << visit[N - 1][M - 1];
}