#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;
const int Tmax=5842,pri[5]={0,2,3,5,7};
int n,p[5];
long long int f[Tmax+5];
void init()
{
		int i,j;
		p[1]=p[2]=p[3]=p[4]=1;
		memset(f,0x3f,sizeof(f));
		f[1]=1;
		for(i=2;i<=Tmax;i++)
		{
				for(j=1;j<=4;j++)
					f[i]=min(f[i],f[p[j]]*pri[j]);
				for(j=1;j<=4;j++)
					if(f[i]==f[p[j]]*pri[j]) p[j]++;
		}
		return;
}
int main() {
	init();
	int n;
	while(scanf("%d", &n)){
		if(!n) break;
		if(n%10 == 1 && (n%100<10 || n%100>20)) printf("The %dst humble number is %lld.\n", n, f[n]);
		else if(n%10 == 2 && (n%100<10 || n%100>20)) printf("The %dnd humble number is %lld.\n", n, f[n]);
		else if(n%10 == 3 && (n%100<10 || n%100>20)) printf("The %drd humble number is %lld.\n", n, f[n]);
		else printf("The %dth humble number is %lld.\n", n, f[n]);
	}
	return 0;
}