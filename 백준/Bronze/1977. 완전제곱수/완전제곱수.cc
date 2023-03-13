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
#include<cmath>

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
	int n, m;
	scanf("%d %d", &n, &m);
	int sum=0;
	int MIN = 987654321;
	for (i = sqrt(n); i <= sqrt(m); i++) {
		if (i*i < n) continue;
		MIN = min(MIN, i*i);
		sum += i * i;
	}
	if (sum == 0) {
		printf("-1");
		return 0;
	}
	printf("%d\n%d", sum, MIN);

	return 0;
}