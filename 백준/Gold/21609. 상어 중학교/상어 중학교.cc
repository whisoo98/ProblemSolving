#include <iostream>

#define N 25
#define BLACK -1
#define RAINBOW 0
#define EMPTY -2
using namespace std;

typedef struct {
  int y;
  int x;
  int color;
} Block;

typedef struct {
  Block baseBlock;
  int num_blocks = 0;
  int num_rainbows = 0;
} BlockGroup;

typedef struct {
  Block arr[405];
  int front = 0;
  int rear = 0;
} Q;

// black : -1
// rainbow 0
// normal : n <= M

// BLOCK GROUP
// at least 1 normal, same color
// no black
// no limits for rainbow
// more than 2 blocks

// BASE BLOCK
// only normal block
// smallest row number & smallest column number

// AUTO PLAY
// 1. find the biggest block group s.t. has many rainbow, big row number and big
// column number
// 2. delete blocks that find 1 seq. -> gain B^2, which is the number of deleted
// blocks in block group
// 3. give gravity. -> fall down blocks
// 4. left rotate 90 degree
// 5. give gravity. -> fall down blocks
// When the gavity gave, the black blocks dont not fall, otherwise fall.

int arr[N][N];
int visit[N][N];
int dy[] = {0, 0, 1, -1};
int dx[] = {1, -1, 0, 0};

int isOk(int ty, int tx, int y, int x) {
  if (ty < 1 || tx < 1 || tx > x || ty > y || arr[ty][tx] == BLACK)
    return false;
  return true;
}

void gravity(int n) {
  for (int y = n - 1; y > 0; y--) {
    for (int x = 1; x <= n; x++) {
      int fall_y = y + 1;
      int fall_x = x;
      if (arr[fall_y][fall_x] != EMPTY || arr[y][x] == BLACK) {
        continue;
      }
      for (fall_y = y + 2; fall_y <= n; fall_y++) {
        if (arr[fall_y][fall_x] != EMPTY) {
          break;
        }
      }
      fall_y--;
      arr[fall_y][fall_x] = arr[y][x];
      arr[y][x] = EMPTY;
    }
  }
}

void leftRotate(int n) {
  int temp[N][N];
  for (int y = 1; y <= n; y++) {
    for (int x = 1; x <= n; x++) {
      int rot_x = y;
      int rot_y = n + 1 - x;
      temp[rot_y][rot_x] = arr[y][x];
    }
  }
  for (int y = 1; y <= n; y++) {
    for (int x = 1; x <= n; x++) {
      arr[y][x] = temp[y][x];
    }
  }
}

int deleteBlockGroup(int n, BlockGroup block_group) {

  int cnt = 0;
  int color = arr[block_group.baseBlock.y][block_group.baseBlock.x];
  Q q;
  q.arr[q.rear++] = block_group.baseBlock;

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      visit[i][j] = 0;
    }
  }

  visit[block_group.baseBlock.y][block_group.baseBlock.x] =
      arr[block_group.baseBlock.y][block_group.baseBlock.x];

  while (q.rear > q.front) {
    Block now = q.arr[q.front++];
    arr[now.y][now.x] = EMPTY;
    cnt++;
    for (int d = 0; d < 4; d++) {
      int ty = now.y + dy[d];
      int tx = now.x + dx[d];
      if (isOk(ty, tx, n, n) && visit[ty][tx] != color &&
          (arr[ty][tx] == color || arr[ty][tx] == RAINBOW)) {
        q.arr[q.rear++] = {ty, tx};
        visit[ty][tx] = color;
      }
    }
  }
  return cnt * cnt;
}

BlockGroup makeBlockGroup(int n, Block block) {
  int num_blocks = 0;
  int num_rainbows = 0;
  int y = block.y;
  int x = block.x;
  int color = block.color;
  Q q;
  q.arr[q.rear++] = {y, x, color};
  while (q.rear > q.front) {
    Block now = q.arr[q.front++];
    num_blocks++;
    if (now.color == RAINBOW) {
      num_rainbows++;
    }
    for (int d = 0; d < 4; d++) {
      int ty = now.y + dy[d];
      int tx = now.x + dx[d];
      if (isOk(ty, tx, n, n) && visit[ty][tx] != color &&
          (arr[ty][tx] == color || arr[ty][tx] == RAINBOW)) {
        q.arr[q.rear++] = {ty, tx, arr[ty][tx]};
        visit[ty][tx] = color;
      }
    }
  }

  return {block, num_blocks, num_rainbows};
}

BlockGroup findBlockGroup(int n) {

  BlockGroup base_group = {{0, 0, EMPTY}, -1, -1};

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      visit[i][j] = 0;
    }
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (visit[i][j] == 0 && arr[i][j] > 0) {
        visit[i][j] = arr[i][j];
        BlockGroup block_group = makeBlockGroup(n, {i, j, arr[i][j]});
        if (block_group.num_blocks > base_group.num_blocks) {
          base_group = block_group;
        } else if (block_group.num_blocks == base_group.num_blocks) {
          if (block_group.num_rainbows > base_group.num_rainbows) {
            base_group = block_group;
          } else if (block_group.num_rainbows == base_group.num_rainbows) {
            if (block_group.baseBlock.y > base_group.baseBlock.y) {
              base_group = block_group;
            } else if (block_group.baseBlock.y == base_group.baseBlock.y) {
              if (block_group.baseBlock.x > base_group.baseBlock.x) {
                base_group = block_group;
              }
            }
          }
        }
      }
    }
  }

  return base_group;
}

void debug(int n) {
  cout << "=================DEBUG START ==================" << endl;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (arr[i][j] == EMPTY) {
        cout << "E ";
      } else if (arr[i][j] == BLACK) {
        cout << "B ";
      } else if (arr[i][j] == RAINBOW) {
        cout << "R ";
      } else {

        cout << arr[i][j] << " ";
      }
    }
    cout << endl;
  }
  cout << "=================DEBUG END ==================" << endl;
}

void Solution(int n, int m) {
  int score = 0;
  while (1) {

    BlockGroup block_group = findBlockGroup(n);
    // cout << "Find Block Group" << endl;
    // debug(n);
    if (block_group.num_blocks < 2)
      break;

    score += deleteBlockGroup(n, block_group);
    // cout << "Delete Block Group " << endl;
    // debug(n);
    gravity(n);
    // cout << "Gravity" << endl;
    // debug(n);
    leftRotate(n);
    // cout << "Left Rotate" << endl;
    // debug(n);
    gravity(n);
    // cout << "Gravity" << endl;
    // debug(n);
  }
  cout << score << endl;
}

int main() {

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> arr[i][j];
    }
  }

  Solution(n, m);

  return 0;
}