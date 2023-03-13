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
int prime[10005];

int isprime(int a)
{
	for (int i = 2; i*i < a; i++)
		if (a%i) return 0;
	return 1;
}
void era() {
	for (int i = 2; i <= 10000; i++) prime[i] = 1;
	for (int i = 2; i <= 10000; i++) {
		for (int j = i * i; j <= 10000; j += i) {
			if (!prime[j]) continue;
			prime[j] = 0;
		}
	}
}
int visit[10005];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int i, j;//for문변수-->가끔식 long으로
	int T;
	scanf("%d", &T);
	era();
	//for (i = 1000; i <= 10000; i++) if (prime[i]) printf("%d\n", i);
	
	while(T--) {
		int start, end;
		scanf("%d %d", &start, &end);
		queue<int>q;

		for (i = 1000; i < 10000; i++) visit[i] = 1e9;
		q.push(start);
		visit[start] = 0;
		int cnt = 1;
		while (!q.empty()) {
			cnt++;
			if (cnt == 10000) {
				printf("Impossible\n");
				return 0;
			}
			int now = q.front();
			q.pop();
			if (now == end) break;
			for (i = 1; i <= 9; i++) {
				if (visit[i * 1000 + now % 1000] > visit[now] + 1 && prime[i * 1000 + now % 1000]) {
					visit[i * 1000 + now % 1000] = visit[now] + 1;
					q.push(i * 1000 + now % 1000);
				}	
			}
			for (i = 0; i <= 9; i++) {
				if (visit[((now / 1000) * 1000) + i * 100 + now % 100] > visit[now] + 1 && prime[((now / 1000) * 1000) + i * 100 + now % 100]) {
					visit[((now / 1000) * 1000) + i * 100 + now % 100] = visit[now] + 1;
					q.push(((now / 1000) * 1000) + i * 100 + now % 100);
				}
				if (visit[((now / 100) * 100) + i * 10 + now % 10] > visit[now] + 1 && prime[((now / 100) * 100) + i * 10 + now % 10]) {
					visit[((now / 100) * 100) + i * 10 + now % 10] = visit[now] + 1;
					q.push(((now / 100) * 100) + i * 10 + now % 10);
				}
				if (visit[((now / 10) * 10) + i] > visit[now] + 1 && prime[((now / 10) * 10) + i]) {
					visit[((now / 10) * 10) + i] = visit[now] + 1;
					q.push(((now / 10) * 10) + i);
				}


		
			}
		}
		printf("%d\n", visit[end]);
	}

	return 0;
}