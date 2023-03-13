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
#include<cmath>

using namespace std;

/*struct type_name {

}srt;*/

//vector <type> vec;
//stack <type> stk;
//queue <type> q;
//string str;
//map <key_type,value_type> m;
int A, B, D, result, d, r, D1;
int num[4000001];

int main()
{
	scanf("%d %d %d", &A, &B, &D);
	D1 = D;
	while (D1 > 0) {
		d++;
		D1 /= 10;
	}
	//cout << d << endl;
	r = pow(10, d);
	for (int i = 2; i <= B; i++) {
		num[i] = 1;
	}

	for (int i = 2; i <= B; i++) {
		if (num[i] == 1) {
			for (int j = i + i; j <= B; j += i) num[j] = 0;
		}
	}

	for (int i = A; i <= B; i++) {
		if(num[i]==1){
			int temp, N = i;
			while (N >= D) {
				temp = N % r;
				if (temp == D) {
					result++;
					break;
				}
				else N = N / 10;
			}
		}
	}
	printf("%d", result);
	return 0;
}