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
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int i, j;//for문변수-->가끔식 long으로
	int e, s, m;
	scanf("%d %d %d", &e, &s, &m);
	//e 1~15, s 1~28, m 1~19
	int y=0, k;
	i = 0, j = 0, k = 0;
	while (i != e%15 || j != s%28 || k != m%19) {
		i = (i + 1) % 15;
		j = (j + 1) % 28;
		k = (k + 1) % 19;
		y += 1;
	}
	if (y == 0) {
		printf("7980");
		return 0;
	}
	printf("%d",y);


	return 0;
}