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
	int a[1005];
	for(int i=0; i<n; i++){
		cin >> a[i];
	}
	int dp[10000+5];	// dp[i]表示以i结尾的最长子串长度
	memset(dp, 0, sizeof(dp));
	dp[a[0]] = 1;
	int ans = 1;
	for(int i=1; i<n; i++){
		int m = 0;
		for(int j=0; j<i; j++){
			if(a[j] < a[i] && m < dp[a[j]]) m = dp[a[j]];
		}
		dp[a[i]] = m+1;
//		cout << dp[a[i]] << " ";
		if(dp[a[i]] > ans) ans = dp[a[i]];
	}
	cout << ans << endl;
	return 0;
}