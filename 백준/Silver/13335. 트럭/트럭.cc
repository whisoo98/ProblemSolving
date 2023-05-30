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
#define N 1'005
#define ll long long
#define endl "\n"
#define MID(a,b) (a+b)/2

using namespace std;

int trucks[N];


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j; //for문 변수 -> longlong필요한지 확인
	int n, len_bridge, weight_bridge; cin >> n >> len_bridge >> weight_bridge;
	for (int i = 0; i < n; i++) {
		cin >> trucks[i + 1];
	}
	queue<int> q_truck;
	queue<int> q_index;
	queue<int> q_dist;
	q_truck.push(trucks[1]);
	q_index.push(1);
	q_dist.push(1);
	int idx_truck = 2;
	int t = 1;
	while (q_truck.size()) {
		int sz = q_truck.size();
		int weight = 0;
		while (sz--) {
			int truck = q_truck.front();
			int index = q_index.front();
			int dist = q_dist.front();
			q_truck.pop();
			q_index.pop();
			q_dist.pop();

			dist++;
			if (dist > len_bridge)
				continue;
			weight += truck;
			q_truck.push(truck);
			q_index.push(index);
			q_dist.push(dist);
		}
		if ((weight + trucks[idx_truck] <= weight_bridge) && idx_truck <= n) {
			q_index.push(idx_truck);
			q_truck.push(trucks[idx_truck]);
			q_dist.push(1);
			idx_truck++;
		}
		t++;
	}
	cout << t << endl;
	return 0;
}