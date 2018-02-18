#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;
typedef long long ll;

const int MAXM = 10005;
const int MAXN = 1005;

ll dp[MAXN][MAXM];
ll c[MAXN];
ll cost[MAXN];
int main() {
	ll m = 0;
	ll n, w, b, x;
	cin >> n >> w >> b >> x;
	for(int i=1; i<=n; i++){
		cin >> c[i];
		m += c[i];
	}
	for(int i=1; i<=n; i++){
		cin >> cost[i];
	}
	for(int i=0; i<MAXN; i++){
		for(int j=0; j<MAXM; j++){
			dp[i][j] = -1;
		}
	}
	dp[0][0] = w;
	int ans = 0;
	for(int i=1; i<=n; i++){
		for(int j=0; j<=m; j++){
			ll max_mana = w + j * b;
			for(int k=0; k<=min((ll)j, c[i]); k++){
				if(dp[i-1][j-k] == -1){
					continue;
				}
				ll new_mana = min(w + (j - k) * b, dp[i-1][j-k] + x) - cost[i] * k;
				if(new_mana < 0){
					continue;
				}
				dp[i][j] = max(dp[i][j], min(max_mana, new_mana));
				ans = max(ans, j);
				max_mana += b;
			}
		}
	}
	cout << ans << endl;
	return 0;
}