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

vector <int> vec;
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
	//printf("%d", );
	scanf("%d", &n);
	for (i = 0; i < n; i++) scanf("%d", &arr[i]);
	for (i = 0; i < n; i++) {
		int idx = lower_bound(vec.begin(), vec.end(), arr[i])-vec.begin();
		if (idx < vec.size()) {
			vec.erase(vec.begin() + idx);
			vec.insert(vec.begin() + idx, arr[i]);
		}
		else vec.push_back(arr[i]);
	}
	printf("%d", n-vec.size());
	return 0;
}