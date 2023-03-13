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
int V, E, W;
struct Edge {
	int start, end, price;
};
vector<Edge>edge;
int visit[505];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int i, j;//for문변수-->가끔식 long으로
	int T;
	scanf("%d", &T);
	while (T--) {
		int chk = 0;
		scanf("%d %d %d", &V, &E, &W);
		for (i = 0; i < E; i++) {
			int a, b, c;
			scanf("%d %d %d", &a, &b, &c);
			edge.push_back({ a,b,c });
			edge.push_back({ b,a,c });
		}
		for (i = 0; i < W; i++) {
			int a, b, c;
			scanf("%d %d %d", &a, &b, &c);
			edge.push_back({ a,b,-c });//-c??
		}
		//이 위는 fix

	/*	for (i = 1; i <= V; i++) {
			if (!chk) {
				/*for (j = 1; j <= V; j++) {
					if (i == j) visit[j] = 0;
					else visit[j] = 987654321;
				}*/

		for (i = 1; i <= V; i++) visit[i] = 987654321;
		//for (i = 1; i <= V; i++) {
			//visit[i] = 0;
		visit[edge[0].start] = 0;
				for (int k = 0; k <= V; k++) {
					for (j = 0; j < edge.size(); j++) {
						if ( visit[edge[j].end] > visit[edge[j].start] + edge[j].price) {
							visit[edge[j].end] = visit[edge[j].start] + edge[j].price;
							if (k == V) {
								chk++;
								break;
							}
						}
					}
				}
			
		//}
		if (chk) {
			printf("YES\n");
			//	break;
		}
		else if (!chk) {
			printf("NO\n");
		}
		edge.clear();

	}
	return 0;
}
