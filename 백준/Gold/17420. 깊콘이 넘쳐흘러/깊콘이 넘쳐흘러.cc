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
#include <cmath>
#include <sstream>


using namespace std;

/*struct type_name {

}srt;*/

//vector <type> vec;
//stack <type> stk;
//queue <type> q;
//string str;
//map <key_type,value_type> m;

long long arr[100005];
//priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<long long>> p;
priority_queue<pair<long long, long long>> p1;
priority_queue<long long> p2;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	long long i, j;
	int n; //cin >> n;
	scanf("%d", &n);
	long long chk = 0;
	for (i = 1; i <= n; i++) {
		//cin >> arr[i];
		scanf("%lld", &arr[i]);
	}
	for (i = 1; i <= n; i++) {
		long long temp;
		//cin >> temp;
		scanf("%lld", &temp);
		p1.push({ -arr[i],-temp });//남아있는 기한이 가장 적은 깊콘
		p2.push(-temp);//서순
	}
	
	while (!p2.empty()) {
		long long brr = -p1.top().first;
		long long cmp = -p1.top().second;

		if (brr >= cmp) {
			if (cmp == -p2.top()) {
				p1.pop();
				p2.pop();
			}
			else {
				brr += 30;
				p1.pop();
				p1.push({ -brr,-cmp });
				chk++;
			}
		}
		else {
			long long tm = cmp - brr;
			if (tm % 30 != 0) {
				long long mok = tm / 30 + 1;
				brr = brr + mok * 30;
				p1.pop();
				p1.push({ -brr,-cmp });
				chk += mok;
			}
			else {
				long long mok = tm / 30;
				brr = brr + mok * 30;
				p1.pop();
				p1.push({ -brr,-cmp });
				chk += mok;
			}
		}
	/*	if (cmp == -p2.top() && brr >= cmp) {
			//cout << brr << " " << cmp << endl;
			p1.pop();
			p2.pop();
		}
		else {
			brr += 30;
			p1.pop();
			p1.push({ -brr,-cmp });
			chk++;
		}*/
	}
	//cout << chk;
	printf("%lld", chk);
	return 0;
}