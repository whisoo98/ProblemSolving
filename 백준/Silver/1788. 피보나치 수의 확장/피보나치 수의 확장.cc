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
int Plus [1000005];
int Minus[1000005];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int i, j;//for문변수-->가끔식 long으로
	int n;
	scanf("%d", &n);
	Plus[0] = 0;
	Plus[1] = 1;
	Minus[0] = 0;
	Minus[1] = 1;
	if (n>0){
		for (i = 2; i <= n; i++) {
			Plus[i] = (Plus[i - 1] + Plus[i - 2]) % 1000000000;
		}
		printf("1\n%d", Plus[n]);
	}
	else if (n == 0) {
		printf("0\n0");
	}
	else {
		int m = -n;
		for (i = 2; i <= m; i++) {
			Minus[i] = (Minus[i - 2] - Minus[i - 1])% 1000000000;
		}
		int temp;
		if (Minus[m] < 0) temp = -1;
		else temp = 1;
		printf("%d\n%d",temp, abs(Minus[m]));
	}

	return 0;
}