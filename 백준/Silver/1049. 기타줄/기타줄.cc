#include <stdio.h>
#include <iostream>
#include <vector>
//#include <set>
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
int set[55];
int sol[55];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int i, j;//for문변수-->가끔식 long으로
	int n, m;
	scanf("%d %d", &n, &m);
	for (i = 0; i < m; i++) {
		scanf("%d %d", &set[i], &sol[i]);
	}
	sort(set, set + m);
	sort(sol, sol + m);
	if (sol[0] != 0) {
		int eff = set[0] / sol[0]; // eff 이상의 갯수를 살때는 set이 이득이다.
		int SET = n / 6;
		int SOL = n % 6;
		/*if (SOL >= eff) {
			printf("%d", min((SET + 1)*set[0],n*sol[0]));
		}
		else {
			printf("%d", min(SET*set[0] + SOL * sol[0],n*sol[0]));
		}*/
		printf("%d", min(min(SET*set[0] + SOL * sol[0], n*sol[0]), min((SET + 1)*set[0], n*sol[0])));

	}
	else printf("0");
	return 0;
}