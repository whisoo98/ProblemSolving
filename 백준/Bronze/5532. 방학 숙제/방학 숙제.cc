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
	int total, math, kor, sol_m, sol_k;
	scanf("%d %d %d %d %d", &total, &kor, &math, &sol_k, &sol_m);
	i = 1;
	while (sol_m*i < math || sol_k*i < kor) {
		i++;
	}
	printf("%d",total - i);

	return 0;
}