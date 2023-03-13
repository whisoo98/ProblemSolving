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
#define N 50
#define ll long long
#define endl "\n"
#define MID(a,b) (a+b)/2

using namespace std;

int dp[N];
ll fibo[N];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    
    int n; cin>>n;
    fibo[1]=1;
    fibo[2]=1;
    for(int i =3;i<=n;i++){
        fibo[i]=fibo[i-1]+fibo[i-2];
    }
    cout<<fibo[n]<<' '<<n-2<<endl;
	return 0;
}