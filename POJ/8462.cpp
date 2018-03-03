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
	while(t--){
		int n;
		cin >> n;
		int dp[100003][2];
		cin >> dp[1][1];
		dp[1][0] = 0;
		int t;
		for(int i=2; i<=n; i++){
			cin >> t;
			dp[i][0] = max(dp[i-1][0], dp[i-1][1]);
			dp[i][1] = dp[i-1][0] + t;
		}
		cout << max(dp[n][0], dp[n][1]) << endl;
	}
	return 0;
}