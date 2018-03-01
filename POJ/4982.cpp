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
	int dp[23][2];
	memset(dp, 0, sizeof(dp));
	dp[1][0] = 1;
	dp[1][1] = 1;
	for(int i=2; i<=n; i++){
		dp[i][0] = dp[i-1][0] + dp[i-1][1] * 2;
		dp[i][1] = dp[i-1][1] + dp[i-1][0];
	}
	cout << dp[n][0] + dp[n][1] * 2 << endl;
	return 0;
}