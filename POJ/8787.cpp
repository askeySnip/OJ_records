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
	int dp[203][9];
	memset(dp, 0, sizeof(dp));
	for(int i=1; i<=n; i++){
		for(int j=1; j<=k; j++){
			if(i==j){
				dp[i][j] = 1;
				break;
			}else{
				dp[i][j] = dp[i-j][j] + dp[i-1][j-1];
			}
		}
	}
	cout << dp[n][k] << endl;
	return 0;
}