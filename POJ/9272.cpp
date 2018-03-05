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
	long long dp[1003][2];
	dp[1][0] = 8;
	dp[1][1] = 1;
	for(int i=2; i<=n; i++){
		dp[i][0] = (dp[i-1][0]*9+dp[i-1][1])%12345;
		dp[i][1] = (dp[i-1][1]*9+dp[i-1][0])%12345;
	}
	cout << dp[n][0] << endl;
	return 0;
}