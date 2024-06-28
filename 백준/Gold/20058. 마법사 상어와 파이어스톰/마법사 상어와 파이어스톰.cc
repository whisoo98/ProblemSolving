#include <iostream>

#define N 80
#define MAX(a, b) (a > b ? a : b)

using namespace std;

int n, Q;
int arr[N][N];
int temp[N][N];
int visit[N][N];

int dy[] = {0, 0, 1, -1};
int dx[] = {1, -1, 0, 0};

void debug() {
  cout << "================== DEBUG START ===================" << endl;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cout << arr[i][j] << " ";
    }
    cout << endl;
  }
  cout << "================== DEBUG END ===================" << endl;
}

void rightRotate(int y, int x, int width) {

  for (int i = 0; i < 0 + width; i++) {
    for (int j = 0; j < 0 + width; j++) {
      //   for (int i = y; i < y + width; i++) {
      // for (int j = x; j < x + width; j++) {
      int ty = y + j;
      int tx = x - 1 + width - i;
      temp[ty][tx] = arr[y + i][x + j];
    }
  }

  // for (int i = y; i < y + width; i++) {
  //   for (int j = x; j < x + width; j++) {
  //     arr[i][j] = temp[i][j];
  //   }
  // }
}

void firestorm(int L) {
  int width = 1 << L;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      temp[i][j] = 0;
    }
  }

  for (int i = 1; i <= n; i += width) {
    for (int j = 1; j <= n; j += width) {
      rightRotate(i, j, width);
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      arr[i][j] = temp[i][j];
    }
  }
  // debug();

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (!arr[i][j]) {
        continue;
      }
      int cnt = 0;
      for (int dir = 0; dir < 4; dir++) {
        int ty = i + dy[dir];
        int tx = j + dx[dir];
        if (arr[ty][tx])
          cnt++;
      }
      if (cnt < 3) {
        temp[i][j]--;
      }
    }
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      arr[i][j] = temp[i][j];
    }
  }
}

int calcSum() {
  int ret = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      ret += arr[i][j];
    }
  }
  return ret;
}

int dfs(int y, int x) {
  visit[y][x] = 1;
  int ret = 1;
  for (int dir = 0; dir < 4; dir++) {
    int ty = y + dy[dir];
    int tx = x + dx[dir];
    if (arr[ty][tx] && visit[ty][tx] == 0) {
      ret += dfs(ty, tx);
    }
  }
  return ret;
}

int calcMax() {
  int M = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (arr[i][j] && visit[i][j] == 0) {
        int ret = dfs(i, j);
        // cout << M << " " << ret << endl;
        M = MAX(M, ret);
      }
    }
  }
  return M;
}

void Solution() {
  // debug();
  for (int i = 1; i <= Q; i++) {
    int L;
    cin >> L;
    firestorm(L);
    // debug();
  }
  int ice_sum = calcSum();
  int big_ice = calcMax();

  cout << ice_sum << endl;
  cout << big_ice << endl;
}

int main() {
  cin >> n >> Q;
  n = 1 << n;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {

      cin >> arr[i][j];
    }
  }

  Solution();
  return 0;
}
