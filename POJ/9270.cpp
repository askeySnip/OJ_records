#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;
int main() {
	int n;
	int dp[1000013];
	cin >> n;
	dp[1] = 2;
	dp[2] = 4;
	dp[3] = 6;
	dp[4] = 9;
	for(int i=5; i<=n; i++){
		dp[i] = (dp[i-1]%2005+dp[i-3]%2005+dp[i-4]%2005)%2005;
	}
	cout << dp[n] << endl;
	return 0;
}