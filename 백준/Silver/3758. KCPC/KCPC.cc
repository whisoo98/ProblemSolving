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


//vector <type> vec;
//stack <type> stk;
//queue <type> q;
//string str;
//map <key_type,value_type> m;

struct Team {
	//int id;
	//int pro_num[105];//문제번호
	int count = 0;//총 제출 횟수
	int last = 0;//마지막 제출자
	int score[105] = { 0, };//점수
	int sum = 0;
};

int main()
{
		
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int i, j;//for문변수-->가끔식 long으로
	int T;

	//cin >> T;
	scanf("%d", &T);
	int n, k, t, m; // n = 팀의수      k = 문제수			t= 내팀번호		m= 로그 수
	while (T--) {
		//cin >> n >> k >> t >> m;
		Team team[105];
		scanf("%d %d %d %d", &n, &k, &t, &m);
		for (i = 1; i <= m; i++) {
			int id, pro, point;
			//cin >> id >> pro >> point;//팀명, 문제 번호, 획득점수
			scanf("%d %d %d", &id, &pro, &point);
			team[id].count++;
			team[id].last=i;
			//team[id].score[pro] = max(team[id].score[pro], point);
			if (team[id].score[pro] < point) {
			//	team[id].last = i;
				team[id].sum -= team[id].score[pro];
				team[id].sum += point;
				team[id].score[pro] = point;
			}
		}
		int rank = 1;
		for (i = 1; i <= n; i++) {
			if (i == t) continue;
			if (team[i].sum > team[t].sum) rank++;
			else if (team[i].sum == team[t].sum) {
				if (team[i].count < team[t].count) rank++;
				else if (team[i].count == team[t].count) {
					if (team[i].last < team[t].last) rank++;
				}
			}
		}
		//cout << rank << "\n";
		printf("%d\n", rank);




	
	}

	return 0;
}