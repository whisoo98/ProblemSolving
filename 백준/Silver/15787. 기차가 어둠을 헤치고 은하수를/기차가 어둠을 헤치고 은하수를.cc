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
#define N 25
#define NN 100'005
#define ll long long
#define endl "\n"
#define MID(a,b) (a+b)/2

using namespace std;

int train[NN][N];
vector <vector<int>> galaxy;


void processQuery(int num_query) {
	for (int i = 0; i < num_query; i++) {
		int cmd; cin >> cmd;
		if (cmd == 1) {
			int train_num, seat_num;
			cin >> train_num >> seat_num;
			train[train_num][seat_num] = 1;
		}
		else if (cmd == 2) {
			int train_num, seat_num;
			cin >> train_num >> seat_num;
			train[train_num][seat_num] = 0;
		}
		else if (cmd == 3) {
			int train_num;
			cin >> train_num;
			for (int i = 20; i >= 1; i--) {
				train[train_num][i + 1] = train[train_num][i];
			}
			train[train_num][1] = 0;

			train[train_num][0] = 0;
			train[train_num][21] = 0;
		}
		else if (cmd == 4) {
			int train_num;
			cin >> train_num;
			for (int i = 1; i <= 20; i++) {
				train[train_num][i - 1] = train[train_num][i];
			}
			train[train_num][20] = 0;

			train[train_num][0] = 0;
			train[train_num][21] = 0;
		}
	}
}

int canGoGalaxy(int num_train) {
	int num_go_galaxy = 0;
	for (int train_num = 1; train_num <= num_train; train_num++) {
		vector<int> now_train(train[train_num], train[train_num] + 25);
		/*cout << "now train : " << train_num << endl;
		for (int j = 0; j < 25; j++) {
			cout << now_train[j] << " ";
		}
		cout << endl << "--------------------------------------------" << endl;*/
		int sz = galaxy.size();
		int is_same = 0;
		for (int i = 0; i < sz; i++) {
			if (is_same) break;
			int same_cnt = 0;
			for (int j = 0; j < 25; j++) {
				if (now_train[j] == galaxy[i][j]) {
					//cout << galaxy[i][j] << " ";
					same_cnt++;
				}
			}
			//cout << " | "<<same_cnt<<endl;
			if (same_cnt == 25) {
				is_same = 1;
			}
		}
		if (!is_same) {
			num_go_galaxy++;
			galaxy.push_back(now_train);
		}
	}
	return num_go_galaxy;
}

void Solution(int num_train, int num_query) {
	processQuery(num_query);
	int ans = canGoGalaxy(num_train);
	cout << ans << endl;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j; //for문 변수 -> longlong필요한지 확인
	int num_train, num_query;
	cin >> num_train >> num_query;
	Solution(num_train, num_query);
	return 0;
}