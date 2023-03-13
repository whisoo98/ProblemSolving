#include <stdio.h>
#include<algorithm>
#include<functional>
#include<vector>
using namespace std;
struct pos 
{
	int posx;
	int posy;

}temp;
vector<pos> vec;
bool cmp(pos a, pos b)
{
	if ( a.posy == b.posy ) return a.posx < b.posx;
	else return a.posy < b.posy;
}
int main()
{
	int n;
	int i, j;
	scanf("%d", &n);
	for ( i = 1; i <= n; i++ )
	{
		scanf("%d %d", &temp.posx, &temp.posy);
		vec.push_back(temp);
	}
	sort(vec.begin(), vec.end(), cmp);
	for ( i = 0; i < n; i++ )
	{
		printf("%d %d\n", vec[i].posx,vec[i].posy);
	}

	return 0;
}