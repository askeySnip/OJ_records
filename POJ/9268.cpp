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
	int a[703];
	for(int i=1; i<=n; i++) cin >> a[i];
	if(n == 1) cout  << a[1] << endl;
	else if(n == 2) cout << a[1] + a[2] << endl;
	else{
		int dp[3][703];
		dp[0][2] = 0;
		dp[1][2] = a[2];
		dp[2][2] = a[1]+a[2];
		for(int i=3; i<=n+1; i++){
			dp[0][i] = max(max(dp[0][i-1], dp[1][i-1]), dp[2][i-1]);
			dp[1][i] = dp[0][i-1] + a[i];
			dp[2][i] = dp[1][i-1] + a[i];
		}
		cout << dp[0][n+1] << endl;
	}
	return 0;
}