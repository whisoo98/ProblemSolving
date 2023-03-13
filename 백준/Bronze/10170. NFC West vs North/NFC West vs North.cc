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

using namespace std;




int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j; //for문 변수 -> longlong필요한지 확인
	string s1 = "NFC West       W   L  T\n";
	string s2 = "-----------------------\n";
	string s3 = "Seattle        13  3  0\n";
	string s4 = "San Francisco  12  4  0\n";
	string s5 = "Arizona        10  6  0\n";
	string s6 = "St. Louis      7   9  0\n";
	cout << s1 << s2 << s3 << s4 << s5 << s6 << "\n";
	s1 = "NFC North      W   L  T\n";
	s2 = "-----------------------\n";
	s3 = "Green Bay      8   7  1\n";
	s4 = "Chicago        8   8  0\n";
	s5 = "Detroit        7   9  0\n";
	s6 = "Minnesota      5  10  1\n";
	cout << s1 << s2 << s3 << s4 << s5 << s6 << "\n";

	return 0;
}