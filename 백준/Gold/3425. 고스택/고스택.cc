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

using namespace std;




int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j; //for문 변수 -> longlong필요한지 확인
	while (1) {
		string cmd; vector<string> v;
		while (1) {
			//cin >> cmd;
			getline(cin, cmd);
			if (cmd == "END") break;
			else if (cmd == "QUIT") return 0;
			v.push_back(cmd);
		}
	
		int n; cin >> n;
		while (n--) {
			long long a; cin >> a;
			stack<long long> stk;
			stk.push(a);
			int flag = 1;
			for (auto i : v) {
				
				//string cmd; cin >> cmd;
				if (i == "POP") {
					if (stk.empty()) {
						flag = 0;
						break;
					}
					stk.pop();
				}
				else if (i == "INV") {
					if (stk.empty()) {
						flag = 0;
						break;
					}
					long long temp = stk.top();
					stk.pop();
					stk.push(-temp);
				}
				else if (i == "DUP") {
					if (stk.empty()) {
						flag = 0;
						break;
					}
					stk.push(stk.top());
				}
				else if (i == "SWP") {
					if (stk.size()<=1) {
						flag = 0;
						break;
					}
					long long temp1 = stk.top();
					stk.pop();
					long long temp2 = stk.top();
					stk.pop();
					stk.push(temp1);
					stk.push(temp2);
				}
				else if (i == "ADD") {
					if (stk.size() <= 1) {
						flag = 0;
						break;
					}
					long long temp1 = stk.top();
					stk.pop();
					long long temp2 = stk.top();
					stk.pop();
					if (abs(temp1 + temp2) > 1000000000) {
						flag = 0;
						break;
					}
					stk.push(temp1 + temp2);
				}
				else if (i == "SUB") {
					if (stk.size() <= 1) {
						flag = 0;
						break;
					}
					long long temp1 = stk.top();
					stk.pop();
					long long temp2 = stk.top();
					stk.pop();
					if (abs(temp2 - temp1) > 1000000000) {
						flag = 0;
						break;
					}
					stk.push(temp2 - temp1);
				}
				else if (i == "MUL") {
					if (stk.size() <= 1) {
						flag = 0;
						break;
					}
					long long temp1 = stk.top();
					stk.pop();
					long long temp2 = stk.top();
					stk.pop();
					if (abs(temp2*temp1) > 1000000000) {
						flag = 0;
						break;
					}
					stk.push(temp2 * temp1);
				}
				else if (i == "DIV") {
					if (stk.size() <= 1) {
						flag = 0;
						break;
					}
					long long temp1 = stk.top();
					stk.pop();
					long long temp2 = stk.top();
					stk.pop();
					if (temp1 == 0) {
						flag = 0;
						break;
					}
					else {
						if ((temp1 < 0 && temp2 < 0) || (temp1 > 0 && temp2 > 0)) {
							flag = 1;
						}
						else flag = -1;
					}
					if (abs(abs(temp2) / abs(temp1)) > 1000000000) {
						flag = 0;
						break;
					}
					stk.push(abs(abs(temp2) / abs(temp1))*flag);
				}
				else if (i == "MOD") {
					if (stk.size() <= 1) {
						flag = 0;
						break;
					}
					long long temp1 = stk.top();
					stk.pop();
					if (temp1 == 0) {
						flag = 0;
						break;
					}
					long long temp2 = stk.top();
					stk.pop();
					if (temp2 < 0) {
						flag = -1;
					}
					else if (temp2 > 0) {
						flag = 1;
					}
					if (abs(abs(temp2) % abs(temp1)) > 1000000000) {
						flag = 0;
						break;
					}
					stk.push(abs(abs(temp2) % abs(temp1))*flag);
					//stk.push(temp2 % temp1);
				}
				else{ //NUM
					//long long temp; cin >> temp;
					stringstream ss(i);
					string str; long long temp;
					ss >> str;
					if (str == "NUM") {
						ss >> temp;
						stk.push(temp);
					}
				}
			}
			if (stk.size() != 1 || flag==0) cout << "ERROR\n";
			else if (abs(stk.top()) > 1000000000) {
				cout << "ERROR\n";
			}
			else {
				cout << stk.top() << "\n";
			}
		}
		cout << "\n";
	}

	return 0;
}