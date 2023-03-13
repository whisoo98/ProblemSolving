#include<stdio.h>
#include <iostream>
#include <string>

using namespace std;


int main() {
	string s;
	int chk = 0;//공백갯수체크
	int i = 0;//for 변수
	getline(cin, s);
	while (0 == 0) {
		if (s[i] == '\0') break;
		if (s[i] == ' ') chk++;

		//if (s[i] == '\0') chk++; 

		i++;
	}
	if (s[0] == ' ') chk--;
	if (s[s.size() - 1] == ' ') chk--;
	if (s[0] == '\0') printf("0");
	else printf("%d", chk + 1);
	return 0;
}