#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
#define N 310
#define M 110
#define mod 9901

int f[M][N],sum[M][N];
int main()
{
		int n,m;
		scanf("%d%d",&n,&m);
		f[1][1]=sum[1][1]=1;
		for (int j=2;j<=n;j++)
			f[1][j]=sum[1][j]=0;
		for (int i=2;i<=m;i++)
		{
			for (int j=1;j<=n;j++)
			{
				f[i][j]=0;
				for (int k=1;k<j;k++)
					f[i][j]=(f[i][j]+(2*f[i-1][k]*sum[i-1][j-k-1]-f[i-1][k]*f[i-1][j-k-1])%mod)%mod;
				sum[i][j]=(sum[i-1][j]+f[i][j])%mod;
			}
		}
		printf("%d\n",f[m][n]);
		return 0;
}