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
	string s1 = "    8888888888  888    88888\n";
	string s2 = "   88     88   88 88   88  88\n";
	string s3 = "    8888  88  88   88  88888\n";
	string s4 = "       88 88 888888888 88   88\n";
	string s5 = "88888888  88 88     88 88    888888\n";
	cout << s1 << s2 << s3 << s4 << s5 << "\n";
	s1 = "88  88  88   888    88888    888888\n";
	s2 = "88  88  88  88 88   88  88  88\n";
	s3 = "88 8888 88 88   88  88888    8888\n";
	s4 = " 888  888 888888888 88  88      88\n";
	s5 = "  88  88  88     88 88   88888888\n";
	cout << s1 << s2 << s3 << s4 << s5;
	return 0;
}