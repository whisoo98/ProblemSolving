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

using namespace std;

int N, M;
int rooms[1'000'005];
int find(int x)
{
	if(rooms[x]==x) return x;
    return rooms[x]=find(rooms[x]);
}

void unite(int x, int y)
{
    int X = find(x);
    int Y = find(y);
	if (X != Y)
	{
		rooms[Y] = X;
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i <= N+2; i++)
	{
		rooms[i] = i;
	}
    
    for(int j=1;j<=M;j++)
	{
		int x, y;
		cin >> x >> y;
		//merge(x, y);
        int rootX = find(x);
	    int rootY = find(y);
        if(rootX == rootY) continue;
        for(int i = rootY; i>x;){
            int temp = find(i);
            unite(rootX,i);
            i = temp-1;
        }
	}
	int cnt = 0;
    for(int i =1;i<=N;i++){
        if(rooms[i]==i) cnt++;
    }
    cout<<cnt;
    return 0;
}

