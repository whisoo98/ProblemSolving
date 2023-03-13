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
	int month, day;
	scanf("%d %d", &month, &day);
	int tot_day = 0;
	int arr[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	vector<const char*> vec = { "SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT" };
	for (i = 0; i < month; i++) {
		tot_day += arr[i];
	}
	tot_day += day;
	printf("%s", vec[tot_day % 7]);


	return 0;
}