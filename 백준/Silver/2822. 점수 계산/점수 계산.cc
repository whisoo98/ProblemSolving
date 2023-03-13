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
	int arr[8];
	int temp_max[8];
	int num[5];
	for (i = 0; i < 8; i++) {
		scanf("%d", &arr[i]);
		temp_max[i] = arr[i];
	}
	sort(temp_max, temp_max + 8,greater<int>());
	printf("%d\n", temp_max[0] + temp_max[1] + temp_max[2] + temp_max[3] + temp_max[4]);
	for (i = 0; i < 5; i++) {
		for (j = 0; j < 8; j++) {
			if (temp_max[i] == arr[j]) num[i] = j;
		}
	}
	sort(num, num + 5);
	for (i = 0; i < 5; i++)printf("%d ", num[i]+1);
	return 0;
}