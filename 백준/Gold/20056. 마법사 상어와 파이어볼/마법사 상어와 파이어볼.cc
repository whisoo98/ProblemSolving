#include <algorithm>
#include <iostream>
#define N 55

using namespace std;

int dy[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dx[] = {0, 1, 1, 1, 0, -1, -1, -1};

typedef struct {
  int mass;
  int speed;
  int dir;
  int even;
  int odd;
} Fireball;

int n, m, K;
// int arr[N][N];
Fireball fireball[N][N][10];

void debug() {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      for (int k = 0; k < 8; k++) {
        if (fireball[i][j][k].mass) {
          int mass = fireball[i][j][k].mass;
          int speed = fireball[i][j][k].speed;
          int dir = fireball[i][j][k].dir;
          cout << i << " " << j << " " << mass << " " << speed << " " << dir
               << endl;
        }
      }
    }
  }
}

void moveFireball() {
  Fireball temp[N][N];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      for (int k = 0; k < 8; k++) {

        temp[i][j] = {0, 0, 0, 0, 0};
      }
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      for (int k = 0; k < 8; k++) {

        if (fireball[i][j][k].mass) {
          int ty = (i + dy[fireball[i][j][k].dir] * fireball[i][j][k].speed +
                    1001 * n) %
                   n;
          int tx = (j + dx[fireball[i][j][k].dir] * fireball[i][j][k].speed +
                    1001 * n) %
                   n;

          temp[ty][tx].mass += fireball[i][j][k].mass;
          temp[ty][tx].speed += fireball[i][j][k].speed;
          temp[ty][tx].dir += fireball[i][j][k].dir;
          if (fireball[i][j][k].dir % 2) {
            temp[ty][tx].odd++;
          } else {
            temp[ty][tx].even++;
          }
        }
      }
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      fireball[i][j][9] = temp[i][j];
      for (int k = 0; k < 8; k++) {
        fireball[i][j][k] = {0, 0, 0, 0, 0};
      }
    }
  }
}

void divideFireball() {
  Fireball temp[N][N];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      temp[i][j] = fireball[i][j][9];
      fireball[i][j][9] = {0, 0, 0, 0, 0};
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (temp[i][j].even + temp[i][j].odd >= 2) {
        int mass = temp[i][j].mass / 5;
        if (mass == 0) {
          continue;
        }
        int speed = temp[i][j].speed / (temp[i][j].even + temp[i][j].odd);
        if (temp[i][j].even == 0 || temp[i][j].odd == 0) { // only odd || even
          for (int dir = 0; dir < 8; dir += 2) {
            fireball[i][j][dir] = {mass, speed, dir, 1, 0};
          }
        } else {
          for (int dir = 1; dir < 8; dir += 2) {
            fireball[i][j][dir] = {mass, speed, dir, 0, 1};
          }
        }
      } else {
        fireball[i][j][temp[i][j].dir] = temp[i][j];
      }
    }
  }
}

void Solution() {
  for (int i = 0; i < K; i++) {
    moveFireball();
    divideFireball();
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      for (int k = 0; k < 8; k++) {
        ans += fireball[i][j][k].mass;
      }
    }
  }

  cout << ans << endl;
}

int main() {
  cin >> n >> m >> K;
  for (int i = 0; i < m; i++) {
    int y, x, mass, speed, dir;
    cin >> y >> x >> mass >> speed >> dir;
    fireball[--y][--x][dir] = {mass, speed, dir, !((bool)(dir % 2)), dir % 2};
  }
  // debug();
  Solution();
  return 0;
}