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
#include <cmath>
#include <sstream>


using namespace std;

/*struct type_name {

}srt;*/

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

	int div, c1, d;
	int a, b;
	scanf("%d%d%d", &div, &a, &b);
	int n=div;
	int cnt = 0;
	int i = 2;
	while (1) {
		cnt++;
		if (a%i != 0) {
			a++;
		}
		a = (a / i);
		if (b%i != 0) {
			b++;
		}
		b = (b / i);
		if (a == b) {
			printf("%d\n", cnt);
			break;
		}
	}
	return 0;
}