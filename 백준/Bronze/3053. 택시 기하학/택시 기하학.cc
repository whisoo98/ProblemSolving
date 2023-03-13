#include <iostream>
#include <algorithm>
#include <functional>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <string>
#include <queue>
#include <stack>
#include <map>
#include <vector>
#include <set>
#include <sstream>

#define phi 3.14159265358979323846

using namespace std;





int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j; //for문 변수 -> longlong필요한지 확인
	double n; cin >> n;
	cout.precision(5);
	cout << fixed;
	cout << n * n*phi << "\n";
	cout << 2 * n*n;
	return 0;
}