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
	int a[1003];
	for(int i=1; i<=n; i++) cin >> a[i];
	int dp[1003];
	memset(dp, 0, sizeof(dp));
	dp[1] = a[1];
	int ans = 0;
	for(int i=1; i<=n; i++){
		int tmax = 0;
		for(int j=1; j<=i; j++){
			if(a[j] < a[i] && dp[j] > tmax){
				tmax = dp[j];
			}
		}
		dp[i] = tmax + a[i];
		if(dp[i] > ans) ans = dp[i];
	}
	cout << ans << endl;
	return 0;
}