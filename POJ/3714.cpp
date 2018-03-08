#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <set>
#include <map>

using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int c, n;
	int dp[1003];
	while(cin >> c >> n){
		memset(dp, 0, sizeof(dp));
		for(int i=0; i<n; i++){
			int a, b;
			cin >> a >> b;
			for(int j=c; j>=0; j--){
				if(j >= a) dp[j] = max(dp[j], dp[j-a]+b);
			}
		}
		int mx = 0;
		for(int i=0; i<=c; i++){
			mx = max(mx, dp[i]);
		}
		cout << mx << endl;
	}
	return 0;
}