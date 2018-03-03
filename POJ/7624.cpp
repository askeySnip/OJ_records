#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;
int main() {
	int m, n;
	cin >> m >> n;
	int pos[503];
	pos[1] = 0;
	for(int i=2; i<=m; i++){
		int d;
		cin >> d;
		pos[i] = pos[i-1] + d;
//		cout << pos[i] << endl;
	}
	int mi[503][503], dp[503][503];
	memset(mi, 0, sizeof(mi));
	for(int i=1; i<=m; i++){
		for(int j=1; j<=n; j++){
			dp[i][j] = 99999999;
		}
	}
	for(int i=1; i<=m; i++){
		for(int j=i+1; j<=m; j++){
			mi[i][j] = mi[i][j-1] + pos[j] - pos[(i+j)/2];
//			mi[i][j] << endl;
		}
		dp[i][1] = mi[1][i];
	}
	for(int i=2; i<=m; i++){
		for(int j=2; j<=n; j++){
			for(int k=j-1; k<i; k++){
				dp[i][j] = min(dp[i][j], dp[k][j-1] + mi[k+1][i]);
//				cout << dp[i][j] << endl;
			}
		}
	}
	cout << dp[m][n] << endl;
	return 0;
}