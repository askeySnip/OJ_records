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
	long long dp[53];
	dp[0] = 1;
	dp[1] = 2;
	for(int i=2; i<=n; i++) dp[i] = dp[i-1] + dp[i-2];
	cout << dp[n] << endl;
}