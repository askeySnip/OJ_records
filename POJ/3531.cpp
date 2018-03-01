#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;
int main() {
	int n, k;
	cin >> n >> k;
	int a[10003];
	for(int i=1; i<=n; i++){
		cin >> a[i];
		a[i] = a[i] % k;
	}
	int dp[10003][103];
	memset(dp, 0, sizeof(dp));
	dp[1][(a[1]%k+k)%k]=1;
	dp[1][(-a[1]%k+k)%k]=1;
	for(int i=2;i<=n;i++){
		for(int j=0;j<k;j++){
			if(dp[i-1][j]==1){
				dp[i][((j+a[i])%k+k)%k]=1;
				dp[i][((j-a[i])%k+k)%k]=1;
			}
		}
	} 
	if(dp[n][0]==1)cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
	return 0;
}