#include <cstdio>
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
#include <climits>
#include <cstring>


using namespace std;

struct Stat {
	int hp = 0, mp = 0, atk = 0, def = 0;
};

//vector <type> vec;
//stack <type> stk;
//queue <type> q;
//string str;
//map <key_type,value_type> m;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int i, j;//for문변수-->가끔식 long으로
	int n; scanf("%d", &n);

	for (i = 0; i < n; i++) {
		Stat stat;
		for (j = 0; j < 2; j++) {
			int a, b, c, d;
			scanf("%d %d %d %d", &a, &b, &c, &d);
			stat.hp += a; stat.mp += b; stat.atk += c; stat.def += d;
		}
		if (stat.hp < 1) stat.hp = 1;
		if (stat.mp < 1) stat.mp = 1;
		if (stat.atk < 0) stat.atk = 0;
		printf("%d\n", stat.hp + stat.mp * 5 + stat.atk * 2 + stat.def * 2);
	}
	//for(i=0;i<n;i++) {}
	//for(i=0;i<n;i++) { for(j=0;j<n;j++) { } }

	return 0;
}