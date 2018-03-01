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
	int dp[1003];
	int a[5] = {0, 100, 50, 20, 10};
	memset(dp, 0, sizeof(dp));
	dp[0] = 1;
	if(n == 0) cout << 0 << endl;
	else {
		for(int i=1;i<=4;i++){
			for(int j=a[i]; j<=n; j++){
				dp[j] += dp[j-a[i]];
			}
		}
		cout << dp[n] << endl;
	}
	return 0;
}