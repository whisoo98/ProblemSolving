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
#define N 
#define ll long long
#define endl "\n"
#define MID(a,b) (a+b)/2

using namespace std;

map<string, int> roman;
map<int, string> arabian;

void preProcess() {
	roman.insert({ "I",1 });
	roman.insert({ "V",5 });
	roman.insert({ "X",10 });
	roman.insert({ "L",50 });
	roman.insert({ "C",100 });
	roman.insert({ "D",500 });
	roman.insert({ "M",1000 });
	roman.insert({ "IV",4 });
	roman.insert({ "IX",9 });
	roman.insert({ "XL",40 });
	roman.insert({ "XC",90 });
	roman.insert({ "CD",400 });
	roman.insert({ "CM",900 });
	roman.insert({ "0",0 });

	arabian.insert({ 1,"I" });
	arabian.insert({ 5,"V" });
	arabian.insert({ 10,"X" });
	arabian.insert({ 50,"L" });
	arabian.insert({ 100,"C" });
	arabian.insert({ 500,"D" });
	arabian.insert({ 1000,"M" });
	arabian.insert({ 4 ,"IV",});
	arabian.insert({ 9,"IX" });
	arabian.insert({ 40,"XL" });
	arabian.insert({ 90,"XC" });
	arabian.insert({ 400,"CD" });
	arabian.insert({ 900,"CM" });
	arabian.insert({ 0,"0" });
}

int parseStringToNumber(string& str) {
	int ret = 0;
	for (int i = 0; i < str.length();) {
		string substr="";
		int subnum = 0;
		int len = 0;
		for (int j = i; j < str.length() && j <= i + 1; j++) {
			substr += str[j];
			if (roman.count(substr)) {
				len++;
			}
			else {
				substr = substr[0];
			}
		}
		subnum = roman[substr];
		ret += subnum;
		i += len;
	}
	return ret;
}

void convertNumberToString(string& roman, int* number, int value) {
	int mok = *number / value;
	*number %= value;
	while (mok--) {
		roman += arabian[value];
	}
}

string parseNumberToString(int num) {
	string roman = "";
	
	convertNumberToString(roman, &num, 1000);
	convertNumberToString(roman, &num, 900);
	convertNumberToString(roman, &num, 500);
	convertNumberToString(roman, &num, 400);
	convertNumberToString(roman, &num, 100);
	convertNumberToString(roman, &num, 90);
	convertNumberToString(roman, &num, 50);
	convertNumberToString(roman, &num, 40);
	convertNumberToString(roman, &num, 10);
	convertNumberToString(roman, &num, 9);
	convertNumberToString(roman, &num, 5);
	convertNumberToString(roman, &num, 4);
	convertNumberToString(roman, &num, 1);
	return roman;
}

void Solution(string& str1, string& str2) {
	preProcess();
	int roman1 = parseStringToNumber(str1);
	int roman2 = parseStringToNumber(str2);
	string ans = parseNumberToString(roman1 + roman2);
	
	cout << roman1 + roman2 << endl;
	cout << ans << endl;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j; //for문 변수 -> longlong필요한지 확인
	string str1, str2; cin >> str1 >> str2;
	Solution(str1, str2);

	return 0;
}