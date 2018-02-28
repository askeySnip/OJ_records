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
	int dp[23];
	memset(dp, 0, sizeof(dp));
	dp[1] = 1;
	dp[2] = 2;
	for(int i=3; i<=n; i++){
		dp[i] = dp[i-1] + dp[i-2];
	}
	cout << dp[n] << endl;
	return 0;
}