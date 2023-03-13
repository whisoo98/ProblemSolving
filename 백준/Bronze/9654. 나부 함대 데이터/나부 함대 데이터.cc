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
	string s1 = "SHIP NAME      CLASS          DEPLOYMENT IN SERVICE\n";
	string s2 = "N2 Bomber      Heavy Fighter  Limited    21        \n";
	string s3 = "J-Type 327     Light Combat   Unlimited  1         \n";
	string s4 = "NX Cruiser     Medium Fighter Limited    18        \n";
	string s5 = "N1 Starfighter Medium Fighter Unlimited  25        \n";
	string s6 = "Royal Cruiser  Light Combat   Limited    4         \n";
	cout << s1 << s2 << s3 << s4 << s5 << s6;

	return 0;
}