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
	int arr[6] = { 500,100,50,10,5,1 };
	int price;
	scanf("%d", &price);
	int rest = 1000 - price;
	int cnt = 0;
	i = 0;
	while (rest) {
		cnt += rest / arr[i];
		rest %= arr[i];
		i++;
	}
	printf("%d", cnt);

	return 0;
}