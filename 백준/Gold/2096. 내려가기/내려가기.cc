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
	int n;
	scanf("%d", &n);
	int one, two, three;
	int min_one, min_two, min_three;
	int max_one, max_two, max_three;
	scanf("%d %d %d", &one, &two, &three);
	max_one = min_one = one;
	max_two = min_two = two;
	max_three = min_three = three;
	for (i = 2; i <= n; i++) {
		scanf("%d %d %d", &one, &two, &three);
		int t_one = min_one;
		int t_two = min_two;
		int t_three = min_three;
		min_one = min(t_one, t_two) + one;
		min_two = min(t_three, min(t_one, t_two)) + two;
		min_three = min(t_two, t_three) + three;
		 t_one = max_one;
		 t_two = max_two;
		 t_three = max_three;
		max_one = max(t_one, t_two) + one;
		max_two = max(t_three, max(t_one, t_two)) + two;
		max_three = max(t_two, t_three) + three;
	}
	printf("%d %d", max(max_three, max(max_one, max_two)), min(min_three, min(min_one, min_two)));

	return 0;
}