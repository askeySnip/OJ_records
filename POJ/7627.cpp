#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;
int main() {
	int n, m;
	int dp[103][103];
	while(cin >> n >> m){
		memset(dp, 0, sizeof(dp));
		for(int i=1; i<=n; i++){
			for(int j=1; j<=m; j++){
				dp[i][j] = i;
			}
		}
		for(int i=1; i<=n; i++){
			for(int j=2; j<i; j++){
				for(int k=2; k<=m; k++){
					dp[i][k] = min(dp[i][k], max(dp[j-1][k-1], dp[i-j][k]) + 1);
				}
			}
		}
		cout << dp[n][m] << endl;
	}
}