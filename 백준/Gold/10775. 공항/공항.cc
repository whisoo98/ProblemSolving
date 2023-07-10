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
#define N 100'005
#define ll long long
#define endl "\n"
#define MID(a,b) (a+b)/2

using namespace std;



int gates[N];
int Find(int x) {
	if (gates[x] == x)return x;
	return gates[x] = Find(gates[x]);
}

void Union(int x, int y) {
	x = Find(x);
	y = Find(y);
	if (x != y) gates[y] = x;
}


void Solution(int g, int p, vector<int>& plane_to_gate) {
	int ans = 0;
	for (auto planes : plane_to_gate) {

		if (Find(planes) == 0) {
			break;
		}
		else {
			ans++;
			Union(Find(planes) - 1, planes);
		}
	}
	cout << ans << endl;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j; //for문 변수 -> longlong필요한지 확인
	int g, p; cin >> g >> p;
	vector<int> plane_to_gate;
	for (int i = 0; i < p; i++) {
		int a; cin >> a;
		plane_to_gate.push_back(a);
	}
	for (int i = 1; i <= g; i++) {
		gates[i] = i;
	}
	Solution(g, p, plane_to_gate);
	return 0;
}