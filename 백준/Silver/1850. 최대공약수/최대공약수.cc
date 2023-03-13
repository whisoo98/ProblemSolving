#include <stdio.h>

long long gcd(long long a, long long b)
{
	if ( a%b == 0 ) return b;
	return gcd(b, a%b);
}
int main()
{
	long long a, b;
	scanf("%lld %lld", &a, &b);
	for ( long long cnt = gcd(a, b); cnt > 0; cnt-- ) printf("1");
	
	return 0;
}