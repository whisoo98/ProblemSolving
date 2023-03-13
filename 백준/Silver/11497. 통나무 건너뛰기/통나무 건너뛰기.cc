#include <cstdio>
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
#include <climits>
#include <cstring>


using namespace std;

/*struct type_name {

}srt;*/

//vector <type> vec;
//stack <type> stk;
//queue <type> q;
//string str;
//map <key_type,value_type> m;
int T;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		int N = 0;
		int max = 0;
		scanf("%d", &N);
		int L[10000] = {};
		for (int j = 0; j < N; j++) {
			scanf("%d", &L[j]);
		}
		sort(L, L + N);
		for (int j = 0; j < N - 2; j++) { 
			max = max < L[j + 2] - L[j] ? L[j + 2] - L[j] : max; }
		printf("%d\n", max);
	}

	return 0;
}