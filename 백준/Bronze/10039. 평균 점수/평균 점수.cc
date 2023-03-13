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
	int arr[5];
	int sum = 0;
	for (i = 0; i < 5; i++) {
		scanf("%d", &arr[i]);
		if (arr[i] < 40) arr[i] = 40;
		sum += arr[i];
	}
	printf("%d", sum / 5);


	return 0;
}