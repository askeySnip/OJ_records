#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

int main() {
	int t;
	cin >> t; 
	while (t--) {
		int m,n;
		cin >> m >> n;
		int dp[23][23];
		memset(dp, 0, sizeof(dp));
		for(int i=1; i<=m; i++) dp[i][1] = 1;
		for(int i=1; i<=n; i++) dp[0][i] = 1;
		for(int i=1; i<=m; i++){
			for(int j=1; j<=n; j++){
				if(i<j) dp[i][j] = dp[i][i];
				else dp[i][j] = dp[i-j][j] + dp[i][j-1];
			}
		}
		cout << dp[m][n] << endl;
	}
	return 0;
}