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
	int T;
	scanf("%d", &T);
	while (T--) {
		int dont_reward;
		int do_reward;
		int cost;
		scanf("%d %d %d", &dont_reward, &do_reward, &cost);
		int actual_rewad = do_reward - cost;
		if (actual_rewad > dont_reward) printf("advertise\n");
		else if (actual_rewad == dont_reward) printf("does not matter\n");
		else printf("do not advertise\n");

	}

	return 0;
}