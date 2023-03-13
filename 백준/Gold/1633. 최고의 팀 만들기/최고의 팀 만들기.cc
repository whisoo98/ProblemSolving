#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <iostream>

using namespace std;

int w[1001], b[1001], cnt, dp[16][16][1001], m;

int dfs(int x, int y, int now)
{
   //dp[x][y][now] = d;
   if (dp[x][y][now]) return dp[x][y][now];

   if (now == cnt + 1)
      return 0;
   else
   {
      if (x < 15)
      {
         dp[x][y][now] = max(dp[x][y][now], dfs(x + 1, y, now + 1) + w[now]);
      }
      if (y < 15)
      {
         dp[x][y][now] = max(dp[x][y][now], dfs(x, y + 1, now + 1) + b[now]);
      }
      dp[x][y][now] = max(dp[x][y][now], dfs(x, y, now + 1));
   }
   return dp[x][y][now];
}

int main()
{
   int idx = 1;
   while (scanf("%d%d", w + idx, b + idx) != EOF) 
   { 
      idx++;
      cnt++;
   }
   printf("%d", dfs(0, 0, 1));
}