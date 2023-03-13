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
#define N 250000

using namespace std;

/*struct type_name {

}srt;*/

//vector <type> vec;
//stack <type> stk;
//queue <type> q;
//string str;
//map <key_type,value_type> m;
int arr[N];
void era() {
	int i, j;
	for (i = 2; i <= N; i++) arr[i] = 1;
	for (i = 2; i <= N; i++) {
		for (j = 2 * i; j <= N; j = j + i) {
			if (arr[j] == 0) continue;
			arr[j] = 0;
		}
	}

}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int i, j;//for문변수-->가끔식 long으로
	int n;
	scanf("%d", &n);
	era();
	while (n) {
		int chk = 0;
		for (i = n + 1; i <= 2 * n; i++) {
			if (arr[i] == 1) chk++;
		}
		printf("%d\n", chk);
		scanf("%d", &n);
	}

	return 0;
}