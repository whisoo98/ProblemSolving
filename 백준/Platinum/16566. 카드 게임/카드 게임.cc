#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
#include<tuple>
#include<queue>
#include<string>

#define N 100'005
#define endl '\n';
#define ALPHABET "abcdefghijklmopqrstuvwxyz"
//#define int long long
using namespace std;

vector<int> cards;
vector<int> visit;
vector<int> opponent;


void putCard(int n, int m, int k) {
	sort(cards.begin(), cards.end());
	for (int i = 0; i < k; i++) {
		int idx = upper_bound(cards.begin(), cards.end(), opponent[i]) - cards.begin();
		for (int j = idx; j < m; j++) {
			if (visit[j] == 0) {
				visit[j] = 1;
				cout << cards[j] << endl;
				break;
			}
		}
	}
}

void Solution(int n,int m, int k) {
	putCard(n, m, k);
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m, k; cin >> n >> m >> k;
	for (int i = 0; i < m; i++) {
		int a; cin >> a;
		cards.push_back(a);
		visit.push_back(0);
	}
	for (int i = 0; i < k; i++) {
		int a; cin >> a;
		opponent.push_back(a);
	}
	
	Solution(n, m, k);
	return 0;
}
