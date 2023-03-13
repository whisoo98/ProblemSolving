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

long long GCD(long long a, long long b) {
	if (!(a%b)){
		return b;
	}
	return GCD(b, a%b);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	long long i, j;//for문변수-->가끔식 long으로
	long long gcd, lcm;
	scanf("%lld %lld", &gcd, &lcm);
	//int gcd = GCD(a, b);
	for (i = sqrt(gcd*lcm); i >= 1; i--) {
		//long long temp = i;
		if (!((gcd*lcm) % i)) {
			if (GCD(i, gcd*lcm / i) == gcd) {
				printf("%lld %lld", i, gcd*lcm / i);
				break;
			}
		}
	}

	return 0;
}