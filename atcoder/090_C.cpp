#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;
int main() {
	int n;
	cin >> n;
	int dp[3][103];
	memset(dp, 0, sizeof(dp));
	int a[3][103];
	for(int i=1; i<3; i++){
		for(int j=1; j<=n; j++){
			cin >> a[i][j];
		}
	}
	for(int j=1; j<=n; j++){
		dp[1][j] = dp[1][j-1] + a[1][j];
	}
	dp[2][1] = dp[1][1] + a[2][1];
	for(int j=2; j<=n; j++){
		dp[2][j] = max(dp[1][j], dp[2][j-1]) + a[2][j];
	}
	cout << dp[2][n] << endl;
	return 0;
}