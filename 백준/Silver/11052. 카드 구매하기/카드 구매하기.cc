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
int arr[10000];
int price[1005][2];//[x][1] = 처음 한장 자체, [x][2] = 최종값
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int i, j;//for문변수-->가끔식 long으로
	int n;
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		scanf("%d", &arr[i]);
		price[i][1] = arr[i];
	}
	price[1][2] = arr[1];
	price[2][2] = max(price[2][1], price[1][2] + price[1][2]);
	//price[1][1] = arr[1];
	/// n = a+b의 꼴에 대해서 a의 가격합 b의 가격합 찾는거임!
	for (int k = 3; k <= n; k++) {
		for (i = 1; i <= k / 2; i++) {
			price[k][2] = max(price[k][2],max(price[k][1], price[i][2] + price[k - i][2]));
		}
				
	}
	printf("%d", price[n][2]);

	return 0;
}