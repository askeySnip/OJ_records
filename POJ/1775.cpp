#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;
int main() {
	int tm, m;
	cin >> tm >> m;
	int dp[103][1003];
	memset(dp, 0, sizeof(dp));
	int t[103], v[103];
	for(int i=1; i<=m; i++){
		cin >> t[i] >> v[i];
	}
	for(int i=1; i<=m; i++){
		for(int j=1;j<=tm; j++){
			if(j >= t[i])
				dp[i][j] = max(dp[i-1][j], dp[i-1][j-t[i]] + v[i]);
			else 
				dp[i][j] = dp[i-1][j];
		}
	}
	cout << dp[m][tm] << endl;
	return 0;
}