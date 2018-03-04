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
	int m[13][13];
	memset(m, 0, sizeof(m));
	int a, b, c;
	while (cin >> a >> b >> c) {
		if(a+b+c == 0) break;
		m[a][b] = c;
	}
	int dp[13][13][13];
	memset(dp, 0, sizeof(dp));
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			for(int k=1; k<=n; k++){
				if(i + j >= k + 1 && i + j <= k + n){
					int t = max(dp[i][j-1][k-1], dp[i][j-1][k]) + (k == i? m[i][j] : m[i][j] + m[k][i+j-k]);
					if(t > dp[i][j][k]) dp[i][j][k] = t;
					t = max(dp[i-1][j][k-1], dp[i-1][j][k]) + (k == i? m[i][j] : m[i][j] + m[k][i+j-k]);
					if(t > dp[i][j][k]) dp[i][j][k] = t;
				}
			}
		}
	}
	cout << dp[n][n][n] << endl;
	return 0;
}