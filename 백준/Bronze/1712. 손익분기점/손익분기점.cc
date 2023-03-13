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
#define N 
#define ll long long
#define endl "\n"
#define MID(a,b) (a+b)/2

using namespace std;




int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j; //for문 변수 -> longlong필요한지 확인
	int constcost, cost, price;
	cin >> constcost >> cost >> price;
	if (cost > price) {
		cout << -1;
		return 0;
	}
	if (cost == price) {
		if (constcost == 0) {
			cout << 0;
			return 0;
		}
		cout << -1;
		return 0;
	}
	int profit = price - cost;
	int mok = constcost / profit;
	int rest = constcost % profit;
	//if (rest) mok++;
	cout << mok + 1;
	return 0;
}