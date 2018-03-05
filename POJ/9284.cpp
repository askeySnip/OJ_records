#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
typedef long long LL;

LL C(LL x,LL y)
{
		if (x>y/2) x=y-x;
		LL s=1;
		for (int i=x;i>=1;i--)
			s*=(y-i+1);
		for (int i=x;i>=1;i--)
			s/=i;
		return s;
}
int main()
{
		LL n,x,y;
		scanf("%lld%lld%lld",&n,&x,&y);
		printf("%lld\n",C(n,n+x)*C(n,n+y));
		return 0;
}