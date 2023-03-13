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
	string s1 = "       _.-;;-._\n";
	string s2 = "\'-..-\'|   ||   |\n";
	string s3 = "\'-..-\'|_.-;;-._|\n";
	string s4 = "\'-..-\'|   ||   |\n";
	string s5 = "\'-..-\'|_.-\'\'-._|\n";
	cout << s1 << s2 << s3 << s4 << s5;
	return 0;
}