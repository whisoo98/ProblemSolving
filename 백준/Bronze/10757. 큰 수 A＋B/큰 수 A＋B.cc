#include <iostream>
#include <algorithm>
#include <functional>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <string>
#include <queue>
#include <stack>
#include <map>
#include <vector>
#include <set>
#include <sstream>
#include <ctime>
#include <climits>
#include <tuple>
#include<cctype>
using namespace std;

int arr[10005];
int brr[10005];
int crr[10005];
stack<int> ans;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j; //for문 변수 -> longlong필요한지 확인
	string s1, s2; cin >> s1 >> s2;
	//cout << s1 <<endl<< s2<<endl;
	int len1 = s1.length();
	int len2 = s2.length();
	for (i = 0; i < len1; i++) {
		arr[i + 1] = s1[len1 - 1 - i] - '0';
	}
	
	
	for (i = 0; i < len2; i++) {
		brr[i + 1] = s2[len2 - 1 - i] - '0';
	}
	int len = max(len1, len2);
	for (i = 1; i <= len; i++) {
		int temp = arr[i] + brr[i];
		crr[i] += temp;
		if (crr[i] >= 10) {
			crr[i] %= 10;
			crr[i + 1]++;
		}
		ans.push(crr[i]);
	}
	if (crr[len + 1]) {
		ans.push(crr[len + 1]);
	}
	while(!ans.empty()) {
		cout << ans.top();
		ans.pop();
	}
	return 0;

}