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
#define N 1000005
using namespace std;

int arr[N * 2]; 


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j; //for문 변수 -> longlong필요한지 확인
	int n; cin >> n;
	queue<int> q;
	for (i = 1; i <= n; i++) {
		q.push(i);
	}
	while(1) {
		if (q.size() == 1) {
			break;
		}
		q.pop();
		q.push(q.front());
		q.pop();
	}
	cout << q.front();
	
	return 0;
}