#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <algorithm>
#include <climits>
#include <cmath>
#include <cstring>

using namespace std;

string pw;
int dp[50001];

bool is_alpha(int first, int second) {

    if(second > (int)pw.size() - 1) {
        return false;
    }

    if(pw[first] - '0' == 0) {
        return false;
    }

    int num = (pw[first] - '0') * 10 + (pw[second] - '0');

    return num <= 26;
}

int get_count(int s, int e) {
    if(s > e) {
        return 1;
    }

    if(dp[s] != -1) {
        return dp[s];
    }

    int temp1 = 0;
    int temp2 = 0;

    if(pw[s] - '0' != 0) {
        temp1 = get_count(s+1, e) % 1000000; 
    }
    if(is_alpha(s, s+1)) {
        temp2 = get_count(s+2, e) % 1000000;
    }

    dp[s] = ((temp1 % 1000000) + (temp2 % 1000000))%1000000;
    return dp[s];
}


int main() {
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> pw;
    int pw_size = (int)pw.size();

    memset(dp, -1, sizeof(int) * 50001);
    cout << get_count(0, pw_size - 1) << "\n";

    return 0;
}