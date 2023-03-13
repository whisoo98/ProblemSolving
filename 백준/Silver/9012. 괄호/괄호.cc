#include<stdio.h>
#include<stack>
#include<string>
#include<string.h>
#include<iostream>
using namespace std;

char str[51];
int main() {
	
	char a;//push 변수
	int n;//받는 갯수
	scanf("%d", &n);
	int i;
	int chk;//break 체커
	while (n > 0) {
		chk = 0;
		stack<char> stk;
		scanf("%s", str);
		for (i = 0; i < strlen(str); i++) {
			a = str[i];
			if (a == '(') stk.push(a);
			else if (a==')') {
				if (stk.size() == 0) {
					printf("NO\n");
					chk++;
					break;
				}
				else stk.pop();
			}
		}
		if ( chk == 0 ) {
			if ( stk.size() == 0 ) printf("YES\n");
			else printf("NO\n");
		}
		n--;
	}
	

	return 0;
}