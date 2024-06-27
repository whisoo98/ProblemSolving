#include <iostream>

#define N 505

using namespace std;

int arr[N][N];
int dy[] = {0, 1, 0, -1};
int dx[] = {-1, 0, 1, 0};
int scatter[4][5][5] = {{
    {0, 0, 2, 0, 0},
    {0, 10, 7, 1, 0},
    {5, 0, 0, 0, 0},
    {0, 10, 7, 1, 0},
    {0, 0, 2, 0, 0},
}};
int n;

void setScatterArr() {
  for (int dir = 1; dir < 4; dir++) {
    for (int i = 0; i < 5; i++) {
      for (int j = 0; j < 5; j++) {
        int ty = 5 - j - 1;
        int tx = i;
        scatter[dir][ty][tx] = scatter[dir - 1][i][j];
      }
    }
  }
}

void moveTornado() {
  int cnt = n * n - 1;
  int nowy = n / 2 + 2;
  int nowx = n / 2 + 2;
  int dir = 0;
  for (int chk = 0, steps = 0; chk < cnt; chk += steps, dir++) {
    steps += ((dir + 1) % 2);
    if (chk + steps >= cnt) {
      steps--;
    }
    dir %= 4;
    // cout << "chk     steps" << endl;
    // cout << chk << " " << steps << endl;

    for (int step = 0; step < steps; step++) {

      nowy += dy[dir];
      nowx += dx[dir];

      // cout << "nowy     nowx" << endl;
      // cout << nowy << " " << nowx << endl;
      if (arr[nowy][nowx]) {
        int sand = arr[nowy][nowx];

        for (int i = 0; i < 5; i++) {
          for (int j = 0; j < 5; j++) {
            int ty = nowy + (i - 2);
            int tx = nowx + (j - 2);
            int scattered_sand = scatter[dir][i][j] * sand / 100;
            arr[ty][tx] += scattered_sand;
            arr[nowy][nowx] -= scattered_sand;
          }
        }

        arr[nowy + dy[dir]][nowx + dx[dir]] += arr[nowy][nowx];
        arr[nowy][nowx] = 0;
      }
    }
  }
}

int calcSand() {
  int ans = 0;
  for (int i = 0; i <= n + 3; i++) {
    for (int j = 0; j <= n + 3; j++) {
      ans += arr[i][j];
    }
  }
  for (int i = 2; i <= n + 1; i++) {
    for (int j = 2; j <= n + 1; j++) {
      ans -= arr[i][j];
    }
  }
  return ans;
}

void Solution() {
  setScatterArr();
  moveTornado();
  int ans = calcSand();
  cout << ans << endl;
}

int main() {
  cin >> n;

  for (int i = 2; i <= n + 1; i++) {
    for (int j = 2; j <= n + 1; j++) {
      cin >> arr[i][j];
    }
  }

  Solution();
  return 0;
}