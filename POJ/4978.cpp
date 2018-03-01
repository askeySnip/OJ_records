#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

int main() {
	int n, m, k;
	cin >> n >> m >> k;
	int c1[103], c2[103];
	for(int i=1; i<=k; i++){
		cin >> c1[i] >> c2[i];
	}
	int dp[1003][503];
	memset(dp, 0, sizeof(dp));
	for(int i=1; i<=k; i++){
		for(int j=n; j>=c1[i]; j--){
			for(int l = m; l>=c2[i]; l--){
				dp[j][l] = max(dp[j][l], dp[j-c1[i]][l-c2[i]] + 1);
			}
		}
	}
	cout << dp[n][m] << " ";
	for(int i=0; i<=m; i++){
		if(dp[n][i] == dp[n][m]){
			cout << m-i << endl;
			break;
		}
	}
	return 0;
}