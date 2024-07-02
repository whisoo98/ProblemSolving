#include <algorithm>
#include <functional>
#include <iostream>
#include <queue>
#include <utility>

#define N 105
#define endl "\n"
using namespace std;

int arr[N][N];
int num_row;
int num_col;
int r, c, k;

void operationC() {
  // col를 따라서 옆으로 가면서 col에 포함된 원소를 정렬
  int new_row = -1;
  for (int j = 1; j <= num_col; j++) {
    priority_queue<pair<int, int>> pq;
    vector<int> v(105, 0);
    for (int i = 1; i <= num_row; i++) {
      // if (!arr[i][j])
      //   break;
      v[arr[i][j]]++;
    }
    for (int i = 1; i <= 100; i++) {
      arr[i][j] = 0;
      if (!v[i])
        continue;
      pq.push({-v[i], -i});
    }
    int cnt = 1;
    while (pq.size()) {
      int counts = -pq.top().first;
      int number = -pq.top().second;
      pq.pop();

      arr[cnt++][j] = number;
      arr[cnt++][j] = counts;
    }
    cnt--;
    new_row = max(new_row, cnt);
  }
  // num_row = min(max(new_row, num_row), 100);
  num_row = min(new_row, 100);
}

void operationR() {
  int new_col = -1;
  // row를 따라서 내려가면서 row에 포함된 원소를 정렬
  for (int i = 1; i <= num_row; i++) {
    priority_queue<pair<int, int>> pq;
    vector<int> v(105, 0);
    for (int j = 1; j <= num_col; j++) {
      v[arr[i][j]]++;
    }
    for (int j = 1; j <= 100; j++) {
      arr[i][j] = 0;
      if (!v[j])
        continue;
      pq.push({-v[j], -j});
    }
    int cnt = 1;
    while (pq.size()) {
      int counts = -pq.top().first;
      int number = -pq.top().second;
      pq.pop();
      arr[i][cnt++] = number;
      arr[i][cnt++] = counts;
    }
    cnt--;
    new_col = max(new_col, cnt);
  }
  // num_col = min(max(new_col, num_col), 100);
  num_col = min(new_col, 100);
}

void debug() {
  for (int i = 1; i <= num_row; i++) {
    for (int j = 1; j <= num_col; j++) {
      cout.width(2);
      cout << arr[i][j] << " ";
    }
    cout << endl;
  }
}

void Solution() {
  // debug();

  for (int t = 0; t <= 100; t++) {
    // cout << t;
    if (arr[r][c] == k) {
      cout << t << endl;
      return;
    }
    if (num_row >= num_col) {
      // cout << "R" << endl;
      operationR();
    } else {
      // cout << "C" << endl;
      operationC();
    }
    // debug();
  }
  cout << -1 << endl;
  return;
}

int main() {

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> r >> c >> k;
  for (int i = 1; i <= 3; i++) {
    for (int j = 1; j <= 3; j++) {
      cin >> arr[i][j];
    }
  }
  num_row = 3;
  num_col = 3;
  Solution();
  return 0;
}