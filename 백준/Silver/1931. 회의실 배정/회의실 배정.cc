#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <utility>

using namespace std;

void Solution(vector<pair<int,int>>& v, int n){
	sort(v.begin(),v.begin()+n);

	int cnt=0;
	int last=-1;
	for(int i=0;i<n;i++){
		if(v[i].second>=last){
			cnt++;
			last = v[i].first;
		}
	}
	printf("%d\n",cnt);
}
int main() {
	// your code goes here
	int n;
	vector<pair<int,int>> v(100'005);
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		v[i]={b,a};
	}
	Solution(v,n);
	return 0;
}