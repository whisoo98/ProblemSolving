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
	long long  i, j;//for문변수-->가끔식 long으로 s;
	long long s;
	scanf("%lld", &s);
	//printf("%lld", s);
	for (i = 1; i < 100000; i++) {
		//printf("%lld : %lld\n",i, i*i+i);
		if ((i*i + i)/2 >  s) {
		//	printf("!!!!!!!!!!!!!!!!!!!!\n");
			printf("%d", i - 1);
			return 0;
		}
	}
	return 0;
}