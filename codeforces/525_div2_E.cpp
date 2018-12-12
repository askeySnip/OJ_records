/*
ID: leezhen
TASK: practice
LANG: C++11                
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <cmath>
#include <bitset>
#include <list>

using namespace std;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<pair<int, int> > vii;
typedef long long ll;
const int inf = 1e9;
const int mod = 1e9+7;

int n;
int a[300005];
vi edge[300005];
ll dp[300005];
ll ans, k;

void dfs(int u, int p, bool f) {
	dp[u] = (ll)a[u];
	for(int i=0; i<(int)edge[u].size(); i++) {
		int v = edge[u][i];
		if(v != p) {
			dfs(v, u, f);
			dp[u] += max(dp[v], 0LL);
		}
	}
	if(f) {
		ans = max(ans, dp[u]);
	}else if(dp[u] == ans) {
		k++;
		dp[u] = 0;
	}
}

int main() {
	ans = -inf, k = 0;
	scanf("%d", &n);
	for(int i=1; i<=n; i++) {
		scanf("%d", &a[i]);
	}
	int f, t;
	for(int i=0; i<n-1; i++) {
		scanf("%d %d", &f, &t);
		edge[f].push_back(t);
		edge[t].push_back(f);
	}
	dfs(1, 0, 1);
	dfs(1, 0, 0);
	printf("%lld %lld\n", ans*k, k);
	return 0;
}