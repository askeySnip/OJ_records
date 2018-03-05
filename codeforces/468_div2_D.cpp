#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;
int d[100003];
vector<int> tr[100003];
void dfs(int x, int dp){
	d[dp]++;
	for(int u : tr[x]){
		dfs(u, dp+1);
	}
}
int main() {
	int n;
	scanf("%d", &n);
	for(int i=1; i<n; i++){
		int x;
		scanf("%d", &x);
		x--;
		tr[x].push_back(i);
	}
	dfs(0, 0);
	int ans = 0;
	for(int i=0; i<n+1; i++)  ans += d[i]&1;
	cout << ans << endl;
	return 0;
}