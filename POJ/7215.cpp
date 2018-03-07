#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;
int main() {
	int n;
	int dp[53][53];
	memset(dp, 0, sizeof(dp));
	for(int i=1; i<53; i++) dp[1][i] = dp[0][i] = dp[i][1] = 1;
	for(int i=2; i<53; i++){
		for(int j=2; j<53; j++){
			if(i < j) dp[i][j] = dp[i][i];
			else dp[i][j] = dp[i][j-1] + dp[i-j][j];
		}
	}
	while(cin >> n){
		cout << dp[n][n] << endl;
	}
	return 0;
}