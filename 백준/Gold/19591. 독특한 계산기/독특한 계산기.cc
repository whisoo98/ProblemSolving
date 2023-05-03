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




int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j; //for문 변수 -> longlong필요한지 확인
	string expression; cin >> expression;
	deque<ll> numbers;
	deque<char> buho;
	stringstream ss;
	ss << expression;
	char del;
	ll num;

	if (expression[0]-'0' >= 0 && expression[0]-'0'<= 9) {
		ss >> num;
		numbers.push_back(num);
		while (ss.good()) {
			ss >> del >> num;
			numbers.push_back(num);
			buho.push_back(del);
		}
	}
	else {
		//ss >> del;
		ss >> num;
	/*	if (del == '-') {
			num -= num;
		}*/
		numbers.push_back(num);
		while (ss.good()) {
			ss >> del >> num;
			numbers.push_back(num);
			buho.push_back(del);
		}
	}
	/*for (auto it : numbers) {
		cout << it << " ";
	}
	cout << endl;
	for (auto it : buho) {
		cout << it << " ";
	}
	cout << endl;*/
	while (buho.size()) {
		tuple<ll, ll, char> front = { numbers[0], numbers[1], buho[0] };
		tuple<ll, ll, char> back = { numbers[numbers.size() - 2], numbers[numbers.size() - 1], buho[buho.size() - 1] };
		ll front_calc = 0;
		ll back_calc = 0;

		if (get<2>(front) == '*' or get<2>(front) == '/') {
			if (get<2>(back) == '*' or get<2>(back) == '/') {
				if (get<2>(front) == '*') {
					front_calc = get<0>(front) * get<1>(front);
				}
				else {
					front_calc = get<0>(front) / get<1>(front);
				}
				if (get<2>(back) == '*') {
					back_calc = get<0>(back) * get<1>(back);
				}
				else {
					back_calc = get<0>(back) / get<1>(back);
				}
				if (front_calc >= back_calc) {
					buho.pop_front();
					numbers.pop_front();
					numbers.pop_front();
					numbers.push_front(front_calc);
				}
				else {
					buho.pop_back();
					numbers.pop_back();
					numbers.pop_back();
					numbers.push_back(back_calc);
				}
			}
			else {
				if (get<2>(front) == '*') {
					front_calc = get<0>(front) * get<1>(front);
				}
				else {
					front_calc = get<0>(front) / get<1>(front);
				}
				buho.pop_front();
				numbers.pop_front();
				numbers.pop_front();
				numbers.push_front(front_calc);
			}
		}
		else {
			if (get<2>(back) == '*' or get<2>(back) == '/') {
				if (get<2>(back) == '*') {
					back_calc = get<0>(back) * get<1>(back);
				}
				else {
					back_calc = get<0>(back) / get<1>(back);
				}
				buho.pop_back();
				numbers.pop_back();
				numbers.pop_back();
				numbers.push_back(back_calc);
			}
			else {
				if (get<2>(front) == '+') {
					front_calc = get<0>(front) + get<1>(front);
				}
				else {
					front_calc = get<0>(front) - get<1>(front);
				}
				if (get<2>(back) == '+') {
					back_calc = get<0>(back) + get<1>(back);
				}
				else {
					back_calc = get<0>(back) - get<1>(back);
				}
				if (front_calc >= back_calc) {
					buho.pop_front();
					numbers.pop_front();
					numbers.pop_front();
					numbers.push_front(front_calc);
				}
				else {
					buho.pop_back();
					numbers.pop_back();
					numbers.pop_back();
					numbers.push_back(back_calc);
				}
			}
		}
	}
	cout << numbers[0] << endl;
	return 0;
}
