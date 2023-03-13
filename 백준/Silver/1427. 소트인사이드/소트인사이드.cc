#include <stdio.h>
#include<algorithm>
#include<string>
#include<iostream>
#include<string.h>
#include<functional>
using namespace std;
int main()
{
	string s;
	cin >> s;
	sort(s.begin(), s.end(),greater<int>());
	cout << s;

	return 0;
}