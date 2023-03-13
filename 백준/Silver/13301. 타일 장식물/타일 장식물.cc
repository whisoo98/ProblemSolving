#include <iostream>
#define ll long long
#define N 85
using namespace std;


void Solution(ll arr[N], int n){
	ll dp[N];
	for(int i=0;i<N;i++){
		dp[i]=0;
	}
	dp[1]=1;
	for(int i =2;i<=n;i++){
		dp[i]=dp[i-1]+dp[i-2];
	}
	printf("%lld",dp[n]*4+dp[n-1]*2);
}


ll arr[N];

int main() {
	// your code goes here
	int n; scanf("%d",&n);

	Solution(arr,n);
	return 0;
}