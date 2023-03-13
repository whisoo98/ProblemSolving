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

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int i, j;//for문변수-->가끔식 long으로
	int t; scanf("%d", &t);
	while (t--) {
		vector<int>v;
		double num; scanf("%lf", &num);
		double avg;
		int sum = 0;
		for (i = 0; i < num; i++) {
			int a; scanf("%d", &a);
			sum += a;
			v.push_back(a);
		}
		avg = sum / num;
		int chk = 0;
		for (i = 0; i < num; i++) {
			if (v[i] > avg) {
				chk++;
			}
		}
		
		printf("%.3lf%%\n", chk / num*100); 
	}

	//for(i=0;i<n;i++) {}
	//for(i=0;i<n;i++) { for(j=0;j<n;j++) { } }

	return 0;
}