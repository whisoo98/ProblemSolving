#include <iostream>
#include <algorithm>
#include <functional>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <string>
#include <queue>
#include <stack>
#include <map>
#include <vector>
#include <set>
#include <sstream>
#include <ctime>
#include <climits>
#include <tuple>
#define N 15
#define ll long long
#define endl "\n"
#define MID(a,b) (a+b)/2

using namespace std;

int Out = -1;

class Hole {
public:
	int y;
	int x;
};

class Bid {
public:
	int color;
	int y;
	int x;
};

Bid red;
Bid blue;
Hole hole;

int dy[] = { -1,1,0,0 };
int dx[] = { 0,0 ,-1,1 };
int ans = 987654321;

bool isOk(int ty, int tx, int y, int x, vector<string>& board) {
	if (ty < 0 || ty >= y || tx < 0 || tx >= x ||
		board[ty][tx] == '#' || board[ty][tx] == 'B' || board[ty][tx] == 'R') return false;
	return true;
}

int moveBid(Bid* bid, int dir, int y,int x, vector<string>& board) {
	int oy = bid->y;
	int ox = bid->x;
	int ty = bid->y + dy[dir];
	int tx = bid->x + dx[dir];
	int move = 0; // not movded

	if (isOk(ty, tx, y, x, board)) { // moved
		if (board[ty][tx] == 'O') { // POP
			move = -1;
			board[oy][ox] = '.';
		}
		else {
			bid->y = ty;
			bid->x = tx;
			board[ty][tx] = bid->color;
			board[oy][ox] = '.';
			move = 1;
		}
	}
	return move;
}

void moveStates(Bid* src_red, Bid* dst_red, 
	Bid* src_blue, Bid* dst_blue, vector<string>& src_board, vector<string>& dst_board) {
	
	dst_red->color = src_red->color;
	dst_red->x = src_red->x;
	dst_red->y = src_red->y;

	dst_blue->color = src_blue->color;
	dst_blue->x = src_blue->x;
	dst_blue->y = src_blue->y;

	int y = src_board.size();
	int x = src_board[0].size();
	for (int i = 0; i < y; i++) {
		string temp = "";
		for (int j = 0; j < x; j++) {
			temp += src_board[i][j];
		}
		dst_board[i] = temp;
	}
}

void popRedBid(int y, int x, vector<string>& board, int lv) {
	if (lv >= 10) return;
	Bid t_red;
	Bid t_blue;
	vector<string> t_board(y);
	/*cout << "---------------------------------------------" << endl;
	cout << "before lv : " << lv << endl;
	for (int i= 0; i < y; i++) {
		cout << board[i] << endl;
	}
	cout << "---------------------------------------------" << endl;*/

	moveStates(&red, &t_red, &blue, &t_blue, board, t_board);
	for (int dir = 0; dir < 4; dir++) {
		int red_move = 0;
		int blue_move = 0;
		int out_red = 0;
		int out_blue = 0;
		int reset = 0;
		while (true) {
			int add_move = moveBid(&red, dir, y, x, board);
			if (add_move == -1) {
				out_red = 1;
				break;
			}
			if (add_move == 0) {
				break;
			}
			else {
				red_move += add_move;
			}
		}
		while (true) {
			int add_move = moveBid(&blue, dir, y, x, board);

			if (add_move == -1) {
				out_blue = 1;
				break;
			}
			if (add_move == 0) {
				break;
			}
			else {
				blue_move += add_move;
			}
		}
		while (true) {
			int add_move = moveBid(&red, dir, y, x, board);

			if (add_move == -1) {
				out_red = 1;
				break;
			}
			if (add_move == 0) {
				break;
			}
			else {
				red_move += add_move;
			}
		}
		while (true) {
			int add_move = moveBid(&blue, dir, y, x, board);

			if (add_move == -1) {
				out_blue = 1;
				break;
			}
			if (add_move == 0) {
				break;
			}
			else {
				blue_move += add_move;
			}
		}
		if (out_blue) { // QUIT
			reset = 1;
		}
		else {
			if (out_red) {
				ans = min(ans, lv + 1);
				Out = ans;
				return;
			}
			else {
				if (red_move == 0 && blue_move == 0) {
					reset = 1;
				}
				else {
					popRedBid(y, x, board, lv + 1);
					reset = 1;
				}
			}
		}
		if(reset)
			moveStates(&t_red, &red, &t_blue, &blue, t_board, board);
		/*cout << "---------------------------------------------" << endl;
		cout << "after lv : " << lv << endl;
		for (int i = 0; i < y; i++) {
			cout << board[i] << endl;
		}
		cout << "---------------------------------------------" << endl;*/
	}
}

void Solution(int y, int x, vector<string>& board) {
	popRedBid(y, x, board, 0);

	cout << Out << endl;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j; //for문 변수 -> longlong필요한지 확인
	int y, x; cin >> y >> x;
	vector<string> board;
	for (int i = 0; i < y; i++) {
		string s; cin >> s;
		board.push_back(s);
		for (int j = 0; j < x; j++) {
			if (s[j] == 'R') {
				red.color = 'R';
				red.y = i;
				red.x = j;
			}
			if (s[j] == 'B') {
				blue.color = 'B';
				blue.y = i;
				blue.x = j;
			}
			if (s[j] == 'O') {
				hole.y = i;
				hole.x = j;
			}
		}
	}
	Solution(y, x, board);
	return 0;
}