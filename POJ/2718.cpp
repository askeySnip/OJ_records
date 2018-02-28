#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;
int dp[23][23];
int find(int m, int n){
	if(min(m, n) == 1){
		return 1;
	}
	if(dp[m][n]) return dp[m][n];
	else {
		dp[m-1][n] = find(m-1, n);
		dp[m][n-1] = find(m, n-1);
		return dp[m-1][n] + dp[m][n-1];
	}
}
int main() {
	int m, n;
	cin >> m >> n;
	if(min(m, n) == 1) cout << "1" << endl;
	else{
		memset(dp, 0, sizeof(dp));
		cout << find(m, n) << endl;
	}
	return 0;
}