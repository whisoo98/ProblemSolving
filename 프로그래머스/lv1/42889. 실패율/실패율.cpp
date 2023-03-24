#include <string>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

vector<int> solution(int N, vector<int> stages) {
	int gamer = stages.size();
	vector<int> stage(N + 5, 0);

	for (auto iter : stages) {
		stage[iter]++;
	}
	vector<pair<double,int>> suc;
	
	for (int i = 1; i <= N; i++) {
		suc.push_back({ (((double)(gamer-stage[i]) / gamer)) * 1000,i });
		gamer -= stage[i];
	}
	sort(suc.begin(), suc.end());
	vector<int>ans;
	for (auto iter : suc) {
		ans.push_back(iter.second);
	}
	return ans;
}