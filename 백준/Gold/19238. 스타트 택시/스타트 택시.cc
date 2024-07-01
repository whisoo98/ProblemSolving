#include <iostream>
#include <queue>

#define N 25
#define MAX(a, b) (a > b ? a : b)
#define MIN(a, b) (a > b ? b : a)
#define ABS(a) (a > 0 ? a : -a)
#define INF 987654321
#define endl "\n"

using namespace std;

typedef struct {
  int y;
  int x;
} Pos;

typedef struct {
  Pos dept;
  Pos arrival;
  int is_arrived;
} Passenger;

typedef struct {
  Pos location;
  int fuel;
  int passenger;
} Taxi;

int n, num_passengers, fuels;
Taxi taxi;
Passenger passengers[N * N];

int arr[N][N];
int visit[N][N];
int dy[] = {-1, 0, 0, 1};
int dx[] = {0, -1, 1, 0};

int isOk(int ty, int tx) {
  if (ty < 1 || ty > n || tx < 1 || tx > n || arr[ty][tx] == 1)
    return false;
  return true;
}

int goToClosestPassenger() {
  int min_path = INF;
  for (int j = 1; j <= n; j++) {
    for (int k = 1; k <= n; k++) {
      visit[j][k] = INF;
    }
  }

  // int targety = passengers[i].dept.y;
  // int targetx = passengers[i].dept.x;

  queue<int> qy, qx;
  qy.push(taxi.location.y);
  qx.push(taxi.location.x);
  visit[taxi.location.y][taxi.location.x] = 0;
  while (qy.size()) {
    int nowy = qy.front();
    int nowx = qx.front();
    qy.pop();
    qx.pop();
    if (visit[nowy][nowx] > min_path)
      continue;
    if (arr[nowy][nowx] < 0) {
      int target = -arr[nowy][nowx];
      int targety = passengers[target].dept.y;
      int targetx = passengers[target].dept.x;
      if (min_path > visit[targety][targetx]) {
        taxi.passenger = target;
        min_path = visit[targety][targetx];
      } else if (min_path == visit[targety][targetx]) {
        int passenger = taxi.passenger;
        if (passengers[passenger].dept.y > passengers[target].dept.y) {
          taxi.passenger = target;
        } else if (passengers[passenger].dept.y == passengers[target].dept.y) {
          if (passengers[passenger].dept.x > passengers[target].dept.x) {
            taxi.passenger = target;
          }
        }
      }
      continue;
    }
    //     if (visit[nowy][nowx] > min_path)
    //       continue;
    //
    //     if (nowy == targety && nowx == targetx) {
    //       if (min_path > visit[nowy][nowx]) {
    //         taxi.passenger = i;
    //         min_path = visit[nowy][nowx];
    //       } else if (min_path == visit[nowy][nowx]) {
    //         int passenger = taxi.passenger;
    //         if (passengers[passenger].dept.y > passengers[i].dept.y) {
    //           taxi.passenger = i;
    //         } else if (passengers[passenger].dept.y == passengers[i].dept.y)
    //         {
    //           if (passengers[passenger].dept.x > passengers[i].dept.x) {
    //             taxi.passenger = i;
    //           }
    //         }
    //       }
    //       break;
    //     }

    for (int dir = 0; dir < 4; dir++) {
      int ty = nowy + dy[dir];
      int tx = nowx + dx[dir];
      if (isOk(ty, tx) && visit[ty][tx] > visit[nowy][nowx] + 1) {
        visit[ty][tx] = visit[nowy][nowx] + 1;
        qy.push(ty);
        qx.push(tx);
      }
    }
  }

  // for (int i = 1; i <= num_passengers; i++) {
  //   if (passengers[i].is_arrived)
  //     continue;
  //   int targety = passengers[i].dept.y;
  //   int targetx = passengers[i].dept.x;
  //   if (min_path > visit[targety][targetx]) {
  //     taxi.passenger = i;
  //     min_path = visit[targety][targetx];
  //   } else if (min_path == visit[targety][targetx]) {
  //     int passenger = taxi.passenger;
  //     if (passengers[passenger].dept.y > passengers[i].dept.y) {
  //       taxi.passenger = i;
  //     } else if (passengers[passenger].dept.y == passengers[i].dept.y) {
  //       if (passengers[passenger].dept.x > passengers[i].dept.x) {
  //         taxi.passenger = i;
  //       }
  //     }
  //   }
  // }

  taxi.location = passengers[taxi.passenger].dept;
  if (taxi.passenger == 0) {
    min_path = INF;
  }
  // cout << "passenger : " << taxi.passenger << endl;
  return min_path;
}

int goToArrival() {
  if (taxi.passenger == 0) {
    return INF;
  }
  for (int j = 1; j <= n; j++) {
    for (int k = 1; k <= n; k++) {
      visit[j][k] = INF;
    }
  }
  int targety = passengers[taxi.passenger].arrival.y;
  int targetx = passengers[taxi.passenger].arrival.x;

  queue<int> qy, qx;
  qy.push(taxi.location.y);
  qx.push(taxi.location.x);
  visit[taxi.location.y][taxi.location.x] = 0;
  while (qy.size()) {
    int nowy = qy.front();
    int nowx = qx.front();
    qy.pop();
    qx.pop();
    if (nowy == targety && nowx == targetx) {
      passengers[taxi.passenger].is_arrived = 1;
      break;
    }

    for (int dir = 0; dir < 4; dir++) {
      int ty = nowy + dy[dir];
      int tx = nowx + dx[dir];
      if (isOk(ty, tx) && visit[ty][tx] > visit[nowy][nowx] + 1) {
        visit[ty][tx] = visit[nowy][nowx] + 1;
        qy.push(ty);
        qx.push(tx);
      }
    }
  }

  if (passengers[taxi.passenger].is_arrived == 0) {
    return INF;
  }
  arr[taxi.location.y][taxi.location.x] = 0;
  taxi.location = passengers[taxi.passenger].arrival;
  taxi.passenger = 0;
  return visit[targety][targetx];
}

void Solution() {
  for (int i = 1; i <= num_passengers; i++) {
    int used_fuel = goToClosestPassenger();
    taxi.fuel -= used_fuel;
    // cout << used_fuel << endl;
    if (taxi.fuel < 0) {
      cout << -1 << endl;
      return;
    }

    used_fuel = goToArrival();
    // cout << used_fuel << endl;

    taxi.fuel -= used_fuel;

    if (taxi.fuel < 0) {
      cout << -1 << endl;
      return;
    }
    taxi.fuel += used_fuel * 2;
  }
  cout << taxi.fuel << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> num_passengers >> fuels;
  taxi.fuel = fuels;
  taxi.passenger = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> arr[i][j];
    }
  }

  cin >> taxi.location.y >> taxi.location.x;
  passengers[0].dept = {0, 0};
  passengers[0].arrival = {0, 0};
  passengers[0].is_arrived = 0;

  for (int i = 1; i <= num_passengers; i++) {
    cin >> passengers[i].dept.y >> passengers[i].dept.x >>
        passengers[i].arrival.y >> passengers[i].arrival.x;
    passengers[i].is_arrived = 0;
    arr[passengers[i].dept.y][passengers[i].dept.x] = -i;
  }
  Solution();
}