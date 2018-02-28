#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;
int main() {
	int n, t;
	cin >> n >> t;
	int a[23];
	for(int i=1; i<=n; i++){
		cin >> a[i];
	}
	int dp[23][1003];
	memset(dp, 0, sizeof(dp));
	dp[0][0] = 1;
	for(int i=0; i<23; i++) dp[i][0] = 1;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=t; j++){
			if(j < a[i]) dp[i][j] = dp[i-1][j];
			else dp[i][j] = dp[i-1][j-a[i]] + dp[i-1][j];
//			cout << dp[i][j] << " ";
		}
//		cout << endl;
	}
	cout << dp[n][t] << endl;
}