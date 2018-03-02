#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;
int t,n,m,a[101][101],k,i,j;
int main(){
	cin>>n;
	memset(a,0,sizeof(a));
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++){
			cin>>k;
			if(i==1) a[i][j]=k+a[i][j-1];
			else if(j==1)
				a[i][j]=k+a[i-1][j];
			else
				a[i][j]=k+min(a[i-1][j],a[i][j-1]);
		}
	cout<<a[n][n]<<endl;
	return 0;
}