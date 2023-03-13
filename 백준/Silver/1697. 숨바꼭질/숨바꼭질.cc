#include <stdio.h>
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <functional>
#include <stdlib.h>
#include <string>
#include <queue>
#include <stack>
#include <map>


using namespace std;

/*struct type_name {

}srt;*/

//vector <type> vec;
//stack <type> stk;
//queue <type> q;
//string str;
//map <key_type,value_type> m;
int n, k;
queue<int> q;
vector<int>v;
int dp[100005];
int visit[100005];


/*now 
now -1 
now +! 
now * 2

visit = 1e9
if(visit[next] > visit[now]+1)
visit[next] = visit[now]+1*/
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int i, j;//for문변수-->가끔식 long으로
	cin >> n >> k;
	q.push(n);
	dp[n] = 0;
	for (i = 0; i <= 100004; i++)visit[i] = 1e9;
	visit[n] = 0;
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		if (now == k) {
			cout << visit[k];
			return 0;
		}
		if (now < 0) continue;
		else if (now > k && visit[now - 1] > visit[now] + 1) {
			q.push(now - 1);
			visit[now - 1] = visit[now] + 1;
		}
		else {
			if (visit[now - 1] > visit[now] + 1) {
				q.push(now - 1);
				visit[now - 1] = visit[now] + 1;
			}
			if (visit[now + 1] > visit[now] + 1) {
				q.push(now + 1);
				visit[now + 1] = visit[now] + 1;
			}
			if (visit[now * 2] > visit[now] + 1) {
				q.push(2 * now);
				visit[now * 2] = visit[now] + 1;
			}
		}
		//	}
	}
	return 0;
}