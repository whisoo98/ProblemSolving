#include <iostream>

#define N 55
#define endl '\n'
#define MOD
#define MAX 987654321

using namespace std;

int y, x;
int t;
int arr[N][N];
int air_cleaner_top, air_cleaner_bottom;
int dy[] = {0, 0, 1, -1};
int dx[] = {1, -1, 0, 0};

bool isOk(int ty, int tx) {
  if (ty < 1 || ty > y || tx < 1 || tx > x || arr[ty][tx] == -1)
    return false;
  return true;
}

void scatterDust() {
  int temp[N][N];
  for (int i = 1; i <= y; i++) {
    for (int j = 1; j <= x; j++) {
      temp[i][j] = 0;
    }
  }

  for (int i = 1; i <= y; i++) {
    for (int j = 1; j <= x; j++) {
      if (arr[i][j] <= 0)
        continue;

      int scattered = 0;
      for (int d = 0; d < 4; d++) {
        int ty = i + dy[d];
        int tx = j + dx[d];
        if (isOk(ty, tx)) {
          scattered++;
          temp[ty][tx] += arr[i][j] / 5;
        }
      }
      temp[i][j] += arr[i][j] - (arr[i][j] / 5) * scattered;
    }
  }

  for (int i = 1; i <= y; i++) {
    for (int j = 1; j <= x; j++) {
      arr[i][j] = temp[i][j];
    }
  }

  arr[air_cleaner_top][1] = -1;
  arr[air_cleaner_bottom][1] = -1;
}

void workAirCleaner() {
  int temp[N][N];
  for (int i = 1; i <= y; i++) {
    for (int j = 1; j <= x; j++) {
      temp[i][j] = arr[i][j];
    }
  }

  // top first
  int dir_top[4] = {0, 3, 1, 2};
  int sty = air_cleaner_top;
  int stx = 1;
  for (int dir = 0; dir < 4;) {
    int ty = sty + dy[dir_top[dir]];
    int tx = stx + dx[dir_top[dir]];
    if (isOk(ty, tx)) {
      temp[ty][tx] = arr[sty][stx];
      sty = ty;
      stx = tx;
    } else {
      dir++;
    }
  }
  arr[air_cleaner_top - 1][1] = 0;

  // bottom last
  int dir_bottom[4] = {0, 2, 1, 3};
  sty = air_cleaner_bottom;
  stx = 1;
  for (int dir = 0; dir < 4;) {
    int ty = sty + dy[dir_bottom[dir]];
    int tx = stx + dx[dir_bottom[dir]];
    if (isOk(ty, tx)) {
      temp[ty][tx] = arr[sty][stx];
      sty = ty;
      stx = tx;
    } else {
      dir++;
    }
  }
  arr[air_cleaner_bottom + 1][1] = 0;

  for (int i = 1; i <= y; i++) {
    for (int j = 1; j <= x; j++) {
      arr[i][j] = temp[i][j];
    }
  }
  arr[air_cleaner_top][1] = -1;
  arr[air_cleaner_bottom][1] = -1;

  arr[air_cleaner_top][2] = 0;
  arr[air_cleaner_bottom][2] = 0;
}

void debug() {
  cout << "==================== DEBUG START =========================" << endl;
  for (int i = 1; i <= y; i++) {
    for (int j = 1; j <= x; j++) {
      cout.width(2);
      cout << arr[i][j] << " ";
    }

    cout << endl;
  }
  cout << "==================== DEBUG END =========================" << endl;
}

void Solution() {
  for (int tt = 0; tt < t; tt++) {
    // debug();
    scatterDust();
    // debug();
    workAirCleaner();
    // debug();
  }

  int ans = 0;
  for (int i = 1; i <= y; i++) {
    for (int j = 1; j <= x; j++) {
      ans += arr[i][j];
    }
  }

  cout << ans + 2 << endl;
}

int main() {

  cin >> y >> x >> t;

  for (int i = 1; i <= y; i++) {
    for (int j = 1; j <= x; j++) {
      cin >> arr[i][j];
      if (arr[i][j] == -1) {
        if (air_cleaner_top == 0) {
          air_cleaner_top = i;
        } else {
          air_cleaner_bottom = i;
        }
      }
    }
  }

  Solution();
  return 0;
}