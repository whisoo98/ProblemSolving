#include <stdio.h>
int sum;
int sys(int a,const int mod)
{
	while ( a )
	{
		sum = sum + a % mod;
		a = a / mod;
	}
	return sum;
}

int main()
{
	int ten;
	int twv;
	int stn;
	for ( int i = 1000; i < 10000; i++ )
	{
		sum = 0;
		stn = sys(i, 16);		
		sum = 0;
		twv = sys(i, 12);
		sum = 0;
		ten = sys(i, 10);
		if ( stn == twv && stn == ten )printf("%d\n", i);



	}

	return 0;
}