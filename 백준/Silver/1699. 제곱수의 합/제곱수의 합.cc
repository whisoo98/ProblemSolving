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

int arr[100005];


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int i, j;//for문변수-->가끔식 long으로
	int n;
	scanf("%d", &n);
	for (i = 1; i*i <= n; i++) arr[i*i] = 1;
	int temp;
	for (i = 1; i <= n; i++) {
		if (arr[i] == 1) {
			temp = i;
			continue;
		}

		arr[i] = arr[temp] + arr[i - temp];
		
		for (j = 1; j*j <= temp ; j++) {
			arr[i] = min(arr[i],arr[j*j] + arr[i-(j*j)] );
		}
	}
	printf("%d", arr[n]);
	return 0;
}