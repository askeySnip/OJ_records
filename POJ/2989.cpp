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
	int sum = 0;
	int a[103];
	for(int i=1; i<=n; i++) cin >> a[i], sum+=a[i];
	if(sum % k == 0) cout << sum << endl;
	else{
		int dp[103][103];
		memset(dp, 0, sizeof(dp));
		for(int i=1; i<=n; i++){
			for(int j=0; j<k; j++) dp[i][j] = dp[i-1][j];
			for(int j=0; j<k; j++){
				if(dp[i-1][j] + a[i] > dp[i][(dp[i-1][j]+a[i])%k])
					dp[i][(dp[i-1][j]+a[i])%k] = dp[i-1][j] + a[i];
			}
		}
		cout << dp[n][0] << endl;
	} 
	return 0;
}