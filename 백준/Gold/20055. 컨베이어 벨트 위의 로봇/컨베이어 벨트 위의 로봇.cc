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
#define N 220
#define ll long long
#define endl "\n"
#define MID(a,b) (a+b)/2

using namespace std;

int durability[N];
int inRobots[N];
queue<int> robots;

int upto;
int downto;
int n, k;
int cnt0;
int debug0;
void rotateConveyor() {
	//cout << "--------before rotate---------" << endl;
	//for (int i = 0; i < n; i++) {
	//	cout << durability[i] << " ";
	//}
	//cout << endl;
	//cout << "--------before rotate---------" << endl;

	int temp1, temp2;
	temp1 = durability[0];
	for (int i = 1; i < n; i++) {
		temp2 = durability[i];

		durability[i] = temp1;

		temp1 = temp2;

	}
	durability[0] = temp1;

	//cout << "--------after rotate---------" << endl;
	//for (int i = 0; i < n; i++) {
	//	cout << durability[i] << " ";
	//}
	//cout << endl;
	//cout << "--------after rotate---------" << endl;

	int sz = robots.size();
	for (int i = 0; i < sz; i++) {
		int robot = robots.front();

		inRobots[robot]--;
		robots.pop();

		robot++;
		robot %= n;
		if (robot == downto) {
			continue;
		}
		robots.push(robot);
		inRobots[robot]++;
	}
}

void moveRobots() {
	int sz = robots.size();
	for (int i = 0; i < sz; i++) {
		int robot = robots.front();

		robots.pop();
		inRobots[robot]--;

		if (inRobots[(robot + 1)%n] || !durability[(robot + 1) % n]) {
			robots.push(robot);
			inRobots[robot]++;
			continue;
		}
		robot++;
		robot %= n;
		durability[robot]--;
		if (durability[robot] == 0) {
			cnt0++;
		}
		if (robot == downto) {
			continue;
		}
		robots.push(robot);
		inRobots[robot]++;
	}
}

void upRobot() {
	if (!durability[upto]) return;
	//if (inRobots[upto]) return;
	durability[upto]--;
	if (durability[upto] == 0) {
		cnt0++;
	}
	robots.push(upto);
	inRobots[upto]++;
	
}

int isStop() {
	/*debug0 = 0;
	for (int i = 0; i < n; i++) {
		if (durability[i] == 0) debug0++;
	}
	cout << cnt0 << " " << debug0 << endl;*/
	if (cnt0 >= k) return 1;
	return 0;
}

void conveyor() {
	int steps = 1;
	int stop = 0;
	while (1) {
		rotateConveyor();
		moveRobots();
		upRobot();
		stop = isStop();
		if (stop) {
			break;
		}
		steps++;
	}
	cout << steps << endl;
}

void Solution() {
	upto = 0;
	downto = n-1;
	n = n * 2;
	conveyor();
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j; //for문 변수 -> longlong필요한지 확인
	cin >> n >> k;
	for (int i = 0; i < 2*n; i++) {
		cin>>durability[i];
	}
	Solution();
	return 0;
}