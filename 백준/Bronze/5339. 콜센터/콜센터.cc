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
	string s1 = "     /~\\\n";
	string s2 = "    ( oo|\n";
	string s3 = "    _\\=/_\n";
	string s4 = "   /  _  \\\n";
	string s5 = "  //|/.\\|\\\\\n";
	string s6 = " ||  \\ /  ||\n";
	string s7 = "============\n";
	string s8 = "|          |\n";
	string s9 = "|          |\n";
	string s10 = "|          |\n";
	cout << s1 << s2 << s3 << s4 << s5 << s6 << s7 << s8 << s9 << s10;
	return 0;
}