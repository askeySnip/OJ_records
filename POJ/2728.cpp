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
		int r, c;
		cin >> r >> c;
		int dp[103][103];
		memset(dp, 0, sizeof(dp));
		for(int i=1; i<=r; i++){
			for(int j=1; j<=c; j++){
				cin >> dp[i][j];
			}
		}
//		memset(dp, 0, sizeof(dp));
		for(int i=1; i<=r; i++){
			for(int j=1; j<=c; j++){
				dp[i][j] = dp[i][j] + max(dp[i-1][j], dp[i][j-1]);
//				cout << i << " " << j << " " << dp[i][j] << endl;
			}
		}
		cout << dp[r][c] << endl;
		
	}
	return 0;
}